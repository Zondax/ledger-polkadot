/*******************************************************************************
 *  (c) 2018 - 2024 Zondax AG
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
 ******************************************************************************/

import Zemu, { ButtonKind, ClickNavigation, TouchNavigation, isTouchDevice } from '@zondax/zemu'

import { ASTAR_PATH, defaultOptions, DOT_SS58_PREFIX, migrationModels, PATH } from './common'
import { PolkadotGenericApp } from '@zondax/ledger-substrate'
import { IButton, SwipeDirection } from '@zondax/zemu/dist/types'

const polkadot_pk = 'e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419'
const astar_pk = 'cf557b2d2bebf3e14f932fec31d2b3ea776b63eede6658e282c9ab3f27d1287b'

jest.setTimeout(45000)

describe('Migration', function () {
  test.concurrent.each(migrationModels)('main menu + get version', async function (m) {
    const sim = new Zemu(m.path)
    try {
      let migrationStartText = 'review'
      if (m.name === 'nanos') {
        migrationStartText = 'Review'
      }

      await sim.start({
        ...defaultOptions,
        startText: migrationStartText,
        model: m.name,
        approveKeyword: isTouchDevice(m.name) ? 'Accept' : '',
        approveAction: ButtonKind.DynamicTapButton,
      })

      let nav = undefined
      if (isTouchDevice(m.name)) {
        const okButton: IButton = {
          x: 200,
          y: 550,
          delay: 0.25,
          direction: SwipeDirection.NoSwipe,
        }
        nav = new TouchNavigation(m.name, [ButtonKind.SwipeContinueButton, ButtonKind.ConfirmYesButton])
        nav.schedule[1].button = okButton
      } else if (m.name === 'nanos') {
        nav = new ClickNavigation([5, 0])
      } else {
        nav = new ClickNavigation([4, 0])
      }

      const path = '.'
      const testcaseName = `${m.prefix.toLowerCase()}-migration-mainmenu`

      const lastIndex = await sim.navigate(path, testcaseName, nav.schedule)
      await sim.compareSnapshots(path, testcaseName, lastIndex)
      await sim.takeSnapshotAndOverwrite(path, testcaseName, lastIndex)

      const app = new PolkadotGenericApp(sim.getTransport(), 'dot')

      // Verify app version
      const respVersion = await app.getVersion()

      console.log(respVersion)

      expect(respVersion).toHaveProperty('testMode')
      expect(respVersion).toHaveProperty('major')
      expect(respVersion).toHaveProperty('minor')
      expect(respVersion).toHaveProperty('patch')

      // Verify addresses
      const respDOT = await app.getAddress(PATH, DOT_SS58_PREFIX)
      console.log(respDOT)

      expect(respDOT.pubKey).toEqual(polkadot_pk)

      const respASTR = await app.getAddress(ASTAR_PATH, DOT_SS58_PREFIX)
      console.log(respASTR)

      expect(respASTR.pubKey).toEqual(astar_pk)
    } finally {
      await sim.close()
    }
  })
})
