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
//! Rust interfaces to Ledger SDK APIs.
#[cfg(test)]
use curve25519_dalek::constants::RISTRETTO_BASEPOINT_POINT;
use curve25519_dalek::scalar::Scalar;
#[cfg(test)]
#[cfg(target_arch = "x86_64")]
use getrandom::getrandom;
use merlin::TranscriptRng;
use rand::{CryptoRng, RngCore};

extern "C" {
    fn cx_rng(buffer: *mut u8, len: u32);
    fn zemu_log_stack(buffer: *const u8);
    fn check_app_canary();
}

#[cfg(not(test))]
pub fn c_zemu_log_stack(s: &[u8]) {
    unsafe { zemu_log_stack(s.as_ptr()) }
}

#[cfg(test)]
pub fn c_zemu_log_stack(s: &[u8]) {}

pub fn c_check_app_canary() {
    unsafe { check_app_canary() }
}

pub struct Trng;

impl RngCore for Trng {
    fn next_u32(&mut self) -> u32 {
        let mut out = [0; 4];
        self.fill_bytes(&mut out);
        u32::from_le_bytes(out)
    }

    fn next_u64(&mut self) -> u64 {
        let mut out = [0; 8];
        self.fill_bytes(&mut out);
        u64::from_le_bytes(out)
    }

    #[cfg(not(target_arch = "x86_64"))]
    fn fill_bytes(&mut self, dest: &mut [u8]) {
        c_zemu_log_stack(b"fill_bytes\x00".as_ref());

        unsafe {
            cx_rng(dest.as_mut_ptr(), dest.len() as u32);
        }
    }

    #[cfg(target_arch = "x86_64")]
    #[cfg(test)]
    fn fill_bytes(&mut self, dest: &mut [u8]) {
        getrandom(dest);
    }

    #[cfg(target_arch = "x86_64")]
    #[cfg(not(test))]
    fn fill_bytes(&mut self, _dest: &mut [u8]) {}

    fn try_fill_bytes(&mut self, dest: &mut [u8]) -> Result<(), rand::Error> {
        self.fill_bytes(dest);
        Ok(())
    }
}

impl CryptoRng for Trng {}
