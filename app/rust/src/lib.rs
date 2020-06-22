#![no_std]
#![no_builtins]

#![allow(dead_code, unused_imports)]

#[cfg(test)]
#[macro_use]
extern crate hex_literal;

extern crate core;

fn debug(_msg: &str) {}

#[cfg(not(test))]
use core::panic::PanicInfo;
use core::mem;
use core::convert::TryInto;
use sha2::{Sha256, Digest, Sha512Trunc256};

#[cfg(not(test))]
#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}
