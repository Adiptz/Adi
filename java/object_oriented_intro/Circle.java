package il.co.ilrd.exercises.object_oriented_intro;

public class Circle extends Shape {
	
	double radius;
	
	// default constructor 
	public Circle() {
		radius = 1.0;
	}
	
	public Circle(double radios) {
		this.radius = radios;
	}

	public Circle(double radios, String color, boolean filled) {
		super(color, filled);
		this.radius = radios;
	}
	
	public void setRadios(double radios) {
		this.radius = radios;
	}
	
	public double getRadius() {
		return radius;
	}
	@Override
	public double getArea() {
		return radius * radius * Math.PI;
	}
	
	@Override
	public double getPerimeter() {
		return 2 * Math.PI * radius;
	}
	
	@Override
	public String toString() {
		return "A Circle with radius = " + radius + ", wich is subclass of" + super.toString();
	}

}

