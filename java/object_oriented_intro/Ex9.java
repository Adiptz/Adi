package il.co.ilrd.exercises.object_oriented_intro;

public class Ex9 {

	public static void main (String[] args) throws ClassNotFoundException {

		Class c = Class.forName(args[0]);
		
		System.out.println(c.getPackage());
		System.out.println(c.toString());
		System.out.println(c.getName());
		System.out.println(c.getTypeName());
		System.out.println(c.isInterface());
		System.out.println(c.isInstance(c.getClass()));
		
		System.out.println("");
		
		Class d = Class.forName(args[1]);
		
		System.out.println(c.getPackage());
		System.out.println(c.toString());
		System.out.println(c.getName());
		System.out.println(c.getTypeName());
		System.out.println(c.isInterface());
		System.out.println(c.isInstance(c.getClass()));
	}
}
