const addon = require('./build/Release/addon.node');

console.log('--------------------------- hello')
console.log(addon.hello());
console.log(addon.addOne(4));

//callback
console.log('--------------------------- callback')
var callme = function(message) {
    if (message) {
        console.log(message);
    } else {
        console.log("I've been called!");
    }
}

addon.callthis(callme);
addon.callthis_withthis(callme, "This is an important message");
addon.callthis_withthis(() => {
    console.log('hello carrien');
});

//add
console.log('--------------------------- add')
console.log(addon.add(3, 4));
var u = addon.add(1)
console.log(u);
console.log(u === undefined);