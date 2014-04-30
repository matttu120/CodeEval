/*
PRIME PALINDROME
CHALLENGE DESCRIPTION:

Write a program to determine the biggest prime palindrome under 1000.

INPUT SAMPLE:

There is no input for this program.

OUTPUT SAMPLE:

Your program should print the largest palindrome on stdout, i.e.

929
*/

public class PrimePalindrome{

	public static boolean isPrime (int a){
		int b;
		for (b=2;b<a;b++){
			if (a%b==0) 
				return false;
		}
		return true;
	}
	
	public static boolean isPalindrome(String str) {
	   int length = str.length();
	   int mid = length/2;
	   for (int a=0;a<mid;a++){
		   if (str.charAt(a) != str.charAt(length-1-a))
			   return false;
	   }
	   return true;
	}
	
	public static void main(String[] args) {
		int a;
		int result=0;
		for (a=2;a<1000;a++)
			if (isPrime(a) && isPalindrome(Integer.toString(a)))
				result = a;
		System.out.print(result);
	}
}
