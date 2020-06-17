package il.co.ilrd.exercises.object_oriented_intro;

public class ShapeTest {
	
	public static void main(String[] args) {

	String traingleStr;
	String circleStr;
	
	Shape traingle = new Shape();
	Shape circle = new Shape("yellow", false);
	
	
	traingleStr = traingle.toString();
	if (!traingleStr.equals("A Shape with color of green and filled")) {
		System.out.println("traingle toString is wrong");
	}
	
	if (traingle.getColor() != "green") {
		System.err.println("Color not init to green");
	}
	
	traingle.setColor("red");
	if (traingle.getColor() != "red") {
		System.err.println("Color didn't change to red");
	}
	
	if (traingle.isFilled() != true) {
		System.err.println("filled not init to true");
	}
	
	traingle.setFilled(false);
	if (traingle.isFilled() != false) {
		System.err.println("filled didn't change to false");
	}
	
	traingleStr = traingle.toString();
	if (!traingleStr.equals("A Shape with color of red and not filled")) {
		System.out.println("traingle toString is wrong");
	}
	
	
	
	if (circle.getColor() != "yellow") {
		System.err.println("Color not init to yellow");
	}
	
	if (circle.isFilled() != false) {
		System.err.println("filled didn't change to false");
	}
	
	circle.setColor("blue");
	circle.setFilled(true);
	
	if (circle.getColor() != "blue") {
		System.err.println("Color didn't change to blue");
	}
	
	if (circle.isFilled() != true) {
		System.err.println("filled didn't change to true");
	}
	
	System.out.println("Great Success");
}
}
