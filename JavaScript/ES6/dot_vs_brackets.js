const obj = {
    '1property' : 'bracket only',
    'property2' : 'dot and bracket',
    '_3thProperty' :  'dot and bracket',
    'property with space' : 'bracket only',
    openToWork : true
};

let varProperty = 'openToWork';

console.log(
    obj["1property"],
    obj.property2, obj['property2'],
    obj._3thProperty, obj["_3thProperty"],
    obj['property with space'],
    obj.openToWork, obj[varProperty]
)

// Adi - Web Developer

