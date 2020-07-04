function getName() {
    myName = 'Adi';
    var fullName = 'Adi Peretz';
}

console.log(this.myName); // undefined
getName();

console.log(myName); // Adi
console.log(fullName); // ReferenceError ! var scope only within getName function