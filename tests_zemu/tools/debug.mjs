import Zemu from "@zondax/zemu";
import LedgerApp from "@zondax/ledger-polkadot";
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
    const pathAccount = 0x80000000;
    const pathChange = 0x80000000;
    const pathIndex = 0x80000000;

    let txBlobStr = "04002756865871cd8e8c2e27b5c5254a8ab6933a5c3081bdcbdc78751fb9c8af12f200d503008ed73e0d26040000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe";
    const txBlob = Buffer.from(txBlobStr, "hex");

    const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true);
    await Zemu.default.sleep(1000);
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickBoth();
    let addr = await respRequest;

    // do not wait here.. we need to navigate
    const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
    await Zemu.default.sleep(1000);
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickBoth();

    let signature = await signatureRequest;
    console.log(signature);
}

async function main() {
    await beforeStart();

    if (process.argv.length > 2 && process.argv[2] === "debug") {
        SIM_OPTIONS["custom"] = SIM_OPTIONS["custom"] + " --debug";
    }

    const sim = new Zemu.default(APP_PATH);

    try {
        await sim.start(SIM_OPTIONS);
        const app = new LedgerApp.default(sim.getTransport());

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
