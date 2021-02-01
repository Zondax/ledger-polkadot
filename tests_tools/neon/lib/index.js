var addon = require('../native');

// Here we can write some simple tests for play around
console.log("--------------------------------------")
console.log("- Kusama Tools Scratch Tests          -")
console.log("--------------------------------------\n\n")

a = Buffer.from("b65abc66a8fdeac1197d03daa6c3791d0c0799a52db6b7127b1cd12d46e34364",'hex');
b = Buffer.from([116, 101, 115, 116, 32, 109, 101, 115, 115, 97, 103, 101]);
c = Buffer.from("48fdbe5cf3524bdd078ac711565d658a3053d10660749959883c4710f49d9948b2d5f829bea6800897dc6ea0150ca11075cc36b75bfcf3712aafb8e1bd10bf8f", 'hex');

console.log(addon.schnorrkel_verify(a,Buffer.from([103, 111, 111, 100]),b, c));