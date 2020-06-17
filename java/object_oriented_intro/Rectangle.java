package il.co.ilrd.exercises.object_oriented_intro;

public class Rectangle extends Shape {
	
	double width;
	double length;
	
	public Rectangle() {
		width = 1.0;
		length = 1.0;
	}

	public Rectangle(double width, double length) {
		this.width = width;
		this.length = length;
	}
	
	public Rectangle(double width, double length, String color, boolean filled) {
		this.width = width;
		this.length = length;
		this.color = color;
		this.filled = filled;
	}

	public double getWidth() {
		return width;
	}

	public double getLength() {
		return length;
	}
	
	public void setWidth(double width) {
		this.width = width;
	}
	
	public void setLength(double length) {
		this.length = length;
	}
	
	@Override
	public double getArea() {
		return width * length;
	}
	
	@Override
	public double getPerimeter() {
		return ((2 * width) + (2 * length));
	}
	
	@Override
	public String toString() {
		return "A Rectangle with width = " + width + " and length = " + length + " wich is subclass of" + super.toString();
	}
}
