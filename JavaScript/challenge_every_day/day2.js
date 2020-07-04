// primitive types are copied by value and reference types (object and arrays) are copied by reference.

// Objects
let obj = {name : 'Adi'};
let data = obj;

obj['name'] = 'Other';
console.log(data['name']); // Other

// Array
let arr = [1, 2, 3];
let cpyArr = arr;
arr[3] = 4;

console.log(cpyArr[3]); // 4

// Primitives
// numbers
let num = 5;
let cpynum = num;
num = 7;

console.log(cpynum); // remain 5 !

//strings
let str = 'Adi';
let cpystr = str;
str = 'Peretz';

console.log(cpystr); // remain Adi !

//booleans
let t = true;
let f = t;
t = false;
console.log(f); // remain true !

