package il.co.ilrd.exercises.object_oriented_intro;

public class SubPoly extends Polymorphic {
	
	SubPoly() {
		System.out.println("Sub Constructor");
	}
	
	public void polyMethod() {
		System.out.println("After Change");
	}

	// Why not printing "Sub Constructor" ???
	public static void main (String[] args) {
		Polymorphic test = new SubPoly();
	}
}
