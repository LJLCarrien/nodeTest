var addon = require('bindings')('test');

console.log(addon.hello()); // 'world'