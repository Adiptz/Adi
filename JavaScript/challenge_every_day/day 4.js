// var, let and const

var name = 'Adi';
name = 'Peretz';
console.log(name); // Peretz

let lastName = 'Peretz';
lastName = 'Shuv';
console.log(lastName); // Shuv

const cannotChange = 'for gone';
cannotChange = 'please be different'; // TypeError: Assignment to constant variable.

