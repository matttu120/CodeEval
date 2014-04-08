/*
MTH TO LAST ELEMENT

CHALLENGE DESCRIPTION:

Write a program to determine the Mth to last element of a list.
INPUT SAMPLE:

The first argument will be a path to a filename containing a series of space delimited characters followed by an integer representing a index into the list (1 based), one per line. E.g.
a b c d 4
e f g h 2
OUTPUT SAMPLE:

Print to stdout, the Mth element from the end of the list, one per line. If the index is larger than the list size, ignore that input. E.g.

a
g

*/
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
	ifstream file;
	string lineBuffer;
	file.open(argv[1]);
	while (!file.eof()){
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue;
		else{
			vector<string> str;
			string spaces = " ";
			int p;
			int q = 0;
			while (q!= string::npos){
				p = q + 1;
				q = lineBuffer.find_first_of(spaces, p);
				str.push_back(lineBuffer.substr(p, q-p));
			}
			int m = atoi(str.back().c_str());
			str.pop_back();
			if (m > str.size())
				continue;
			else {
				cout << str.at(str.size() - m) << endl;
			}
		}
	}
}