/*SUM OF PRIMES
CHALLENGE DESCRIPTION:

Write a program to determine the sum of the first 1000 prime numbers.

INPUT SAMPLE:

There is no input for this program.

OUTPUT SAMPLE:

Your program should print the sum on stdout, i.e.

3682913*/
#include <iostream>
#include <math.h>
using namespace std;

//Checks if the input i is prime by attempting to divide all numbers less than i evenly.
bool isPrime(int a){
	int x = sqrt(a);
	for (int b = 2; b < a; b++){
		if (a%b == 0)
			return false;
		if (b > x)
			return true;
	}
	return true;
}

int main(){
	int sum = -1; // Remove 1 for "1" not being prime
	for (int i = 1, c = 0; c <= 1000; i++){
		if (isPrime(i)){
			sum += i;
			c++;
		}
	}
	cout << sum << endl;
	return 0;
}