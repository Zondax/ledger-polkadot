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
  '050000eb59733e8380cd2b0b016ca5c869ea96cf533b3aa1eb61390afd349c83b51e578ed73e0dd503000b63ce64c10c051e0000000700000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3'

export const txNomination =
  '07052000aa8a5fae8673bf78e2ec1979dfd85036e13fabf352afe8ca2b2e9228de0ab4780000c81b48ea7c653da3ad40bf552f2ac1ad3355b4e287273a990a4758ac922464000a2ee6d81952c2d3a2a87d90a4647957ae370d84f41f16d2f3d420e3eec718700082aaea231c743ca260d0e2c7e9dcddbdacdecb291cd2ea45c8680a0e79a6f7020052bd4e02a0b206af2b64e02643783d94e4b10aad8e68b5af573fa50a2ea7ee19005a8add1131397aa1d6a9cb5ee20d41bb93a9da35df3f0d3aee102c8abb15e910004adcd9098665791d91e86a0960f27d16aa28c18d66d10720f6e5b6ebc17ad17f005864b341caa9120033861730f104f97d653671c7d87d1a4ac6f42d21009fee30d503048ed73e0d1e0000000700000091b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c391b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3'
