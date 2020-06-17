package il.co.ilrd.exercises.object_oriented_intro;

public class Ex1Superclass {
	
	static {
		System.out.println("Superclass static block");
	}
	
	{
		System.out.println("Super non-static");
	}
	
	public Ex1Superclass(){
	 System.out.println("Superclass Constructor");
	}

}
