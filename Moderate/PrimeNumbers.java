
/*
PRIME NUMBERS
CHALLENGE DESCRIPTION:

Print out the prime numbers less than a given number N. For bonus points your solution should run in N*(log(N)) time or better. You may assume that N is always a positive integer.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Each line in this file is one test case. Each test case will contain an integer n < 4,294,967,295. E.g.

10
20
100
OUTPUT SAMPLE:

For each line of input, print out the prime numbers less than N, in ascending order, comma delimited. (There should not be any spaces between the comma and numbers) E.g.

2,3,5,7
2,3,5,7,11,13,17,19
2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class PrimeNumbers {
	
    public static void main (String[] args) throws IOException{
    	File file = new File(args[0]);
    	BufferedReader in = new BufferedReader(new FileReader(file));
    	String line;
    	while ((line = in.readLine()) != null) {
    		int max = Integer.parseInt(line);
    		int n=2;
    		StringBuilder result = new StringBuilder();
    		result.append(n);
    		while (n != max){
    			if (n%2 != 0){
    				if (isPrime(n))
    					result.append(","+ n);
    			}
    			n++;
    		}
			System.out.println(result);
    	}
    	in.close();
    }
    
    public static boolean isPrime (int a){
    	double x = Math.sqrt(a);
    	for (int b = 2; b<a; b++){
    		if (a%b==0)
    			return false;
    		if (b>x)
    			return true;
    	}
    	return true;
    }
}
