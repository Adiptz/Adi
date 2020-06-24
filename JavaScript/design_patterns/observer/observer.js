class Observable {

    colors = ['gray', 'blue', 'red', 'yellow', 'orange'];
    // each instance of the Observer class
    // starts with an empty array of things (observers)
    // that react to a state change
    constructor() {
        this.observers = [];
    }

    // add the ability to subscribe to a new object / DOM element
    // update all subscribed objects / DOM elements

    // essentially, add something to the observers array
    subscribe(f) {
        this.observers.push(f);
    }
    // and pass some data to each of them
    notifyAll() {
        let currColor = this.colors[Math.floor(Math.random() * Math.floor(this.colors.length))];

        for (let observer of this.observers){
            observer.update(currColor);
         }
    }
}

class Observer {

    constructor(elementIndex) {
        this.element = document.getElementById('obs' + elementIndex);
    }

    update(color) {
        this.element.style.background = color;
    }
}


const observer1 = new Observer(1);
const observer2 = new Observer(2);
const observer3 = new Observer(3);

// instantiate new Observer class
const mainObserver = new Observable();

// subscribe to some observers
mainObserver.subscribe(observer1);
mainObserver.subscribe(observer2);
mainObserver.subscribe(observer3);

document.getElementById("button_obs").addEventListener('click', e => {
    mainObserver.notifyAll();
});

