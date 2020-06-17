package il.co.ilrd.strings;

public class Test {

	public static void main(String[] args) {
		// Palindrome Test
		assert (true == Strings.isPalindrome("a"));
		assert (true == Strings.isPalindrome("aba"));
		assert (true == Strings.isPalindrome("Aba"));
		assert (false == Strings.isPalindrome("abac"));
		assert (false == Strings.isPalindrome("ab"));
		
		// Reverse Test
		Strings.printReverse("VOVA THE QUEEN!");
		
		// Swap In Place Test
		StringBuilder s1 = new StringBuilder("Vova");
		StringBuilder s2 = new StringBuilder("Queen");
		
		Strings.swapInPlace(s1, s2);

		System.out.println();
		System.out.println(s1);
		System.out.println(s2);
		
		// Permutation Test
//		Strings.printAllPermutes("ABC");
	}

}
