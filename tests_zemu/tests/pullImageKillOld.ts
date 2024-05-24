import Zemu from '@zondax/zemu'

async function main() {
  await Zemu.checkAndPullImage()
  await Zemu.stopAllEmuContainers()
}

main().catch(console.error)
