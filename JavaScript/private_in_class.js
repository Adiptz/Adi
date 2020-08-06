

    class NewFeature {
        _private = 'not really';
        #realPrivate = true;

        constructor() {
            this.name = 'private class fields using a hash #'
        }
    }

    let instance = new NewFeature();
    console.log(instance._private); // not really
    console.log(instance.#realPrivate);


    // Adi - Web Developer
