package il.co.ilrd.linked_list;

public class Test {

	public static void main(String[] args) {
		
	LinkedList test = new LinkedList();
	Integer a = 1;
	Integer b = 2;
	Integer c = 3;
	
	System.out.println("true : " + test.isEmpty());
	System.out.println("0 :" + test.size());
	
	test.pushFront(a);
	test.pushFront(b);
	test.pushFront(c);

	System.out.println("1 : " + test.find(a).next());
	System.out.println("2 : " + test.find(b).next());
	System.out.println("3 : " + test.find(c).next());
	
	System.out.println("false : " + test.isEmpty());
	System.out.println("3 : " + test.size());

	test.popFront();
	
	System.out.println("false : " + test.isEmpty());
	System.out.println("2 : " + test.size());
	
	test.popFront();
	test.popFront();
	
	System.out.println("true : " + test.isEmpty());

	test.popFront();
	test.popFront();
	test.popFront();



}
}
