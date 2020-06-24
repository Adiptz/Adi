
class Animal {
    constructor() {
        if (new.target === Animal) {
            throw new Error("DO not instanciate abstract class");
        }
        this.numOfLegs = 4;
    }

}

function showNumOfLegs(someClass) {
    let instance = new someClass();
    console.log(instance.numOfLegs);
}


class Dog extends Animal {
    constructor() {
        super();
    }
}

// const a = new Animal();
const b = new Dog();
console.log(b.numOfLegs);