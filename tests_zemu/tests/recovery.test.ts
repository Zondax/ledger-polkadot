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

import Zemu, { DEFAULT_START_OPTIONS } from '@zondax/zemu'
import { newPolkadotApp } from '@zondax/ledger-substrate'
import { APP_SEED, models } from './common'

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

jest.setTimeout(60000)

describe('Recovery', function () {
  test.concurrent.each(models)('main secret menu (%s)', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolkadotApp(sim.getTransport())

      const polkadot_expected_address = '166wVhuQsKFeb7bd1faydHgVvX1bZU2rUuY7FJmWApNz2fQY'
      const polkadot_expected_pk = 'e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419'
      const kusama_expected_address = '16nK5XEGrPHjSwzHAdkKabmwu6L2t1RGW6drYyGgS84UZDRy'
      const kusama_expected_pk = 'ffbc10f71d63e0da1b9e7ee2eb4037466551dc32b9d4641aafd73a65970fae42'

      let resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      expect(resp.address).toEqual(polkadot_expected_address)
      expect(resp.pubKey).toEqual(polkadot_expected_pk)

      await sim.enableSpecialMode('Zondax', true)

      resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      expect(resp.address).toEqual(kusama_expected_address)
      expect(resp.pubKey).toEqual(kusama_expected_pk)
    } finally {
      await sim.close()
    }
  })
})
