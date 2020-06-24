function Outer() {
    // local variable
    const a = 3;
    console.log('local variable of outer ' + a);

    function Inner() {
        console.log("Inner")

    }

    Inner();
}

Outer();
Inner();