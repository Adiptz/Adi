/**
 * student name
 * @type {string}
 */
const studentName = 'Adi Peretz';

/**
 *
 * @param birthYear {number} - Year of birth
 * @returns {number} - Your Age
 */
function myAge(birthYear) {
    return (2020 - birthYear);
}


class Person{

    /**
     * Create a new person
     * @param personInfo - Information about the Person
     */
    constructor(personInfo) {

        /**
         * @property {number} age - Person's age
         */
        this.age = personInfo.age;

        /**
         * @property {string} name - Person's name
         */
        this.name = personInfo.name;


    }


    /**
     * @property {Function} greet A greeting with name and age
     * @return void
     */
    greet(){
        console.log(`Hello my nme is ${this.name} and i'm ${this.age}`);
    }
}

/**
 * @example
 * // returns 15
 * globalNS.method1(5, 10);
 * @example
 * // returns 20
 * globalNS.method(5, 15);
 * @returns {Number} Returns the value of x for the equation.
 */
const addition = function (a, b) {
    return a+b ;
};
/**
 * @throws {InvalidArgumentException} FIXME
 */
function divide(a, b) {

}

/**
 * @throws {InvalidArgumentException}
 */
function foo(x) {}


/** @const
 * @type {string}
 */
var RED = 'FF0000';
