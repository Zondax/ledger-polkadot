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
            // This nomination targets 1XBtuFJiaYy4hcEvLPZ4Vqkz7E5WeoFyq7iBPewr7fpx3rv
            // This nomination targets 12b61iH1KaXijeRdAmm1b63RgDPeg9Nr6Soqm5w7tgPfqPfy
            let nominate_tx1 = "070508170609956f7131390f4498fd84bb2096c997bbb9085ca41984428737e985c993463b7333950f0664d00a83d1eea4ef0915271323724bffdbf3fef6853bac18b6d503910100110000000300000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";
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
            // 13gR15tgGKZ6vkQonQmfLJBvQRVpkg1ypecS3zFJXoH9aCZr
            const nominate_tx2 = "0705047687d572183ed129145775debe04254558d5b3bde9928354a64d9b0e8538bfa1d5038d248ed73e0d110000000300000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";
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
