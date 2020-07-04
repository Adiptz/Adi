let array = ['Adi', 'Peretz', 'Challenge'];
console.log(array.length); // 3

let newArray = array;
newArray.length = 0;

console.log(newArray.length); // 0

console.log(array.length); // ? 0

// Objects are stored and copied by "reference" !!!
console.log(array) // empty array!