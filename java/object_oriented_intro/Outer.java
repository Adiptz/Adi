package il.co.ilrd.exercises.object_oriented_intro;

class Outer {

	int intOuter = 3;
	private int privateOuter = 5;
	static int intStatic = 4;
	
	int outerMethod() {
		System.out.println("Outer method");
		return 3;
	}
	
	 class Inner {
		int innerToOuterInt = intOuter;
		int innerToOuterStatic = intStatic;
		int innerToOuterPrivate = privateOuter;
		
		void innerMethod() {}
		
		void foo() {
			Outer.this.outerMethod();
		}
	}
	
	static class Nested {
		int nestedToOuterInt = Outer.intStatic;
		
	}
	

	public static void main (String arg[]) {
	
		System.out.println("VOVA THE KING");
	
	Outer.Inner objInner = new Outer().new Inner(); // create inner object
	Outer.Nested objNested = new Nested();
	Outer.Inner objAnonymous = new Outer().new Inner() {
		@Override
		void innerMethod() {
			System.out.println("Anonymous Class");
		}};

		
	System.out.println(objNested.nestedToOuterInt);
	objInner.foo();
	objAnonymous.innerMethod();
}}

