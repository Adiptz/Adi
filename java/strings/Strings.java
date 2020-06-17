package il.co.ilrd.strings;

public class Strings {

	public static boolean isPalindrome(String str) {
		
		int length = str.length();
		int left = 0;
		int right = length - 1;
		
		str = str.toUpperCase();
		
		for (;left < right; ++left, --right) {
				if (str.charAt(left) != str.charAt(right)){
				return false;
			}
		}
		
		return true;
	}
	
	public static void printReverse(String str){
		
		int length = str.length() - 1;
		
		while(0 <= length) {
			System.out.print(str.charAt(length));
			--length;
		}
	}
	
	public static void swapInPlace(StringBuilder s1, StringBuilder s2) {
		
		String tmp = s1.toString();
		
	    s1.replace(0, s1.length(), s2.toString());
		s2.replace(0, s2.length(), tmp);
	}
	
	
	public static void printAllPermutations(String str) {
		Strings.recPermute(str, 0, str.length() - 1);
	}

	// service function for printAllPermutations
	private static void recPermute(String str, int left, int right) 
    { 
        if (left == right) {
            System.out.println(str);
        }
        
        else { 
            for (int i = left; i <= right; i++) { 
                
            	str = swap(str, left, i); 
                
            	recPermute(str, left + 1, right); 
                
            	str = swap(str, left, i); //back to how it was at the start of iteration 
            } 
        } 
    } 
    private static String swap(String str, int i, int j) 
    { 
        char tmp; 
        char[] charArray = str.toCharArray(); 
        
        tmp = charArray[i]; 
        charArray[i] = charArray[j]; 
        charArray[j] = tmp;
        
        return String.valueOf(charArray); 
    } 

}

