// copy
let arr1 = [1, 2, 3];
let arr2 = [...arr1];
console.log(arr2);

// merge
let fruits = ['banana', 'apple', 'mango'];
let vegetables = ['cucumber'];
const merge = [...fruits, ...vegetables];
console.log(merge);


let objArr = [{num : 0, name : 'zero'}, {num : 1, name: 'one'}];
let test = [...objArr];

const str = 'hello';
let arr = str.split('');
console.log(arr);

let capitalizedHello = [...str[0]....str];
capitalizedHello[0] = capitalizedHello[0].toUpperCase();
console.log(capitalizedHello);