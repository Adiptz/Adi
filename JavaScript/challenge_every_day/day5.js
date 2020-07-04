// this value is execution context (global, function, class or eval)
this.num = 5;

const data = {
    add : function () {
        return this.num + 10; // this will point to data object
    },
    num : 10
};

console.log(this.num); // 5
console.log(data.add()); // 20