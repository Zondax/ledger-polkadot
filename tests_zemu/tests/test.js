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

import jest, {expect} from "jest";
import Zemu from "@zondax/zemu";
const {newPolkadotApp} = require("@zondax/ledger-polkadot");

const ed25519 = require("ed25519-supercop");
import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";

const Resolve = require("path").resolve;
const APP_PATH = Resolve("../app/bin/app.elf");

const APP_SEED = "equip will roof matter pink blind book anxiety banner elbow sun young"
const sim_options = {
    logging: true,
    start_delay: 3000,
    custom: `-s "${APP_SEED}"`
    , X11: true
};

jest.setTimeout(60000)

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

    test('get address', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolkadotApp(sim.getTransport());

            const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000);

            console.log(resp)

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "166wVhuQsKFeb7bd1faydHgVvX1bZU2rUuY7FJmWApNz2fQY";
            const expected_pk = "e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);

        } finally {
            await sim.close();
        }
    });

    test('show address', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolkadotApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "show_address", 3);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "166wVhuQsKFeb7bd1faydHgVvX1bZU2rUuY7FJmWApNz2fQY";
            const expected_pk = "e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);
        } finally {
            await sim.close();
        }
    });

    test('sign basic', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolkadotApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0500a1b3d9e860a3d4f163414442c17a10df6a31f3ab017e2aa7fb9a0fe87ebff0ba0b63ce64c10c05d50391016d0f110000000300000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "sign_basic", 12);

            let signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x9000);
            expect(signatureResponse.error_message).toEqual("No errors");

            // Now verify the signature
            let prehash = txBlob;
            if (txBlob.length > 256) {
                const context = blake2bInit(32, null);
                blake2bUpdate(context, txBlob);
                prehash = Buffer.from(blake2bFinal(context));
            }
            const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey);
           expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test('sign large nomination', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolkadotApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "060540c17c9e6afb931ae7beb788511a328f969f3973a3463d346b3f37b78b7148a2de6eb61a6850ef4a72361507f73c5e11b9ac83526940296f4d5b76187a20bc38b54c11bc36f9ae08d274dd4dd6f01b0d3b1bc5bf6d348d9497dbfba1d848e496af59da2c352aaf3660d4cb3f6d1503aee4ce7d2cb6aa8640883ed2c72332d0015489e530a829632e84698d1b2029fd99d3d1ef1a74d85c5516bab91155dcbb64536683d375cdc516f8a0f49d04c669cf5f3a4dcd9626e35fd54bb01c554a612abb4ad3dc3ac25ddb3ad2227428519a51476b02de5d086f2594652c01a9968c45cd8ef40f1f310d26d880b5ff4d4640430a884fa36ec8c8f1e914c1c5a8ce152c46dbfcd84f7fce802c2ec814144be18e1985981fc85002e6c8e5d587b53149db381909be0274b84e846a5900ec972a11c204fb45b5efc0be284b48de2c6d82410592015cf9cef9a74d7179954e124c7d8131c6addb11cad60e73478db74bcfe7f22c8c584ef41a0f2ed937b976411ef9c576ca3c71098538f3110e33970f7a935d503d6288cb603e03dbbc398af9f0006463c5bc9cd4db5de3d68137da7a2f813b5c98e60c109de2e8c42bb5a5706ef25d3fffd8d19a50bfd017301221f006f41c5ee1c4a1fe7d7b972335955b5aef187dff342eea4b9c1ef5d468946bdaf333d71aaa5756aac3eb8b03382f2ed9ad9000872651db6836319f955ab3331a3ebac5d5030400e307000002000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "sign_large_nomination", 41);

            let signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x9000);
            expect(signatureResponse.error_message).toEqual("No errors");

            // Now verify the signature
            let prehash = txBlob;
            if (txBlob.length > 256) {
                const context = blake2bInit(32, null);
                blake2bUpdate(context, txBlob);
                prehash = Buffer.from(blake2bFinal(context));
            }
            const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey);
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

});
