// @ts-ignore
import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";
// @ts-ignore
import ed25519 from "ed25519-supercop";
import {DeviceModel} from "@zondax/zemu";

const Resolve = require("path").resolve;

export const APP_SEED = "equip will roof matter pink blind book anxiety banner elbow sun young"

const APP_PATH_S = Resolve("../app/output/app_s.elf");
const APP_PATH_X = Resolve("../app/output/app_x.elf");

export const models: DeviceModel[] = [
    {name: 'nanos', prefix: 'S', path: APP_PATH_S},
    {name: 'nanox', prefix: 'X', path: APP_PATH_X}
]

export const TESTING_ALLOWLIST_SEED = "0000000000000000000000000000000000000000000000000000000000000000"

export function dummyAllowlist(nonce: number) {
    const addresses = [
        "16dGaSkriYA9aLfDZ3wzYExzD39ysdXrmFkE1F8r4oenXHxB",
        "14wbzhrtCQJ62YrAivvZby79H4MEne4M7HNdidWnLUC6rjPc",
    ]

    // Prepare len field
    const nonce_bytes = Buffer.alloc(4);
    const allowlist_len_bytes = Buffer.alloc(4);

    nonce_bytes.writeUInt32LE(nonce);
    allowlist_len_bytes.writeUInt32LE(addresses.length);

    // Prepare items field
    const addressBuffer = Buffer.alloc(64 * addresses.length, 0);
    for (let i = 0; i < addresses.length; i++) {
        const tmp = Buffer.from(addresses[i])
        tmp.copy(addressBuffer, i * 64)
    }

    // calculate digest
    const context = blake2bInit(32, null);
    blake2bUpdate(context, nonce_bytes);
    blake2bUpdate(context, allowlist_len_bytes);
    blake2bUpdate(context, addressBuffer);
    const digest = Buffer.from(blake2bFinal(context));
    console.log(`-------------------- ${digest.toString("hex")}`)

    // sign
    const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
    console.log(`PK : ${keypair.publicKey.toString("hex")}`)
    console.log(`SK : ${keypair.secretKey.toString("hex")}`)

    const allowlist_signature = ed25519.sign(digest, keypair.publicKey, keypair.secretKey)
    console.log(`SIG: ${allowlist_signature.toString("hex")}`)

    return Buffer.concat([
        nonce_bytes,
        allowlist_len_bytes,
        allowlist_signature,
        addressBuffer
    ])
}
