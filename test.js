const addon = require('./build/Release/addon.node');

console.log(addon.hello());
console.log(addon.addOne(4));

//callback
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