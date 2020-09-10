var test = require('bindings')('test');

let id = 7300;
let name = 'carrien';
let password = '123123123';
console.log(test.method_proHelper(id, name, password));
console.log(test.method_shareMemoryHelper());