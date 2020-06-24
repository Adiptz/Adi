//Question 1
// {
//     function print2() {
//         console.log("print2");
//     }
//
//     console.log("print1");
//
//     setTimeout(print2, 1000);
//
//     console.log("print3");
// }

// Question 2
// {
//     function exponent(x){
//         return function(y){
//            return y ** x;
//         }
//     }
//
//     let cube = exponent(3);
//     console.log(cube(2), cube(3)); // 8, 27  cube = function(y) { return y ^ 3};
//     console.log(exponent(2)(3)); // 3 ^ 2 = 9
// }

// Question 3
// {
//     function doSomething() {
//
//         setTimeout(function () {
//             console.log("SURPRISE!");
//         }, 1000);
//
//         while(true) {}
//     }
//
//     doSomething();
// }

// Question 7
// {
//     let promise = new Promise(function(resolve, reject) {
//         resolve('Promise');
//         // console.log("Promise");
//     });
//
//     console.log("Hi");
// }

// Question 8
{
    let promise = new Promise(function (resolve, reject) {
        console.log("Promise"); // First because its in the executer
        resolve();
    });

    // last printed - the callback goes into callback-queue
    setTimeout(function () {
        console.log("Timeout");

    }, 0);

    // third printed - the callback goes into job-queue
    promise.then(function () {
        console.log("Resolved!");
    });

    // second printed - in the stack
    console.log("Hi");
}

