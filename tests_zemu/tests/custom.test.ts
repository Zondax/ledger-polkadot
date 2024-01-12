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

// @ts-expect-error missing typings
import ed25519 from 'ed25519-supercop'
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'
import { txBalances_transferAllowDeath, txSession_setKeys, txStaking_nominate, txProxy_proxy, txUtility_batch } from './zemu_blobs'

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

jest.setTimeout(180000)

const TXNS = [
  {
    name: 'balances_transfer',
    blob: txBalances_transferAllowDeath,
  },
  {
    name: 'session_setkeys',
    blob: txSession_setKeys,
  },
  {
    name: 'staking_nominate',
    blob: txStaking_nominate,
  },
  {
    name: 'proxy_proxy',
    blob: txProxy_proxy,
  },
  {
    name: 'txUtility_batch',
    blob: txUtility_batch,
  },
]

describe.each(TXNS)('Transactions', function (data) {
  test.concurrent.each(models)(`Test: ${data.name}`, async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolkadotApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(data.blob, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-${data.name}`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

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

test.concurrent.each(models)('balances transfer expert', async function (m) {
  const sim = new Zemu(m.path)
  try {
    await sim.start({ ...defaultOptions, model: m.name })
    const app = newPolkadotApp(sim.getTransport())
    const pathAccount = 0x80000000
    const pathChange = 0x80000000
    const pathIndex = 0x80000000

    // Change to expert mode
    await sim.toggleExpertMode()

    const txBlob = Buffer.from(txBalances_transferAllowDeath, 'hex')

    const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
    const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

    // do not wait here.. we need to navigate
    const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

    // Wait until we are not in the main menu
    await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

    await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-balances_transfer_expert`)

    const signatureResponse = await signatureRequest
    console.log(signatureResponse)

    expect(signatureResponse.return_code).toEqual(0x9000)
    expect(signatureResponse.error_message).toEqual('No errors')

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
