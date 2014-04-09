/*
SUM OF DIGITS
CHALLENGE DESCRIPTION:

Given a positive integer, find the sum of its constituent digits.

INPUT SAMPLE:

The first argument will be a path to a filename containing positive integers, one per line. E.g.

23
496
OUTPUT SAMPLE:

Print to stdout, the sum of the numbers that make up the integer, one per line. E.g.

5
19
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[]){
	std::ifstream file;
	file.open(argv[1]);
	while (!file.eof()){
		int num;
		while (file >> num){
			int sum=0;
			while (num != 0){
				sum += num % 10;
				num /= 10;
			}
			std::cout << sum << std::endl;
		}
	}
}