let originalArr = [1, 2, 3, 4, 5];
let forEach, map;

/* forEach - you would never return from a forEach function,
             it's executes a provided function once
             for each array element. */
forEach = originalArr.forEach((num, index) => {
    return originalArr[index]= num * 2;
} );
console.log(forEach); // undefined - no return value on forEach
console.log(originalArr); //modified! [2, 4, 6, 8, 10]

originalArr = [1, 2, 3, 4, 5]; // initialize

/* map -  creates a new array contain
          the results of calling a provided function
          on every element in the calling array. */
map = originalArr.map(num => num * 2);
console.log(map); // has a value! [2, 4, 6, 8, 10]
console.log(originalArr); // no modification [1, 2, 3, 4, 5]

// Adi Peretz - web developer


