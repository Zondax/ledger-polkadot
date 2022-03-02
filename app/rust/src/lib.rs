/*******************************************************************************
*   (c) 2020 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#![no_std]
#![no_builtins]
#![allow(dead_code, unused_imports)]

extern crate core;
#[cfg(test)]
#[macro_use]
extern crate hex_literal;

use core::convert::TryInto;
use core::mem;
use core::panic::PanicInfo;
use core::slice::{from_raw_parts, from_raw_parts_mut};

use curve25519_dalek::scalar::Scalar;
use merlin::{Transcript, TranscriptRng, TranscriptRngBuilder};
use rand::RngCore;
use schnorrkel::context::{SigningContext, SigningTranscript};
use schnorrkel::{PublicKey, SecretKey};
use zeroize::Zeroize;

use crate::bolos::*;

mod bolos;

fn debug(_msg: &str) {}

#[cfg(not(test))]
#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

#[inline(never)]
fn mult_with_secret(k: &mut Scalar, sk: &[u8]) {
    let mut skbytes = [0u8; 32];
    skbytes.copy_from_slice(&sk[0..32]);
    let s = Scalar::from_bits(skbytes);
    *k *= s;
}

#[inline(never)]
fn add_witness(k: &mut Scalar, x: [u8; 32]) -> [u8; 32] {
    let r = Scalar::from_bits(x);
    *k += r;
    k.to_bytes()
}

#[inline(never)]
fn get_challenge_scalar(k: &mut Scalar, tr: &mut Transcript) {
    let mut kbytes = [0u8; 64];
    tr.challenge_bytes(b"sign:c", &mut kbytes);
    *k += Scalar::from_bytes_mod_order_wide(&kbytes);
}

#[inline(never)]
fn get_witness_bytes_custom(br: &mut Transcript, nonce_seeds: &[&[u8]]) -> [u8; 32] {
    c_zemu_log_stack(b"witness_bytes\x00".as_ref());
    let mut x = [0u8; 32];
    for ns in nonce_seeds {
        br.append_message(b"nonce-bytes", ns);
    }
    {
        let random_bytes = {
            let mut bytes = [0u8; 32];
            Trng.fill_bytes(&mut bytes);
            bytes
        };
        br.append_message(b"rng", &random_bytes);
    }
    br.challenge_bytes(b"witness-bytes", &mut x);
    br.zeroize();
    x
}

#[no_mangle]
pub extern "C" fn sign_sr25519_phase1(
    sk_ristretto_expanded_ptr: *const u8,
    pk_ptr: *const u8,
    context_ptr: *const u8,
    context_len: usize,
    msg_ptr: *const u8,
    msg_len: usize,
    sig_ptr: *mut u8,
) {
    c_zemu_log_stack(b"sign_sr25519\x00".as_ref());

    let sk_ristretto_expanded =
        unsafe { from_raw_parts(sk_ristretto_expanded_ptr as *const u8, 64) };
    let pk = unsafe { from_raw_parts(pk_ptr as *const u8, 32) };
    let context = unsafe { from_raw_parts(context_ptr as *const u8, context_len) };
    let message = unsafe { from_raw_parts(msg_ptr as *const u8, msg_len) };
    let signature = unsafe { from_raw_parts_mut(sig_ptr as *mut u8, 64) };

    let mut signtranscript = Transcript::new(b"SigningContext");
    signtranscript.append_message(b"", context);
    signtranscript.append_message(b"sign-bytes", message);
    signtranscript.append_message(b"proto-name", b"Schnorr-sig"); //proto name
    signtranscript.append_message(b"sign:pk", pk); //commitpoint: pk

    let x = get_witness_bytes_custom(&mut signtranscript, &[&sk_ristretto_expanded[32..]]);
    signature[32..64].copy_from_slice(&x);
}

#[no_mangle]
pub extern "C" fn sign_sr25519_phase2(
    sk_ristretto_expanded_ptr: *const u8,
    pk_ptr: *const u8,
    context_ptr: *const u8,
    context_len: usize,
    msg_ptr: *const u8,
    msg_len: usize,
    sig_ptr: *mut u8,
) {
    c_zemu_log_stack(b"sign_sr25519\x00".as_ref());

    let sk_ristretto_expanded =
        unsafe { from_raw_parts(sk_ristretto_expanded_ptr as *const u8, 64) };
    let pk = unsafe { from_raw_parts(pk_ptr as *const u8, 32) };
    let context = unsafe { from_raw_parts(context_ptr as *const u8, context_len) };
    let message = unsafe { from_raw_parts(msg_ptr as *const u8, msg_len) };
    let signature = unsafe { from_raw_parts_mut(sig_ptr as *mut u8, 64) };

    let mut signtranscript = Transcript::new(b"SigningContext");
    signtranscript.append_message(b"", context);
    signtranscript.append_message(b"sign-bytes", message);
    signtranscript.append_message(b"proto-name", b"Schnorr-sig"); //proto name
    signtranscript.append_message(b"sign:pk", pk); //commitpoint: pk
    signtranscript.append_message(b"sign:R", &signature[0..32]); //commitpoint: pk

    let mut x = [0u8; 32];
    x.copy_from_slice(&signature[32..64]);

    let mut k = Scalar::zero();
    get_challenge_scalar(&mut k, &mut signtranscript);

    mult_with_secret(&mut k, sk_ristretto_expanded);
    signature[32..].copy_from_slice(&add_witness(&mut k, x));
    signature[63] |= 128;
}

#[no_mangle]
pub extern "C" fn get_sr25519_sk(sk_ed25519_expanded_ptr: *mut u8) {
    let sk_ed25519_expanded = unsafe { from_raw_parts_mut(sk_ed25519_expanded_ptr as *mut u8, 64) };
    let secret: SecretKey = SecretKey::from_ed25519_bytes(&sk_ed25519_expanded[..]).unwrap();
    sk_ed25519_expanded.copy_from_slice(&secret.to_bytes());
}

#[cfg(test)]
mod tests {
    use curve25519_dalek::constants::RISTRETTO_BASEPOINT_POINT;
    use curve25519_dalek::edwards::EdwardsPoint;
    use curve25519_dalek::scalar::Scalar;
    use log::{debug, info};
    use schnorrkel::{context::*, Keypair, PublicKey, SecretKey, Signature};

    use crate::*;
    use core::ops::Mul;

    fn init_logging() {
        let _ = env_logger::builder().is_test(true).try_init();
    }

    fn ristretto_scalarmult(sk: &[u8], pk: &mut [u8]) {
        let mut seckey = [0u8; 32];
        seckey.copy_from_slice(&sk[0..32]);
        let pubkey = RISTRETTO_BASEPOINT_POINT
            .mul(Scalar::from_bits(seckey))
            .compress()
            .0;
        pk.copy_from_slice(&pubkey);
    }

    #[test]
    fn test_sign_verify() {
        let mut sk_ed25519_expanded = [
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
            0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03,
            0x04, 0x05, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x00, 0x01,
            0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        ];

        let pk_expected = "b65abc66a8fdeac1197d03daa6c3791d0c0799a52db6b7127b1cd12d46e34364";

        let secret = SecretKey::from_ed25519_bytes(&sk_ed25519_expanded).unwrap();

        let mut pk = [0u8; 32];
        get_sr25519_sk(sk_ed25519_expanded.as_mut_ptr());

        ristretto_scalarmult(&sk_ed25519_expanded, &mut pk);

        assert_eq!(hex::encode(pk), pk_expected);

        let context = b"good";
        let msg = b"test message";
        let mut signature = [0u8; 64];

        sign_sr25519_phase1(
            secret.to_bytes().as_ptr(),
            pk.as_ptr(),
            context.as_ptr(),
            context.len(),
            msg.as_ptr(),
            msg.len(),
            signature.as_mut_ptr(),
        );

        let mut x = [0u8; 32];
        x.copy_from_slice(&signature[32..64]);

        ristretto_scalarmult(&x, &mut signature[0..32]);

        sign_sr25519_phase2(
            secret.to_bytes().as_ptr(),
            pk.as_ptr(),
            context.as_ptr(),
            context.len(),
            msg.as_ptr(),
            msg.len(),
            signature.as_mut_ptr(),
        );

        let keypair: Keypair = Keypair::from(secret);

        let mut sigledger = [0u8; 64];
        hex::decode_to_slice("48fdbe5cf3524bdd078ac711565d658a3053d10660749959883c4710f49d9948b2d5f829bea6800897dc6ea0150ca11075cc36b75bfcf3712aafb8e1bd10bf8f",&mut sigledger).expect("dec");

        let self_sig = Signature::from_bytes(&signature).unwrap();
        let self_sig_ledger = Signature::from_bytes(&sigledger).unwrap();

        let vers = signing_context(context);

        assert!(
            keypair.verify(vers.bytes(msg), &self_sig).is_ok(),
            "Verification of a valid signature failed!"
        );
        assert!(
            keypair.verify(vers.bytes(msg), &self_sig_ledger).is_ok(),
            "Verification of a valid signature from ledger failed!"
        );
    }

    #[test]
    fn get_public_key_c() {
        init_logging();

        let mut sk_ed25519_expanded = [
            0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06,
            0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5,
            0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04,
            0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03,
            04, 0x5, 0x06, 0x07,
        ];

        let pk_expected = "b65abc66a8fdeac1197d03daa6c3791d0c0799a52db6b7127b1cd12d46e34364";

        let mut pk = [0u8; 32];
        get_sr25519_sk(sk_ed25519_expanded.as_mut_ptr());

        ristretto_scalarmult(&sk_ed25519_expanded, &mut pk);

        info!("{:?}", hex::encode(pk));
        assert_eq!(hex::encode(pk), pk_expected);
    }
}
