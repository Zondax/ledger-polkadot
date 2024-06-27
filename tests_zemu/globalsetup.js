const Zemu = require('@zondax/zemu')

/**
 * Sets up a handler to stop all emulator containers when a SIGINT is received.
 */
const catchExit = () => {
  process.on('SIGINT', async () => {
    await Zemu.default.stopAllEmuContainers()
    process.exit()
  })
}

/**
 * Initializes the emulator environment by setting up exit handlers,
 * pulling the latest emulator image, and stopping any running emulator containers.
 */
module.exports = async () => {
  catchExit()
  await Zemu.default.checkAndPullImage()
  await Zemu.default.stopAllEmuContainers()
}
