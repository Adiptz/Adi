package il.co.ilrd.exercises.object_oriented_intro;

public class Square extends Rectangle{
	
	double side; 
	
	public Square() {
		//empty
	}
	
	public Square(double side) {
		this.length = side;
		this.width = side;
	}
	
	public Square(double side, String color, boolean filled) {
		super(side, side, color, filled);
	}
	
	public double getSide() {
		return side;
	}
	
	public void setSide(double side) {
		this.side = side;
	}
}
