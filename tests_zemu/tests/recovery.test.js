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
const Resolve = require("path").resolve;

const APP_SEED = "equip will roof matter pink blind book anxiety banner elbow sun young"

var simOptions = {
    logging: true,
    start_delay: 3000,
    custom: `-s "${APP_SEED}"`,
    X11: false
};

let models = [
    ['S', {model: 'nanos', prefix: 'S', path: Resolve("../app/output/app_s.elf")}],
    ['X', {model: 'nanox', prefix: 'X', path: Resolve("../app/output/app_x.elf")}]
]

jest.setTimeout(60000)

async function activateSecretMode(sim) {
    // Get to Zondax.ch menu
    for (let i = 0; i < 3; i += 1) {
        await sim.clickRight();
    }

    // Activate secret features
    for (let i = 0; i < 10; i += 1) {
        await sim.clickBoth();
    }

    let reviewSteps = 8;
    if (sim.model === "nanox") {
        reviewSteps = 6;
    }

    // Review warning message
    for (let i = 0; i < reviewSteps; i += 1) {
        await sim.clickRight();
    }

    // Accept
    await sim.clickBoth();
}

describe('Standard', function () {
    test.each(models)('main secret menu (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start({model, ...simOptions});
            const app = newPolkadotApp(sim.getTransport());

            const polkadot_expected_address = "166wVhuQsKFeb7bd1faydHgVvX1bZU2rUuY7FJmWApNz2fQY";
            const polkadot_expected_pk = "e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419";
            const kusama_expected_address = "16nK5XEGrPHjSwzHAdkKabmwu6L2t1RGW6drYyGgS84UZDRy";
            const kusama_expected_pk = "ffbc10f71d63e0da1b9e7ee2eb4037466551dc32b9d4641aafd73a65970fae42";

            let resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000);
            console.log(resp)
            expect(resp.address).toEqual(polkadot_expected_address);
            expect(resp.pubKey).toEqual(polkadot_expected_pk);

            await activateSecretMode(sim)

            resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000);
            console.log(resp)
            expect(resp.address).toEqual(kusama_expected_address);
            expect(resp.pubKey).toEqual(kusama_expected_pk);

        } finally {
            await sim.close();
        }
    });
});
