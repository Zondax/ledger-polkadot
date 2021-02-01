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

const {newKusamaApp} = require("@zondax/ledger-polkadot");
const ed25519 = require("ed25519-supercop");
import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";
var addon = require('../../tests_tools/neon/native');

const Resolve = require("path").resolve;

const APP_PATH = Resolve("../app/output/app_sr25519.elf");
const APP_SEED = "equip will roof matter pink blind book anxiety banner elbow sun young"

const simOptions = {
    logging: true,
    start_delay: 3000,
    custom: `-s "${APP_SEED}"`,
    X11: false
};

jest.setTimeout(60000)

describe('SR25519', function () {
    test('get address sr25519', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());

            const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000, false, 1);

            console.log(resp)

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "Cz4vu6J2NHP977ZYZcMCdjmmLgmddKvXRi5TxecuTgFfKww";
            const expected_pk = "121cc87d316d311fe3e3b9c34b1083a29c55f6ebd214b60f59578b0a37007424";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);

        } finally {
            await sim.close();
        }
    });

    test('show address sr25519', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-show_address_sr25519", 2);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "Cz4vu6J2NHP977ZYZcMCdjmmLgmddKvXRi5TxecuTgFfKww";
            const expected_pk = "121cc87d316d311fe3e3b9c34b1083a29c55f6ebd214b60f59578b0a37007424";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);
        } finally {
            await sim.close();
        }
    });

    test('show address - reject sr25519', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.compareSnapshotsAndAccept(".", "s-show_address_reject_sr25519", 3, 2);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test('sign basic normal', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0400a03c31b64722c0852992e65493764f31ca55a86a8fa3262ba54381698bcc066133158139ae28a3dfaac5fe1560a5e9e05cd503ae1103008ed73e0dea07000003000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-sign_basic_normal", 6);

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
            let signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey,signingcontext,prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test('sign basic expert', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            // Change to expert mode so we can skip fields
            await sim.clickRight();
            await sim.clickBoth();
            await sim.clickLeft();

            let txBlobStr = "0400a03c31b64722c0852992e65493764f31ca55a86a8fa3262ba54381698bcc066133158139ae28a3dfaac5fe1560a5e9e05cd503ae1103008ed73e0dea07000003000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false , 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);

            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-sign_basic_expert", 12);

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
            let signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey,signingcontext,prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test('sign basic expert - accept shortcut', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            // Change to expert mode so we can skip fields
            await sim.clickRight();
            await sim.clickBoth();
            await sim.clickLeft();

            let txBlobStr = "0400d401b48506d4de473a04f40ad8114add5eda886068a71efdf95eee616ee4909e33158139ae28a3dfaac5fe1560a5e9e05cd503ae1103006d0fe707000003000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);

            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            // Shortcut to accept menu
            await sim.clickBoth();

            // Accept tx
            await sim.clickBoth();

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
            let signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey,signingcontext,prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test('sign basic - forward/backward', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0400d401b48506d4de473a04f40ad8114add5eda886068a71efdf95eee616ee4909e33158139ae28a3dfaac5fe1560a5e9e05cd503ae1103006d0fe707000003000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-sign_basic_FB", 6, 1);

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
            let signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey,signingcontext,prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test('sign basic - forward/backward-reject', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0400d401b48506d4de473a04f40ad8114add5eda886068a71efdf95eee616ee4909e33158139ae28a3dfaac5fe1560a5e9e05cd503ae1103006d0fe707000003000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-sign_basic_FB_reject", 7, 1);

            let signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x6986);
            expect(signatureResponse.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test('sign large nomination', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "060540632751e57bd704b9d0e1a016f35e86df929bac522e6cfc4eae03eb2a4411862ff768f8cd08f228b69a8bd71da4caa9611fcfc1be95df68cc1a28e45d7f8e4e38b80d7731115479b1bd9918a1294bd9d22c62f7de1bbe2553525dd52a779b3110ff28e16b81b22bbc3d3163b3ba1fefb9438cea8560cb0711308ab398351c89464eb2015e9a9082ac9eecd9d08868b7c38a1ed3eee6625ac027c83c49c3d57064de8952adef2e842465ec59eca2c83574a158640b294e539eae2b64c3fe86b1c7432f90c11bde3958ed8cfe29e26cd6d951d4047a4245e608743be02e7cca6c28d7d91d06e16880c2dc29b7d6d79255048a78212c76436b1fbfe96e9a61be9f0438131d928b065389b2c7eacf4ba6d3599ea01f7e142e48391e784e5603a88c53f1559a8bac1a6969efb9d30b3fad16b8d361a286072b443167a588363bd1146177d8eb34473d68f27d638321d6c35942057253842d9b9770c574dbb7b0a9ce6cac2bd27d0692ebf2d661f587354b41a8b47bce6240dc76a0f802a22930ca77814b79a4c8b3a02ae3b6bffed9ae90b186ceb8976f65dba2cd278c80170d447f49eab42ba84f4f319580c8e5dd0561df82f00d6178fc0661a12033eccdafae1a98c755a79b7622993005a2877a797c968ebd895fa9fab4e5e6bb88e87fb9ebfc0674741994dd6f5c40fb06adc78b9f53ae1cdcb369c77a528ea6ee2a140064783fd50391018ed73e0de707000003000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-sign_large_nomination", 34);

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
            let signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey,signingcontext,prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });
});
