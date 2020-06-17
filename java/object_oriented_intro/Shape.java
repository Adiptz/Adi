package il.co.ilrd.exercises.object_oriented_intro;

public class Shape {

		String color;
		boolean filled;
		
		Shape(){
			this.color = "green";
			this.filled = true;
		}
		
		Shape(String color, boolean filled){

			this.color = color;
			this.filled = filled;
		}

		 public void setColor(String color) {
			 this.color = color;
		 } 
		 public String getColor() {
			 return this.color;
		 }
		 
		 public void setFilled(boolean filled) {
			 this.filled = filled;
		 } 
		
		 public boolean isFilled() {
			 return this.filled;
		 }

		 public String toString(){
			 
			 String filledCheck;
			
			 if (this.filled) {
				 filledCheck = "filled";
			 }
			 else {
				 filledCheck = "not filled";
			 }
			 
			 String ret_str = "A Shape with color of " + this.color + " and " + filledCheck;
			 
			 return ret_str;
		 }
		 
		 public double getArea() {
				return 0;
			}
			
			public double getPerimeter() {
				return 0;
			}
}
