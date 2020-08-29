// remove all values from array a, which are present in array b
// arrayDiff([1, 2], [1]) == [2];


import {removeDuplicates} from "./removeDuplicates.js";

const arrayDiff = (a, b) => {
    let i, j;
    const result = [];

    a = a.sort();
    b = b.sort();

    a = removeDuplicates(a);
    b = removeDuplicates(b);


    for (i = 0, j = 0
        ; j < b.length && i < a.length
        ;) {
        if (a[i] === b[j]) {
            ++i;
            ++j;
        } else if (a[i] < b[j]) {
            result.push(a[i]);
            ++i;
        } else if (a[i] > b[j]) {
            ++j;
        }
    }

    if (j === b.length) {
        while (i < a.length) {
            result.push(a[i]);
            ++i;
        }
    }

    return result;
}

let d = [10, 11, 1, 6, 2, 4, 5, 7, 8, 9];
let e = [2, 3, 1, 4, 7, 5];

console.log(arrayDiff(d, e));