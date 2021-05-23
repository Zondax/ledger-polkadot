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
import { newPolkadotApp } from '@zondax/ledger-polkadot'
import { APP_SEED, models } from './common'

// @ts-ignore
import ed25519 from 'ed25519-supercop'
// @ts-ignore
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

jest.setTimeout(60000)

describe('Standard', function () {
  test.each(models)('can start and stop container', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
    } finally {
      await sim.close()
    }
  })

  test.each(models)('main menu', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      await sim.navigateAndCompareSnapshots('.', `${m.prefix.toLowerCase()}-mainmenu`, [1, 0, 0, 5, -5])
    } finally {
      await sim.close()
    }
  })

  test.each(models)('get app version', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolkadotApp(sim.getTransport())
      const resp = await app.getVersion()

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')
      expect(resp).toHaveProperty('test_mode')
      expect(resp).toHaveProperty('major')
      expect(resp).toHaveProperty('minor')
      expect(resp).toHaveProperty('patch')
    } finally {
      await sim.close()
    }
  })

  test.each(models)('get address', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolkadotApp(sim.getTransport())

      const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      const expected_address = '166wVhuQsKFeb7bd1faydHgVvX1bZU2rUuY7FJmWApNz2fQY'
      const expected_pk = 'e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419'

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('show address', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolkadotApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', `${m.prefix.toLowerCase()}-show_address`, 2)

      const resp = await respRequest

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      const expected_address = '166wVhuQsKFeb7bd1faydHgVvX1bZU2rUuY7FJmWApNz2fQY'
      const expected_pk = 'e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419'

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('show address - reject', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolkadotApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', `${m.prefix.toLowerCase()}-show_address_reject`, 3, 2)

      const resp = await respRequest
      console.log(resp)

      expect(resp.return_code).toEqual(0x6986)
      expect(resp.error_message).toEqual('Transaction rejected')
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign basic normal', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolkadotApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlobStr =
        '050000eb59733e8380cd2b0b016ca5c869ea96cf533b3aa1eb61390afd349c83b51e578ed73e0dd503000b63ce64c10c051e0000000700000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3'

      const txBlob = Buffer.from(txBlobStr, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', `${m.prefix.toLowerCase()}-sign_basic_normal`, m.name === 'nanos' ? 5 : 5)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32, null)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign basic expert', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolkadotApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      // Change to expert mode so we can skip fields
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()

      const txBlobStr =
        '050000eb59733e8380cd2b0b016ca5c869ea96cf533b3aa1eb61390afd349c83b51e578ed73e0dd503000b63ce64c10c051e0000000700000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3'

      const txBlob = Buffer.from(txBlobStr, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', `${m.prefix.toLowerCase()}-sign_basic_expert`, 11)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32, null)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign large nomination', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolkadotApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlobStr =
        '07052000aa8a5fae8673bf78e2ec1979dfd85036e13fabf352afe8ca2b2e9228de0ab4780000c81b48ea7c653da3ad40bf552f2ac1ad3355b4e287273a990a4758ac922464000a2ee6d81952c2d3a2a87d90a4647957ae370d84f41f16d2f3d420e3eec718700082aaea231c743ca260d0e2c7e9dcddbdacdecb291cd2ea45c8680a0e79a6f7020052bd4e02a0b206af2b64e02643783d94e4b10aad8e68b5af573fa50a2ea7ee19005a8add1131397aa1d6a9cb5ee20d41bb93a9da35df3f0d3aee102c8abb15e910004adcd9098665791d91e86a0960f27d16aa28c18d66d10720f6e5b6ebc17ad17f005864b341caa9120033861730f104f97d653671c7d87d1a4ac6f42d21009fee30d503048ed73e0d1e0000000700000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3'

      const txBlob = Buffer.from(txBlobStr, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', `${m.prefix.toLowerCase()}-sign_large_nomination`, m.name === 'nanos' ? 18 : 11)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32, null)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })
})
