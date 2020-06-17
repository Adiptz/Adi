package il.co.ilrd.exercises.object_oriented_intro;

public class Ex1Subclass extends Ex1Superclass {

	static {
		System.out.println("Subclass static block");
	}
	
	{
		System.out.println("Subclass non-static");
	}
	public Ex1Subclass() {
		System.out.println("Subclass Consturctor");
	}

	public static void main (String[] args)
	{
		Ex1Subclass su = new Ex1Subclass();
	}
}


