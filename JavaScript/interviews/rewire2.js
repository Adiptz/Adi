for (var i = 0; i < 10 ; i++ ) {
  setTimeout(function() {
  	console.log(i)
  }, 10)
}

function fooCreate () {
    let counter = 0;

    return function () {
        console.log(counter);
        ++counter;
    }
}

const foo = fooCreate();
