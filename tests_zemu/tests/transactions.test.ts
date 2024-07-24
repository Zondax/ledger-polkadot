/** ******************************************************************************
 *  (c) 2018 - 2023 Zondax AG
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

import Zemu from '@zondax/zemu'
import axios from 'axios'
import { PolkadotGenericApp } from '@zondax/ledger-substrate'
import { defaultOptions, DOT_SS58_PREFIX, PATH, TEST_TRANSACTIONS, models, TEST_TRANSACTIONS_FAIL } from './common'

// @ts-expect-error missing typings
import ed25519 from 'ed25519-supercop'
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'

jest.setTimeout(180000)

describe.each(TEST_TRANSACTIONS)('Transactions - OK', function (data) {
  test.concurrent.each(models)(`Test: ${data.name}`, async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = new PolkadotGenericApp(sim.getTransport(), 'dot')

      const blob = Buffer.from(data.blob.replace("<rootHash>", data.rootHash), 'hex')
      const metadata = Buffer.from(data.metadata, 'hex')

      const { pubKey } = await app.getAddress(PATH, DOT_SS58_PREFIX)

      // do not wait here.. we need to navigate
      const signatureRequest = app.signWithMetadata(PATH, blob, metadata)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-${data.name}`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse.signature.toString('hex'))

      // Now verify the signature
      let prehash = blob
      if (blob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, blob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.subarray(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })
})

describe.each(TEST_TRANSACTIONS)('Transactions - API - OK', function (data) {
  test.concurrent.each(models)(`Test: ${data.name}`, async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = new PolkadotGenericApp(sim.getTransport(), 'roc', 'https://api.zondax.ch/polkadot/transaction/metadata')

      const resp = await axios.post("https://api.zondax.ch/polkadot/node/metadata/hash", { id: 'roc' })
      const blob = Buffer.from(data.blob.replace("<rootHash>", resp.data.metadataHash), 'hex')

      const { pubKey } = await app.getAddress(PATH, DOT_SS58_PREFIX)

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(PATH, blob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-${data.name}`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse.signature.toString('hex'))

      // Now verify the signature
      let prehash = blob
      if (blob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, blob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.subarray(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })
})

describe.each(TEST_TRANSACTIONS_FAIL)('Transactions - FAIL', function (data) {
  test.concurrent.each(models)(`Test: ${data.name} - ${data.description}`, async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = new PolkadotGenericApp(sim.getTransport(), 'dot')

      const blob = Buffer.from(data.blob, 'hex')
      const metadata = Buffer.from(data.metadata, 'hex')

      let errorFound = undefined
      try {
        await app.signWithMetadata(PATH, blob, metadata)
      } catch (e) {
        errorFound = e
      }

      expect(errorFound).toBeDefined()
      console.log(errorFound)
    } finally {
      await sim.close()
    }
  })
})
