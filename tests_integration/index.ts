import { ApiPromise, WsProvider } from '@polkadot/api';
import { PolkadotGenericApp } from '@zondax/ledger-substrate';
import transport from "@ledgerhq/hw-transport-node-hid"
import { hexToU8a } from '@polkadot/util';
import axios from "axios";
import {ExtrinsicPayloadValue} from "@polkadot/types/types/extrinsic";

// Function to initialize Ledger
async function initLedger() {
  const t = await transport.create()
  const ledger = new PolkadotGenericApp(t, 'roc', "https://api.zondax.ch/polkadot/transaction/metadata");

  await ledger.getVersion(); // Initialize the Ledger app

  return ledger;
}

// Reference: https://github.com/polkadot-js/api/issues/1421

async function main() {
  // Connect to the Polkadot network
  const wsProvider = new WsProvider('wss://rococo-rpc.polkadot.io');
  const api = await ApiPromise.create({ provider: wsProvider });

  // Initialize Ledger
  const ledger = await initLedger();

  // Define sender and receiver addresses and the amount to transfer
  const senderAddress = await ledger.getAddress("m/44'/354'/0'/0'/0'", 42);
  const receiverAddress = '5HfLsSjQnru3tjrsGCwVuzPi7ePhUxrtGHm6EoaTKNTfQy86';
  const transferAmount = 1_000_000_000_000;

  console.log("sender address " + senderAddress.address)
  const nonceResp = await api.query.system.account(senderAddress.address);
  const {nonce} = nonceResp.toHuman() as any
  console.log("nonce " + nonce)

  // Create the transfer transaction
  const transfer = api.tx.balances.transferKeepAlive(receiverAddress, transferAmount);

  const resp = await axios.post("https://api.zondax.ch/polkadot/node/metadata/hash", {id: 'roc'})

  console.log("metadata hash " + resp.data.metadataHash)

  // Create the payload for signing
  const payload = api.createType('ExtrinsicPayload', {
    method: transfer.method.toHex(),
    nonce: nonce as unknown as number,
    genesisHash: api.genesisHash,
    blockHash: api.genesisHash,
    transactionVersion: api.runtimeVersion.transactionVersion,
    specVersion: api.runtimeVersion.specVersion,
    runtimeVersion: api.runtimeVersion,
    version: api.extrinsicVersion,
    mode: 1,
    metadataHash: hexToU8a("01" + resp.data.metadataHash)
  });

  console.log("payload to sign[hex] " + Buffer.from(payload.toU8a(true)).toString("hex"))
  console.log("payload to sign[human] " + JSON.stringify(payload.toHuman(true)))

  // Request signature from Ledger
  // Remove first byte as it indicates the length, and it is not supported by shortener and ledger app
  const { signature } = await ledger.sign("m/44'/354'/0'/0'/0'", Buffer.from(payload.toU8a(true)));

  console.log("signature " + signature.toString("hex"))

  const payloadValue :ExtrinsicPayloadValue= {
    era: payload.era,
    genesisHash: api.genesisHash,
    blockHash: api.genesisHash,
    method: transfer.method.toHex(),
    nonce: nonce as unknown as number,
    specVersion: api.runtimeVersion.specVersion,
    tip: 0,
    transactionVersion: api.runtimeVersion.transactionVersion,
    mode: 1,
    metadataHash: hexToU8a("01" + resp.data.metadataHash)
  }

  // Combine the payload and signature to create a signed extrinsic
  const signedExtrinsic = transfer.addSignature(senderAddress.address, signature, payloadValue );

  console.log("signedTx to broadcast[hex] " + Buffer.from(signedExtrinsic.toU8a()).toString("hex"))
  console.log("signedTx to broadcast[human] " + JSON.stringify(signedExtrinsic.toHuman(true)))

  // Submit the signed transaction
  await transfer.send((status)=>{
    console.log(`Tx status: ${JSON.stringify(status)}`);
  });

  await new Promise((resolve ) => setTimeout(resolve, 120000))
}

main().catch(console.error).finally(() => process.exit());
