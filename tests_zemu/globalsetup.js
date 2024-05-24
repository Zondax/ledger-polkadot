const Zemu = require('@zondax/zemu')

const catchExit = async () => {
  process.on('SIGINT', () => {
    Zemu.default.stopAllEmuContainers(function () {
      process.exit()
    })
  })
}

module.exports = async () => {
  await catchExit()
  await Zemu.default.checkAndPullImage()
  await Zemu.default.stopAllEmuContainers()
}
