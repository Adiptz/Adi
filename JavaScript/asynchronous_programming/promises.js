// First try of promises --> didn't success chaining
{
    const promiseCleanTheRoom = new Promise(function (resolve, reject) {

        const isRoomClean = false;

        if (isRoomClean) {
            resolve('Yes!');
        }

        reject('No!');
    });

    promiseCleanTheRoom.then(function (promiseResolve) {
        console.log('The room is clean ? ' + promiseResolve);
        return promiseResolve;
    }).catch(function(promiseReject){ // could replaced : delete 'catch' and pass as second argument of then
        console.log('The room is clean ? ' + promiseReject);
        return promiseReject;
    });

    // TODO : How to operate this snip ONLY when last promise has resolved
    // .then(function (newPromise) {
    //     console.log('You\'re the Best!');
    // });
}

// Promise.all()
// get an array of promises - return an array of resolved after all promises resolved!
{
    const recordChanel1 = new Promise((resolve, reject) => {
        setTimeout(resolve('1 success'), 1000);
    });

    const recordChanel2 = new Promise((resolve, reject) => {
        setTimeout(resolve('2 success'), 10000);
    });

    const recordChanel3 = new Promise((resolve, reject) => {
        resolve('3 success');
        // reject('3 failed');
    });

    Promise.all([recordChanel1,
                 recordChanel2,
                 recordChanel3]).then((messages) => {
                                        console.log(messages)
                                }).catch((messages) => {
        console.log(messages);
    });
}

// async + await
// async ensures that the function returns a promise, and wraps non-promises in it
// await makes JavaScript wait until that promise settles and returns its result.
{
     async function f() {
        // try to take off

        const promise =  await new Promise((resolve, reject) => {
            setTimeout(() => resolve("done!"), 3000)
        });

         const promise1 =  await new Promise((resolve, reject) => {
             setTimeout(() => resolve("done!"), 3000)
         });

        return "OK";

        // const some = await setTimeout(() => console.log("Daniel"), 2000);
        // wait until the promise resolves (*)
        // return promise;
    }

    f().then((result) => {
        console.log(result); // "done!"
    });

}

