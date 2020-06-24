/* pure function
    have no side-effects
 */
function pureDouble(x) {
    return x * 2;
}

/* Array */

// array.slice(start, end)
{
// returns the selected elements in an array, as a new array object.
// does not include, the given end argument.
// Note: The original array will not be changed.

    const arr = [1, 2, 3, 4, 5];
    const shortArr = arr.slice(0, 3);
    console.log(shortArr);
}

// arr.filter(callback)
{
    // creates a new array with all elements that pass the test implemented by the provided function.

    // arr :
    const testA = ['aba', 'Aba', 'Amen', 'hello'];

    // callback :
    function startWithA(word) {
        if (word.startsWith('A')) return true;
    }

    const wordsStartWithA = testA.filter(startWithA);
    console.log(wordsStartWithA);
}

// arr.join([separator])
{
    // creates and returns a new string by concatenating all of the elements in an array,
    // separated by commas or a specified separator string.
    const sentence = ['hello', 'i\'m', 'separated', 'without', 'specified', 'separator'];
    const str = sentence.join();
    console.log(str);

    const sentence2 = ['hello', 'i\'m', 'separated', 'with', 'specified', 'separator', 'which', 'is : ', ''];
    const str2 = sentence2.join('-');
    console.log(str2);

}

// arr.map(callback)
{
    // creates a new array populated with the results of
    // calling a provided function on every element in the calling array.
    const arr = [1, 2, 3];

    // callback
    function divideBy2(number) {
        return number / 2;
    }

    console.log(arr.map(divideBy2));
}

//  array3 = array1.concat(array2)
{
    const arr1 = [1, 2];
    const arr2 = [3, 4];
    const arr1To4 = arr1.concat(arr2);
    console.log(arr1To4);
}

// arr.some(callback)
{
    //  tests whether at least one element in the array passes the test
    // return Boolean

    const array = [1, 2, 3, 4, 5];
    const arrayWithoutEvens = [1, 3, 5, 7, 9];
    const even = (element) => element % 2 === 0;

    console.log(array.some(even));
    console.log(arrayWithoutEvens.some(even));
}

// arr.every(callback)
{
    // method tests whether all elements in the array pass the test implemented by the provided function
    // return Boolean
    const array = [1, 2, 3, 4, 5];
    const arrayOfOdds = [1, 3, 5, 7, 9];
    const odd = (element) => element % 2 !== 0;

    console.log(arrayOfOdds.every(odd));
    console.log(array.every(odd));

}

// Exercise 2 - High Order
{
    function paramFunc() {
            // do nothing
        return 5;
    }

    function higherOrder(someFunc) {
        console.log(someFunc);
        console.log(someFunc());
    }

    higherOrder(paramFunc);
}
