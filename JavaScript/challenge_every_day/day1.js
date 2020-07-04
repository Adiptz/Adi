var name = ' Java';
this.name = 'Script';
console.log(name); // Script

let fullname = 'Adi Peretz';
this.fullname = 'Other Name'

console.log(fullname); // Adi Peretz
console.log(this.fullname); // Other Name

// var create a property on the global object unlike let

// var Variables declared are scoped to the immediate function body
// let variables are scoped to the immediate enclosing block {}
