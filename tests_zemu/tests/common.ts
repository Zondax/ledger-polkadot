import { DeviceModel } from '@zondax/zemu'

const Resolve = require('path').resolve

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'

const APP_PATH_S = Resolve('../app/output/app_s.elf')
const APP_PATH_X = Resolve('../app/output/app_x.elf')

export const models: DeviceModel[] = [
  { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  { name: 'nanox', prefix: 'X', path: APP_PATH_X },
]

export const txBasic =
  '050000db5759e8e6bb673b7b9d7468c4086a845ae5c30bffd59a08f94501cd95e606396d0fd5038d248ed73e0da22300000800000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3'

export const txNomination =
  '07050c0084d4a8e337e1d886b91cf845938451df3b0965bc59dea1eeb9b56e927d9bfd0900cc2c0101a6ee7fc407a6750f3a30d822c6205406b6e05866af7f3fcff294731c006f5f2cf53f2621cac6a24339c4572a25e18dd49157c36f42e1afbae2eba0cf90d50391018ed73e0da22300000800000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3'
