import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";
import ed25519 from "ed25519-supercop";

export const TESTING_ALLOWLIST_SEED = "0000000000000000000000000000000000000000000000000000000000000000"

export function dummyAllowlist(nonce) {
    const addresses = [
        "1XBtuFJiaYy4hcEvLPZ4Vqkz7E5WeoFyq7iBPewr7fpx3rv",
        "12b61iH1KaXijeRdAmm1b63RgDPeg9Nr6Soqm5w7tgPfqPfy",
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
