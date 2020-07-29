#![no_std]
#![no_builtins]
#![allow(dead_code, unused_imports)]

#[cfg(test)]
#[macro_use]
extern crate hex_literal;

mod bolos;

extern crate core;

fn debug(_msg: &str) {}

use core::convert::TryInto;
use core::mem;
#[cfg(not(test))]
use core::panic::PanicInfo;
use sha2::{Digest, Sha256, Sha512Trunc256};

#[cfg(not(test))]
#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

#[no_mangle]
pub extern "C" fn rs_sha512_256(
    input_ptr: *const u8,
    input_size: usize,
    output_ptr: *const u8,
    output_size: usize,
) -> i8 {
    if output_size != 32 {
        return -1;
    }

    let input = unsafe { core::slice::from_raw_parts(input_ptr, input_size as usize) };
    let output = unsafe { mem::transmute::<*const u8, &mut [u8; 32]>(output_ptr) };

    let mut hasher = Sha512Trunc256::new();
    hasher.input(input);
    let result = hasher.result();

    output.copy_from_slice(&result);
    return 0;
}

#[cfg(test)]
mod tests {

    use crate::*;
    use sha2::Sha512Trunc256;

    #[test]
    fn sha512_256_pure() {
        let mut hasher = Sha512Trunc256::new();
        hasher.input(b"Zondax");
        let result = hasher.result();

        assert_eq!(
            result[..],
            hex!("3d119a287af12a4a1f263803f18a674f200d86e07954286dfe33cad245fe1be9")[..]
        );
    }

    #[test]
    fn sha512_256_c() {
        let data = b"Zondax";
        let result = [0u8; 32];

        rs_sha512_256(data.as_ptr(), data.len(), result.as_ptr(), result.len());

        assert_eq!(
            result[..],
            hex!("3d119a287af12a4a1f263803f18a674f200d86e07954286dfe33cad245fe1be9")[..]
        );
    }
}
