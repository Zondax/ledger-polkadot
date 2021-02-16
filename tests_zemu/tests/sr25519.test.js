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
import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";
var addon = require('../../tests_tools/neon/native');

const Resolve = require("path").resolve;

const APP_PATH = Resolve("../app/output/app_sr25519.elf");
const APP_SEED = "equip will roof matter pink blind book anxiety banner elbow sun young"

const simOptions = {
    logging: true,
    start_delay: 3000,
    custom: `-s "${APP_SEED}"`,
    X11: true
};

jest.setTimeout(60000)

describe('SR25519', function () {
    test('get address sr25519', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newPolkadotApp(sim.getTransport());

            const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000, false, 1);

            console.log(resp)

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "1b8tiTYdzk8hZ6W65ppiGPA5TnYBAnoRDSoyxyVbj1DZENm";
            const expected_pk = "1a08e8cba45e59c761ebe72133da0b7f4de8ce6a263690b07e3bd56dcc8d2226";

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
            const app = newPolkadotApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-show_address_sr25519", 2);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "1b8tiTYdzk8hZ6W65ppiGPA5TnYBAnoRDSoyxyVbj1DZENm";
            const expected_pk = "1a08e8cba45e59c761ebe72133da0b7f4de8ce6a263690b07e3bd56dcc8d2226";

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
            const app = newPolkadotApp(sim.getTransport());

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
            const app = newPolkadotApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0500c29421760786e979ca1f08f09e1793bcaa031ed77e3ad42dbe173e3cd62b410a33158139ae28a3dfaac5fe1560a5e9e05cd5030003d20296491a0000000500000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";

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
            const app = newPolkadotApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            // Change to expert mode so we can skip fields
            await sim.clickRight();
            await sim.clickBoth();
            await sim.clickLeft();

            let txBlobStr = "0500c29421760786e979ca1f08f09e1793bcaa031ed77e3ad42dbe173e3cd62b410a33158139ae28a3dfaac5fe1560a5e9e05cd5030003d20296491a0000000500000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";

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

    test('sign basic - forward/backward', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newPolkadotApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0500c29421760786e979ca1f08f09e1793bcaa031ed77e3ad42dbe173e3cd62b410a33158139ae28a3dfaac5fe1560a5e9e05cd5030003d20296491a0000000500000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";

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
            const app = newPolkadotApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0500c29421760786e979ca1f08f09e1793bcaa031ed77e3ad42dbe173e3cd62b410a33158139ae28a3dfaac5fe1560a5e9e05cd5030003d20296491a0000000500000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";

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
            const app = newPolkadotApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "07054026951b3286754fa7c9138b97e43cf0688b8e7a63edb63a79bcbc624bd534db2764de55acce68b57f853a486692609b81974d730449c272b466b7423752acdc2f3659bd3d1584f3b31261fbb0f9718a3031db1ffd6e15d2cad5e1cc67303802290cf166640c67010f7b253f176449bfb9578b4f545e115e28590a0145beb2be7da0ba634ed63f424e321d4a69aa8c80b9d53733b356e51a9413adc7dd5b56901274856fc73b6f71968133674ddd8fcb1ddc8e26f8e59f45334c14727411db5d3cb0a1c57153b1dcea8783d1eafd6de7f0a039fe9b66c76be7b9e7b95d14923d55ba5db57dcd5e8c54321df0e70670243be1634233ecc5708031efbbafd9e1676cb68cb8c024fdbe85995072874b6f6248da7b603724f225a2ca46319f7f8970688ec7826410f60a71fdd095ad2557f4ea8ea3c49187b502fa8dc753862775107afcebb20575eb7d25efc9b1abf206f1fd8c5f160d9aec935e24546bf265fb0b1cc0cfc577a00be15abce98ee0942047e612295f26b42a022e982749fbe2138b6daada43755b2a7b888db0d43caf60e4cac7a587d532097324bf44f57fc75ba24b541f6c230c5fc829843e33d81e2a211e5765fdcfd17f01cc7351ce0a5aa58771d414fa05274ebfb36fa34baaa5a25ff6bb063e8d6ce621c0ea9088aab74de6326007dd05c846e9523d9e6d42b5dce339a3a517abaeceb5565c11f589d2529562d5038d246d0f1a0000000500000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";

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
