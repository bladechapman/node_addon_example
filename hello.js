const nan_addon = require('./build/Release/nan_addon');
const node_addon = require('./build/Release/node_addon');

console.log(nan_addon.nan_hello());
console.log(nan_addon.nan_fibonacci(15));

console.log(node_addon.v8_hello());
