import Zemu from "@zondax/zemu";
import path from "path";
import LedgerPolkadot from "@zondax/ledger-polkadot";

const APP_PATH = path.resolve(`./../../app/bin/app.elf`);
import pkg from 'blakejs';

const {blake2bInit, blake2bUpdate, blake2bFinal} = pkg;

import ed25519 from "ed25519-supercop";

const seed = "equip will roof matter pink blind book anxiety banner elbow sun young"
const SIM_OPTIONS = {
    logging: true,
    start_delay: 4000,
    X11: true,
    custom: `-s "${seed}" --color LAGOON_BLUE`
};

async function beforeStart() {
    process.on("SIGINT", () => {
        Zemu.default.stopAllEmuContainers(function () {
            process.exit();
        });
    });
    await Zemu.default.checkAndPullImage();
}

async function beforeEnd() {
    await Zemu.default.stopAllEmuContainers();
}

const TESTING_ALLOWLIST_SEED = "0000000000000000000000000000000000000000000000000000000000000000"

function dummyAllowlist() {
    const addresses = [
        "HFfvSuhgKycuYVk5YnxdDTmpDnjWsnT76nks8fryfSLaD96",
        "FQr6vFmm8zNFV9m4ZMxKzMdUVUbPtrhxxaVkAybHxsDYMCY",
        "HXAjzUP15goNbAkujFgnNcioHhUGMDMSRdfbSxi11GsCBV6"
    ]

    // Prepare len field
    const allowlist_len = Buffer.alloc(4);
    allowlist_len.writeUInt32LE(addresses.length);

    // Prepare items field
    const addressBuffer = Buffer.alloc(64 * addresses.length, 0);
    for(let i=0; i<addresses.length; i++) {
        const tmp = Buffer.from( addresses[i] )
        tmp.copy(addressBuffer, i*64)
    }

    // calculate digest
    const context = blake2bInit(32, null);
    blake2bUpdate(context, allowlist_len);
    blake2bUpdate(context, addressBuffer);
    const digest = Buffer.from(blake2bFinal(context));
    console.log(`-------------------- ${digest.toString("hex")}`)

    // sign
    const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
    console.log(`PK : ${keypair.publicKey.toString("hex")}`)
    console.log(`SK : ${keypair.secretKey.toString("hex")}`)

    const allowlist_signature = ed25519.sign(digest, keypair.publicKey, keypair.secretKey)
    console.log(`SIG: ${allowlist_signature.toString("hex")}`)

    return Buffer.concat([allowlist_len, allowlist_signature, addressBuffer])
}

async function debugScenario(sim, app) {
    const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
    let resp = await app.setAllowlistPubKey(keypair.publicKey);
    console.log(resp)

    const allowlist = dummyAllowlist(0);
    console.log(`\n\n------------ Upload allowlist : ${allowlist.length} bytes`)
    resp = await app.uploadAllowlist(allowlist);
    console.log(resp);

    console.log("\n\n------------ Get allowlist hash")
    resp = await app.getAllowlistHash();
    console.log(resp.hash.toString("hex"));
}

async function debugScenario2(sim, app) {
    const pathAccount = 0x80000000;
    const pathChange = 0x80000000;
    const pathIndex = 0x80000000;

    let txBlobStr = "05005cd6daea110119e757f4af9ad9fc0cdc7d4d6380ca0009169c9b7b1c909c20248ed73e0dd503040b63ce64c10c05170000000500000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";
    const txBlob = Buffer.from(txBlobStr, "hex");

    const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
    const pubKey = Buffer.from(responseAddr.pubKey, "hex");

    // do not wait here.. we need to navigate
    const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
    // Wait until we are not in the main menu
    await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

    let signatureResponse = await signatureRequest;
    console.log(signatureResponse);
}

async function main() {
    await beforeStart();

    if (process.argv.length > 2 && process.argv[2] === "debug") {
        SIM_OPTIONS["custom"] = SIM_OPTIONS["custom"] + " --debug";
    }

    const sim = new Zemu.default(APP_PATH);

    try {
        await sim.start(SIM_OPTIONS);
        const app = LedgerPolkadot.newPolkadotApp(sim.getTransport());

        ////////////
        /// TIP you can use zemu commands here to take the app to the point where you trigger a breakpoint

        await debugScenario2(sim, app);

        /// TIP

    } finally {
        await sim.close();
        await beforeEnd();
    }
}

(async () => {
    await main();
})();
