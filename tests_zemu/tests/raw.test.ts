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
import { defaultOptions, DOT_SS58_PREFIX, PATH, models } from './common'

// @ts-expect-error missing typings
import ed25519 from 'ed25519-supercop'
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'
import { PolkadotGenericApp } from '@zondax/ledger-substrate'
import { ResponseError } from '@zondax/ledger-js'

jest.setTimeout(180000)

const TESTS = [
  {
    name: 'raw_sign',
    text: '<Bytes>This is our test payload!</Bytes>',
  },
  {
    name: 'raw_sign_hex',
    text: '<Bytes>This is our test payload with emoji! 😉</Bytes>',
  },
]

describe.each(TESTS)('Raw signing', function (data) {
  test.concurrent.each(models)(`${data.name}`, async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = new PolkadotGenericApp(sim.getTransport(), 'dot')

      const txBlob = Buffer.from(data.text)
      const responseAddr = await app.getAddress(PATH, DOT_SS58_PREFIX)
      const pubKey = responseAddr.pubKey

      // do not wait here.. we need to navigate
      const signatureRequest = app.signRaw(PATH, txBlob)

      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-${data.name}`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.subarray(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })
})

test.concurrent.each(models)('Raw signing - incorrect', async function (m) {
  const sim = new Zemu(m.path)
  try {
    await sim.start({ ...defaultOptions, model: m.name })
    const app = new PolkadotGenericApp(sim.getTransport(), 'dot')

    const txBlob = Buffer.from('<Bytes>Incorrect blob/Bytes>')

    let errorFound: any = undefined
    try {
      await app.signRaw(PATH, txBlob)
    } catch (error) {
      errorFound = error
    }

    console.log(errorFound)

    expect(errorFound).toBeDefined()
    expect('returnCode' in errorFound).toBeTruthy()
    expect('errorMessage' in errorFound).toBeTruthy()

    if ('returnCode' in errorFound) {
      expect(errorFound.returnCode).toBe(27012)
    }
    if ('errorMessage' in errorFound) {
      expect(errorFound.errorMessage).toBe('Data is invalid : Unexpected value')
    }
  } finally {
    await sim.close()
  }
})

// TODO: add a test for the legacy wrapper to ensure we don't throw
