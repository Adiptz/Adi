function LikedList(){
    let head = null;
    let size = 0;

    const Node = function (data, next) {
        this.data = data;
        this.next = next;
    };

    // return all publics
    return {
        isEmpty : function(){
            return (head === null);
        },

        pushFront : function (data) {
            head = new Node(data, head);
            size += 1;
        },

        popFront : function () {
            if (head === null) {
                throw ('Can not pop element from an empty list');
            }

            const dataToRemove = head.data;
            head = head.next;
            size -= 1;
            return dataToRemove;
        },

        [Symbol.iterator] : function() {
            let iterator = head;

            return {
                next: function () {
                    if (null !== iterator) {
                        const data = iterator.data;
                        iterator = iterator.next;

                        return {value: data, done: false};
                    }
                    return {done: true};
                }
            }
        },

        size : function () {
            // return size;
            let counter = 0;

            for (const element of this) {
                ++counter;
            }

            return counter;
        }
    }
}

let myList = new LikedList();
console.log('true : ' + myList.isEmpty());
console.log('0 : ' + myList.size());

myList.pushFront(5);
myList.pushFront(4);
myList.pushFront(3);
myList.pushFront(2);
myList.pushFront(1);

console.log('false : ' + myList.isEmpty());
console.log('5 : ' + myList.size());

console.log('1 : ' + myList.popFront());
console.log('2 : ' + myList.popFront());
console.log('3 : ' + myList.popFront());
console.log('4 : ' + myList.popFront());
console.log('5 : ' + myList.popFront());

console.log('true : ' + myList.isEmpty());
console.log('0 : ' + myList.size());

myList.popFront();