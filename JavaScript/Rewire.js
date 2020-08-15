const logHello = () => console.log('hello')

const limitedLogHello = limit(logHello, 2000)

limitedLogHello() // logs 'hello'
limitedLogHello() // does nothing

// After waiting 2 seconds… (not a timeout)

limitedLogHello() // logs ‘hello’
limitedLogHello() // does nothing

function limit(cb, time) {
    let flag;

    return function () {
        if (flag) {
            //do nothing
        } else {
            cb();
            setTimeout(() => {
                flag = false;
            }, time);
            flag = true;
        }
    }
}