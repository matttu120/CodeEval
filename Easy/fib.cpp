/*
FIBONACCI SERIES
CHALLENGE DESCRIPTION:

The Fibonacci series is defined as: F(0) = 0; F(1) = 1; F(n) = F(n-1) + F(n-2) when n>1. Given a positive integer 'n', print out the F(n).

INPUT SAMPLE:

The first argument will be a path to a filename containing a positive integer, one per line. E.g.

5
12
OUTPUT SAMPLE:

Print to stdout, the fibonacci number, F(n). E.g.

5
144
*/
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int fib(int n){
	if (n < 2)
		return n;
	else
		return (fib(n - 1) + fib(n - 2));
}

int main(int argc, char *argv[]){
	ifstream file;
	string line;

	file.open(argv[1]);
	while (!file.eof()){
		getline(file, line);
		if (line.length() == 0)
			continue;
		else {
			int input;
			input = atoi(line.c_str());
			cout << fib(input) << endl;
		}
	}
}