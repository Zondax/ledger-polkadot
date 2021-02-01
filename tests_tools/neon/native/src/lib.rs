extern crate neon;
use neon::prelude::*;

// reference
// https://neon-bindings.com/docs/primitives

//bridge stuff only

use schnorrkel::{context::*, PublicKey, Signature};

fn schnorrkel_verify(mut cx: FunctionContext) -> JsResult<JsValue> {

    let handler_pubkey = cx.argument::<JsBuffer>(0)?;
    let pubkeybytes = cx.borrow(&handler_pubkey, |data| data.as_slice::<u8>());

    let pubkey = PublicKey::from_bytes(pubkeybytes);
    if !pubkey.is_ok(){
        return Ok(cx.boolean(false).upcast());
    }

    let pk = pubkey.unwrap();

    let handler_context = cx.argument::<JsBuffer>(1)?;
    let context = cx.borrow(&handler_context, |data| data.as_slice::<u8>());

    let handler_message = cx.argument::<JsBuffer>(2)?;
    let message = cx.borrow(&handler_message, |data| data.as_slice::<u8>());

    let handler_signature = cx.argument::<JsBuffer>(3)?;
    let signaturebytes = cx.borrow(&handler_signature, |data| data.as_slice::<u8>());

    let signature = Signature::from_bytes(signaturebytes);
    if !signature.is_ok(){
        return Ok(cx.boolean(false).upcast());
    }

    let sig = signature.unwrap();

    let sigcontext = signing_context(context);

    let v = pk.verify(sigcontext.bytes(message), &sig);
    if v.is_ok(){
        Ok(cx.boolean(true).upcast())
    }else{
        Ok(cx.boolean(false).upcast())
    }
}

register_module!(mut m, {
    m.export_function("schnorrkel_verify", schnorrkel_verify)?;
    Ok(())
});
