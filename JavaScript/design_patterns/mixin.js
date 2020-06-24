// In JavaScript we can only inherit from a single object.
// There can be only one [[Prototype]] for an object.
// A class may extend only one other class.

// a mixin is a class containing methods that can be used by other classes without a need to inherit from it.
// a mixin provides methods that implement a certain behavior.

// mixin
let sayMixin = {
    sayHi() {
        console.log(`Hello ${this.name} !`);
    },
    sayBye() {
        console.log(`Bye ${this.name} !`);
    }
};

class User {
    constructor(name) {
        this.name = name;
    }
}

// There’s no inheritance, but a simple method copying
Object.assign(User.prototype, sayMixin);

// now User can say hi and bye
let testUser = new User("Dude");
testUser.sayHi(); // Hello Dude !
testUser.sayBye(); // Bye Dude !