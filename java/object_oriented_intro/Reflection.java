package il.co.ilrd.exercises.object_oriented_intro;
import java.lang.reflect.Method; 

public class Reflection {

		static public void whatsMyModify() {}
		
		public static void main(String[] args) {
			
			//outer class (simple)
			System.out.println(new Reflection().getClass().getSuperclass().toString());
			
			Class objModifier = new Reflection().getClass();
			
			Method[] method = objModifier.getMethods();
			
			System.out.println(method[0].toString());
			
		}
}
