import { DeviceModel } from '@zondax/zemu'

const Resolve = require('path').resolve

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'

const APP_PATH_S = Resolve('../app/output/app_s.elf')
const APP_PATH_X = Resolve('../app/output/app_x.elf')
const APP_PATH_SP = Resolve('../app/output/app_s2.elf')

export const models: DeviceModel[] = [
  { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  { name: 'nanox', prefix: 'X', path: APP_PATH_X },
  { name: 'nanosp', prefix: 'SP', path: APP_PATH_SP },
]


export const txProxy_proxy_transferKeepAlive =
  '1d00d6b008a737aed42bb2c1ae6d9f1e5684a4ed31c02ad7322c225b624defa5f04d00050300d6b008a737aed42bb2c1ae6d9f1e5684a4ed31c02ad7322c225b624defa5f04d07401cdcdf0205000000e62300000c00000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c347230be35deffb71bb83f47b2b91216ccb1315663dc93a3a4861546061bbe52b'
