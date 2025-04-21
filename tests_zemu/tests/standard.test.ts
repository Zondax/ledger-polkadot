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

import Zemu, { ButtonKind, zondaxMainmenuNavigation, isTouchDevice } from '@zondax/zemu'
import { defaultOptions, DOT_SS58_PREFIX, PATH, models } from './common'
import { PolkadotGenericApp } from '@zondax/ledger-substrate'
import { SCHEME } from '@zondax/ledger-substrate/dist/common'

const expected_address = '166wVhuQsKFeb7bd1faydHgVvX1bZU2rUuY7FJmWApNz2fQY'
const expected_pk = 'e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419'
const expected_address_secp256k1 = '44f13602040fbda4eb5d01382830b306ec65f4be'
const expected_pk_secp256k1 = '0377c9cac4b494062cd4f59ae17303a6731bc6dea74bb1651f5ca64eac6a293831'
jest.setTimeout(180000)

describe('Standard', function () {
  test.concurrent.each(models)('can start and stop container', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(models)('main menu', async function (m) {
    const sim = new Zemu(m.path)
    try {
      const mainmenuNavigation = zondaxMainmenuNavigation(m.name)
      await sim.start({ ...defaultOptions, model: m.name })
      await sim.navigateAndCompareSnapshots('.', `${m.prefix.toLowerCase()}-mainmenu`, mainmenuNavigation.schedule)
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(models)('get app version', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = new PolkadotGenericApp(sim.getTransport(), 'dot')
      // const app = PolkadotApp(sim.getTransport())
      const resp = await app.getVersion()

      console.log(resp)

      expect(resp).toHaveProperty('testMode')
      expect(resp).toHaveProperty('major')
      expect(resp).toHaveProperty('minor')
      expect(resp).toHaveProperty('patch')
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(models)('get address', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = new PolkadotGenericApp(sim.getTransport(), 'dot')

      const resp = await app.getAddressEd25519(PATH, DOT_SS58_PREFIX, true)
      console.log(resp)

      expect(resp.pubKey).toEqual(expected_pk)
      expect(resp.address).toEqual(expected_address)
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(models)('get secp256k1 address', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = new PolkadotGenericApp(sim.getTransport(), 'dot')

      // Using new method to get secp256k1 address
      const resp = await app.getAddressEcdsa(PATH, false)
      console.log(resp)

      expect(resp.pubKey).toEqual(expected_pk_secp256k1)
      expect(resp.address).toEqual(expected_address_secp256k1)
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(models)('show address', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({
        ...defaultOptions,
        model: m.name,
        approveKeyword: isTouchDevice(m.name) ? 'Confirm' : '',
        approveAction: ButtonKind.DynamicTapButton,
      })
      const app = new PolkadotGenericApp(sim.getTransport(), 'dot', '')
      const respRequest = app.getAddressEd25519(PATH, DOT_SS58_PREFIX, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-show_address`)

      const resp = await respRequest

      console.log(resp)

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(models)('show address secp256k1', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({
        ...defaultOptions,
        model: m.name,
        approveKeyword: isTouchDevice(m.name) ? 'Confirm' : '',
        approveAction: ButtonKind.DynamicTapButton,
      })
      const app = new PolkadotGenericApp(sim.getTransport(), 'dot', '')

      // Using old method to check backward compatibility
      const respRequest = app.getAddress(PATH, DOT_SS58_PREFIX, true, 2)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-show_address-secp256k1`)

      const resp = await respRequest

      console.log(resp)

      expect(resp.address).toEqual(expected_address_secp256k1)
      expect(resp.pubKey).toEqual(expected_pk_secp256k1)
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(models)('show address - reject', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({
        ...defaultOptions,
        model: m.name,
        rejectKeyword: isTouchDevice(m.name) ? 'Public key' : '',
      })
      const app = new PolkadotGenericApp(sim.getTransport(), 'dot')

      const respRequest = app.getAddressEd25519(PATH, DOT_SS58_PREFIX, true)
      expect(respRequest).rejects.toMatchObject({
        returnCode: 0x6986,
        errorMessage: 'Transaction rejected',
      })
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      try {
        await sim.compareSnapshotsAndReject('.', `${m.prefix.toLowerCase()}-show_address_reject`)
      } catch {}
    } finally {
      await sim.close()
    }
  })
})
