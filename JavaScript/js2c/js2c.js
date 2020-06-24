var obj = new Object();
var obj2 = new Object();
console.log(obj); // {}
console.log(obj.valueOf()); // {}
console.log(obj.isPrototypeOf(obj2)); // false
console.log(Object.prototype.isPrototypeOf(obj)); // true
console.log(obj.hasOwnProperty('toString')); // false
console.log(obj.hasOwnProperty('name')); // false
obj.name = 'anyvision';
console.log(obj.hasOwnProperty('name')); // true

function Shape(color) {
  this.color = color;
}
Shape.prototype = {
  constructor: Shape,
  printColor: function() {
    console.log(this.color);
  },
  toString: function() {
    return "[Shape " + this.color + "]";
  }
};
var shape1 = new Shape("red");
var shape2 = new Shape("green");
console.log(shape1 instanceof Shape);
console.log(shape1 instanceof Object);
console.log(shape1.constructor === Shape);
console.log(shape1.constructor === Object);
Shape.prototype.printHi = function() {
  console.log("Hi");
};
shape1.printHi();
function Rectangle(length, width) {
  this.length = length;
  this.width = width;
  Shape.call(this, "black"); /*what happens if we don't call it?*/
  this.printColor();
}
Rectangle.prototype = Object.create(Shape.prototype);
Rectangle.prototype.constructor = Rectangle;
Rectangle.prototype.getArea = function() {
  return this.length * this.width;
}
Rectangle.prototype.toString = function() {
  return "[Rectangle " + this.length + "x" + this.width + "]";
}
/* think about it after --> why is it bad that square inherits from rectangle */
function Square(size) {
  this.length = size;
  this.width = size;
}
Square.prototype = Object.create(Rectangle.prototype);
Square.prototype.constructor = Square;
var rectangle1 = new Rectangle(5,10);
var square1 = new Square(6);
console.log(rectangle1.getArea());
console.log(square1.getArea());
console.log(rectangle1.toString());
console.log(square1.toString());
Object.defineProperty(square1, "name", {
  enumerable: false
});
console.log(square1.propertyIsEnumerable("name"));
/* Is it possible ? What happens?
Object.defineProperty(square1, "name", {
enumerable: true
});*/