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

import Zemu, {DEFAULT_START_OPTIONS} from "@zondax/zemu";
import {newPolkadotApp} from "@zondax/ledger-polkadot";

// @ts-ignore
import ed25519 from "ed25519-supercop";
import {APP_SEED, dummyAllowlist, TESTING_ALLOWLIST_SEED} from "./common";

const Resolve = require("path").resolve;
const APP_PATH = Resolve("../app/output/app_ledgeracio.elf");

const defaultOptions = {
    ...DEFAULT_START_OPTIONS,
    logging: true,
    custom: `-s "${APP_SEED}"`,
    X11: true,
    model: 'nanos'
};

jest.setTimeout(60000)

describe('Ledgeracio', function () {
    // eslint-disable-next-line jest/expect-expect
    test('can start and stop container', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start({...defaultOptions});
        } finally {
            await sim.close();
        }
    });

    test('get app version', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start({...defaultOptions});
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
            await sim.start({...defaultOptions});
            const app = newPolkadotApp(sim.getTransport());
            // @ts-ignore
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
            await sim.start({...defaultOptions});
            const app = newPolkadotApp(sim.getTransport());

            const pk = Buffer.from("1234000000000000000000000000000000000000000000000000000000000000", "hex")

            // @ts-ignore
            const req = app.setAllowlistPubKey(pk);
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.clickRight();
            await sim.clickRight();
            await sim.clickBoth();
            let resp = await req;
            // @ts-ignore
            expect(resp.return_code).toEqual(0x9000);
            // @ts-ignore
            expect(resp.error_message).toEqual("No errors");

            // Try setting again
            // @ts-ignore
            resp = await app.setAllowlistPubKey(pk);
            // @ts-ignore
            expect(resp.return_code).toEqual(0x6986);
            // @ts-ignore
            expect(resp.error_message).toEqual("Transaction rejected");

            // @ts-ignore
            resp = await app.getAllowlistPubKey();
            console.log(resp);
            // @ts-ignore
            expect(resp.return_code).toEqual(0x9000);
            // @ts-ignore
            expect(resp.error_message).toEqual("No errors");

            // @ts-ignore
            expect(resp.pubkey).toEqual(pk);

        } finally {
            await sim.close();
        }
    });

    test('get allowlist hash | not set yet', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start({...defaultOptions});
            const app = newPolkadotApp(sim.getTransport());
            // @ts-ignore
            const resp = await app.getAllowlistHash();

            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test('create signed allowlist', async function () {
        const allowList = dummyAllowlist(0)
        console.log(allowList)
        expect(allowList.length).toEqual(4 + 4 + 64 * 3)
    });

    test('upload allowlist | no pubkey', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start({...defaultOptions});
            const app = newPolkadotApp(sim.getTransport());

            console.log("\n\n------------ Upload allowlist")
            const allowlist = dummyAllowlist(0);
            // @ts-ignore
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
            await sim.start({...defaultOptions});
            const app = newPolkadotApp(sim.getTransport());

            console.log("\n\n------------ Set pubkey")
            const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
            // @ts-ignore
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
            // @ts-ignore
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
            // @ts-ignore
            resp = await app.getAllowlistHash();
            console.log(resp);
            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            console.log(`\n\n------------ Upload allowlist : Again`)
            // @ts-ignore
            resp = await app.uploadAllowlist(allowlist);
            console.log(resp);
            expect(resp.return_code).toEqual(0x6400);
            expect(resp.error_message).toEqual("Execution Error");

            console.log(`\n\n------------ Upload allowlist : Again but change nonce`)
            allowlist = dummyAllowlist(11);
            // @ts-ignore
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

            // Try to sign a nomination included in the allowlist
            const nominate_tx1 = "0705080090c8e14f2764111e777eec088e0dbf4147d28d49b9e98349f09607750b2a0c7400f461cf468c6d4348b4ee554eda68d1b5f2eb57ff348576b820032e89a2df1b6cd503046d0f1e0000000700000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";
            const txBlob1 = Buffer.from(nominate_tx1, "hex");
            const signatureResponse1 = app.sign(0x80000000, 0x80000000, 0x80000000, txBlob1);
            await Zemu.sleep(1000);
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.clickBoth();
            await sim.clickBoth();
            const signature1 = await signatureResponse1;
            expect(signature1.return_code).toEqual(0x9000);
            expect(signature1.error_message).toEqual("No errors");
            console.log(signature1)

            await Zemu.sleep(3000);
            console.log("Try an address that is not allowed")

            // Now try a nominations that is not allowed
            const nominate_tx2 = "07050400aadebcb17c61283953f08346bef03801b39e1043b0d7e810ca7ab54bb5456d6ad503ae1103000b63ce64c10c051e0000000700000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";
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
