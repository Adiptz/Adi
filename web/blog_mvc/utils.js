export function createElement(tag, className, idName) {
    const element = document.createElement(tag);
    if (className) {
        element.className = className;
    }

    else if (idName) {
        element.id = idName;
    }

    return element;
}

// Retrieve an element from the DOM
export function getElement(selector) {
    return document.querySelector(selector);
}

export function debounce(func, wait, immediate) {
    let timeout;
    return function() {
        const context = this, args = arguments;

        let later = function() {
            timeout = null;
            if (!immediate) {
                func.apply(context, args);
            }
        };

        let callNow = immediate && !timeout;
        clearTimeout(timeout);
        timeout = setTimeout(later, wait);

        if (callNow) {
            func.apply(context, args);
        }
    };
}