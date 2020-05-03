import Zemu from "@zondax/zemu";
import OasisApp from "ledger-oasis-js";
import path from "path";

const APP_PATH = path.resolve(`./../../app/bin/app.elf`);

const seed = "equip will roof matter pink blind book anxiety banner elbow sun young"
const SIM_OPTIONS = {
    logging: true,
    start_delay: 4000,
    X11: true,
    custom: `-s "${seed}" --color LAGOON_BLUE`
};

async function beforeStart() {
    process.on("SIGINT", () => {
        Zemu.default.stopAllEmuContainers(function () {
            process.exit();
        });
    });
    await Zemu.default.checkAndPullImage();
}

async function beforeEnd() {
    await Zemu.default.stopAllEmuContainers();
}

async function debugScenario(sim, app) {
    // Here you can customize what you want to do :)
    const path = [44, 474, 5, 0, 3];
    const addrRequest = await app.getAddressAndPubKey(path);

    await Zemu.default.sleep(1000);
    // await sim.clickRight();
    await sim.clickBoth();

    const addr = await addrRequest;
    console.log(addr)

    // From https://iancoleman.io/bip39/
    const expected_pk = "";
    const expected_addr = "";

    if (addr.return_code !== 0x9000) {
        console.log("INVALID RESPONSE")
        return;
    }

    const pk = addr.address_raw.toString('hex');
    console.log(pk)
    if (expected_pk !== pk) {
        console.log("INCORRECT PK!")
    }

    console.log(addr.address)
    if (expected_addr !== addr.address) {
        console.log("INVALID ADDRESS!")
    }
}

async function main() {
    await beforeStart();

    if (process.argv.length > 2 && process.argv[2] === "debug") {
        SIM_OPTIONS["custom"] = SIM_OPTIONS["custom"] + " --debug";
    }

    const sim = new Zemu.default(APP_PATH);

    try {
        await sim.start(SIM_OPTIONS);
        const app = new OasisApp.default(sim.getTransport());

        ////////////
        /// TIP you can use zemu commands here to take the app to the point where you trigger a breakpoint

        await debugScenario(sim, app);

        /// TIP

    } finally {
        await sim.close();
        await beforeEnd();
    }
}

(async () => {
    await main();
})();
