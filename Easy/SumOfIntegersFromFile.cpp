/*
SUM OF INTEGERS FROM FILE
CHALLENGE DESCRIPTION:

Print out the sum of integers read from a file.

INPUT SAMPLE:

The first argument to the program will be a path to a filename containing a positive integer, one per line. E.g.

5
12
OUTPUT SAMPLE:

Print out the sum of all the integers read from the file. E.g.

17
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]){
	ifstream file;
	string line;
	int sum = 0;
	file.open(argv[1]);
	while (!file.eof()){
		getline(file, line);
		if (line.length() == 0)
			continue;
		else {
			int input = 0;
			input = atoi(line.c_str());
			sum += input;
			}
	}
	cout << sum << endl;
}