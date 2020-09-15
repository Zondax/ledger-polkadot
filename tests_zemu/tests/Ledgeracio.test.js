/** ******************************************************************************
 *  (c) 2020 Zondax GmbH
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
 ******************************************************************************* */

import jest, {expect, test} from "jest";
import Zemu from "@zondax/zemu";
import {newPolkadotApp} from "@zondax/ledger-polkadot";
import ed25519 from "ed25519-supercop";
import {dummyAllowlist, TESTING_ALLOWLIST_SEED} from "./common";

const Resolve = require("path").resolve;
const APP_PATH = Resolve("../app/bin/app_ledgeracio.elf");

const APP_SEED = "equip will roof matter pink blind book anxiety banner elbow sun young"
const sim_options = {
    logging: true,
    start_delay: 3000,
    custom: `-s "${APP_SEED}"`
    , X11: true
};

jest.setTimeout(30000)

describe('Basic checks', function () {
    test('can start and stop container', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
        } finally {
            await sim.close();
        }
    });

    test('get app version', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolkadotApp(sim.getTransport());
            const resp = await app.getVersion();

            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");
            expect(resp).toHaveProperty("test_mode");
            expect(resp).toHaveProperty("major");
            expect(resp).toHaveProperty("minor");
            expect(resp).toHaveProperty("patch");
        } finally {
            await sim.close();
        }
    });

    test('get allowlist pubkey | unset', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolkadotApp(sim.getTransport());
            const resp = await app.getAllowlistPubKey();

            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test('set allowlist pubkey', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolkadotApp(sim.getTransport());

            const pk = Buffer.from("1234000000000000000000000000000000000000000000000000000000000000", "hex")

            let req = app.setAllowlistPubKey(pk);
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.clickRight();
            await sim.clickRight();
            await sim.clickBoth();
            let resp = await req;
            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            // Try setting again
            resp = await app.setAllowlistPubKey(pk);
            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");

            resp = await app.getAllowlistPubKey();
            console.log(resp);
            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            expect(resp.pubkey).toEqual(pk);

        } finally {
            await sim.close();
        }
    });

    test('get allowlist hash | not set yet', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolkadotApp(sim.getTransport());
            const resp = await app.getAllowlistHash();

            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test('create signed allowlist', async function () {
        const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
        const allowList = dummyAllowlist(0)

        console.log(allowList)
        expect(allowList.length).toEqual(4 + 4 + 64 * 3)
    });

    test('upload allowlist | no pubkey', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolkadotApp(sim.getTransport());

            console.log("\n\n------------ Upload allowlist")
            const allowlist = dummyAllowlist(0);
            const resp = await app.uploadAllowlist(allowlist);
            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test('upload allowlist | with pubkey set before', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolkadotApp(sim.getTransport());

            console.log("\n\n------------ Set pubkey")
            const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
            let req = app.setAllowlistPubKey(keypair.publicKey);
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.clickRight();
            await sim.clickRight();
            await sim.clickBoth();
            let resp = await req;
            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            let allowlist = dummyAllowlist(10);
            console.log(`\n\n------------ Upload allowlist : ${allowlist.length} bytes`)
            req = app.uploadAllowlist(allowlist);
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.clickRight();
            await sim.clickRight();
            await sim.clickBoth();
            resp = await req;
            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            console.log("\n\n------------ Get allowlist hash")
            resp = await app.getAllowlistHash();
            console.log(resp);
            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            console.log(`\n\n------------ Upload allowlist : Again`)
            resp = await app.uploadAllowlist(allowlist);
            console.log(resp);
            expect(resp.return_code).toEqual(0x6400);
            expect(resp.error_message).toEqual("Execution Error");

            console.log(`\n\n------------ Upload allowlist : Again but change nonce`)
            allowlist = dummyAllowlist(11);
            req = app.uploadAllowlist(allowlist);
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.clickRight();
            await sim.clickRight();
            await sim.clickBoth();
            resp = await req;
            console.log(resp);
            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            // Change to expert mode so we can skip fields
            await sim.clickRight();
            await sim.clickBoth();
            await sim.clickLeft();

            // Try to sign a nomination not included in the allowlist
            // This nomination targets 16dGaSkriYA9aLfDZ3wzYExzD39ysdXrmFkE1F8r4oenXHxB
            // This nomination targets 14wbzhrtCQJ62YrAivvZby79H4MEne4M7HNdidWnLUC6rjPc
            let nominate_tx1 = "070508f8d66ff9ce34aa58502eef2f1c605dc5cd272eda9d0018f920668cea2156d14fae59c16b6ce333628ef8cf81240a29b402665d60b55b1ea238dbaf20d3bd6803d503ae1103000b63ce64c10c05170000000500000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";
            const txBlob1 = Buffer.from(nominate_tx1, "hex");
            const signatureResponse1 = app.sign(0x80000000, 0x80000000, 0x80000000, txBlob1);
            await Zemu.sleep(1000);
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.clickBoth();
            await sim.clickBoth();
            let signature1 = await signatureResponse1;
            expect(signature1.return_code).toEqual(0x9000);
            expect(signature1.error_message).toEqual("No errors");
            console.log(signature1)

            await Zemu.sleep(3000);
            console.log("Try an address that is not allowed")

            // Now try a nominations that is not allowed
            // 13BP3Jpm3SboANHyfTwDp437t1atrUKjba8YonifCBbgyDG2
            const nominate_tx2 = "07050460631d0c1e64840fa3d6ecc4975ebd0d2012cec0a766f0ce2658d9b1aa6c1e03d5038d2400170000000500000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";
            const txBlob2 = Buffer.from(nominate_tx2, "hex");
            const signature2 = await app.sign(0x80000000, 0x80000000, 0x80000000, txBlob2);
            await Zemu.sleep(1000);
            await sim.clickBoth();
            await sim.clickBoth();
            expect(signature2.return_code).toEqual(0x6984);
            expect(signature2.error_message).toEqual("Not allowed");

        } finally {
            await sim.close();
        }
    });
});
