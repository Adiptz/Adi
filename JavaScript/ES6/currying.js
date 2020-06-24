function multiply1(a, b, c) {
    return a * b * c;
}

// C U R R Y I N G
function multiply(a) {
    return (b) => {
        return (c) => {
            return a * b * c
        }
    }
}

const multFive = multiply(5);
const result = multFive(2)(3);
console.log(result);


