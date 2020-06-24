// First we start using a anonymous closure.
// Next, export our modules - assigns the module to a variable
// that we can use to call our modules methods.

let myModule = (function() {
    'use strict';

    let publicProperty = 'I am a public property';

    // JavaScript does not have a private keyword by default
    // using closures we can create private methods and private state.
    // Because our private properties are not returned they are not available outside of out module.
    let _privateProperty = 'Hello World';

    function _privateMethod() {
        console.log(_privateProperty);
    }

    // create a public method for our module to call.
    function publicMethod() {
        _privateMethod();
    }
    // To expose this method to code outside our module :
    // we return an Object with the methods defined.
    // The Revealing Module Pattern is one of the most popular ways of creating modules.
    // Using the return statement we can return a object literal
    // that ‘reveals’ only the methods or properties we want to be publicly available.
    return {
        publicMethod: publicMethod,
        publicProperty : publicProperty,
        }
     // Benefit : we can quickly see what is publicly available for use.

}());

myModule.publicMethod();                    // outputs 'Hello World'
console.log(myModule.publicProperty);       // outputs 'I am a public property'
// console.log(myModule._privateProperty);     // is undefined protected by the module closure
// myModule._privateMethod();                  // is TypeError protected by the module closure


//Linked List as module :

let myList = (function () {
    'use strict';

    let _head = null;
    let _size = 0;

    function _node(data, next) {
         return {data, next};
    }

    function pushFront(data) {
        _head = _node(data, _head);
        _size += 1;
    }

    function popFront() {
        let newHead = _head.next;
        let currentData = _head.data;
        _head = newHead;
        _size -= 1;

        return currentData;
    }

    function sizeList() {
        return _size;
    }

    return {
        pushFront : pushFront,
        popFront: popFront,
        sizeList : sizeList,
    }
}());

myList.pushFront(5);
console.log(myList.sizeList);