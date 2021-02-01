import Zemu from "@zondax/zemu";
import path from "path";
import LedgerPolkadot from "@zondax/ledger-polkadot";

const APP_PATH = path.resolve(`./../../app/output/app_X.elf`);
import pkg from 'blakejs';

const {blake2bInit, blake2bUpdate, blake2bFinal} = pkg;

import ed25519 from "ed25519-supercop";

const seed = "equip will roof matter pink blind book anxiety banner elbow sun young"
const SIM_OPTIONS = {
    logging: true,
    start_delay: 1000,
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

async function debugSchnorrkel(sim, app) {
    let input = 10;

    let response = await sim.getTransport()
        .send(0x99, 0xFF, 0, 0, Buffer.from([input]));

    console.log(response.toString("hex"));
}

async function debugX(sim, app) {
    console.log("Hey!");
}

async function main() {
    await beforeStart();

    if (process.argv.length > 2 && process.argv[2] === "debug") {
        SIM_OPTIONS["custom"] = SIM_OPTIONS["custom"] + " --debug";
    }

    SIM_OPTIONS["model"] = "nanox";

    const sim = new Zemu.default(APP_PATH);

    try {
        await sim.start(SIM_OPTIONS);
        const app = LedgerPolkadot.newPolkadotApp(sim.getTransport());

        ////////////
        /// TIP you can use zemu commands here to take the app to the point where you trigger a breakpoint

        await debugSchnorrkel(sim, app);

        /// TIP

    } finally {
        await sim.close();
        await beforeEnd();
    }
}

(async () => {
    await main();
})();
