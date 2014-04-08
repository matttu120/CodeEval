/*
﻿
﻿THIS SOLUTION DOES NOT WORK.
﻿
﻿
DISCOUNT OFFERS
CHALLENGE DESCRIPTION:
Our marketing department has just negotiated a deal with several local merchants that will allow us to offer exclusive discounts on various products to our top customers every day. The catch is that we can only offer each product to one customer and we may only offer one product to each customer. 

Each day we will get the list of products that are eligible for these special discounts. We then have to decide which products to offer to which of our customers. Fortunately, our team of highly skilled statisticians has developed an amazing mathematical model for determining how likely a given customer is to buy an offered product by calculating what we call the "suitability score" (SS). The top-secret algorithm to calculate the SS between a customer and a product is this: 

1. If the number of letters in the product's name is even then the SS is the number of vowels (a, e, i, o, u, y) in the customer's name multiplied by 1.5. 
2. If the number of letters in the product's name is odd then the SS is the number of consonants in the customer's name. 
3. If the number of letters in the product's name shares any common factors (besides 1) with the number of letters in the customer's name then the SS is multiplied by 1.5. 

Your task is to implement a program that assigns each customer a product to be offered in a way that maximizes the combined total SS across all of the chosen offers. Note that there may be a different number of products and customers. You may include code from external libraries as long as you cite the source.
*/

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

const int MAX = 100;
int n;
int score[MAX][MAX];
int matched[MAX];
int loc1[MAX], loc2[MAX];
bool search1[MAX], search2[MAX];


using namespace std;

//Checks if the current character is a letter.
bool isLetter (char c){
	if ((c >='a' && c <='z') || (c >='A' && c <='Z'))
		return true;
	else 
		return false;
}

//Checks if the current character is a vowel.
bool isVowel(char c){
	string vowels = "aeiouyAEIOUY";
	if (vowels.find(c) != string::npos)
		return true;
	else 
		return false;
}

//Counts the number of letters in an element
int letterCount (string s){
	int count = 0;
	for (int i = 0; i < s.size(); i++){
		if (isLetter(s[i])) 
			count++;
	}
	return count;
}

//Counts the number of vowels in an element
int vowelCount(string s){
	int count = 0;
	for (int i = 0; i < s.size(); i++){
		if (isVowel(s[i]))
			count++;
	}
	return count;
}

//Checks to see if there are common factors between two numbers.
int findCommonFactor(int a, int b){
	int n = min(a, b);
	for (int i=2; i<=n; i++){
		if (a%i==0 && b%i==0)
			return i;
	}
	return 1;
}	

//This function computes the "Suitability Score" between a customer and a product.
double findSScore(string customer, string product){
	double result = 0;

	//Checks for even numbers or odd numbers (cases 1 and 2)
	if (letterCount(product) % 2 == 0){
		result = (double)vowelCount(customer) * 1.5;
	}
	else 
		result = letterCount(customer) - vowelCount(customer);

	//Check for factors (case 3)
	if (findCommonFactor(letterCount(product), letterCount(customer)) > 1){
		result *= 1.5;
	}
	return result;
}

//This function parses the lines as the come in. It starts by splitting the line at the customer/product divider, then dividing each substring into individual elements.
void parse(vector<string> &customer, vector<string> &product, string buff){
	int pos = buff.find(';'); // finds the customer/product split point in a line
	string customerString = buff.substr(0, pos);
	string productString = buff.substr(pos + 1);

	pos = customerString.find(',');
	while (pos != string::npos){
		customer.push_back(customerString.substr(0, pos));
		customerString = customerString.substr(pos + 1);
		pos = customerString.find(',');
	}
	customer.push_back(customerString);


	pos = productString.find(',');
	while (pos != string::npos){
		product.push_back(productString.substr(0, pos));
		productString = productString.substr(pos + 1);
		pos = productString.find(',');
	}

	product.push_back(productString);
}

//This function checks if the path has been searched already. This is used to break out of the infinite loop, as we don't need to re-check paths that we've been down already.
bool searchCheck(int a){
	search1[a] = true;
	for (int b = 0; b < n; b++)
		if (!search2[b] && loc1[a] + loc2[b] == score[a][b]){
			search2[b] = true;
			if (matched[b] == -1 || searchCheck(matched[b])){
				matched[b] = a;
				return true;
			}
		}
	return false;
}
//The fun part! This is where we find and keep tabs on all the maximum combinations in a line. 
double getMaxSS(){
	int i, j;
	for (i = 0; i < n; i++){
		loc1[i] = -0x1FFFFFFF; //Sets loc1 to the absolute minimum possible value. 
		loc2[i] = 0;
		for (j = 0; j < n; j++){
			if (loc1[i] < score[i][j])
				loc1[i] = score[i][j];
		}
	}
	//Sets all values in matched[] to -1, which acts as a flag for our search checks.
	for (int x = 0; x < sizeof(matched); x++)
		matched[x] = -1;
	for (int a = 0; a < n; a++){
		while (1){
			for (int x = 0; x < sizeof(search1); x++)
				search1[x] = 0;
			for (int x = 0; x < sizeof(search2); x++)
				search2[x] = 0;
			//Breaks the loop if we find that we've searched every combination.
			if (searchCheck(a))
				break;
			int save = 0x7FFFFFFF; // Sets save to the maximum possible value. Initiated as a placeholder.
			for (i = 0; i < n; i++){
				if (search1[i]){
					for (j = 0; j < n; j++){
						if (!search2[j])
							save = min(loc1[i] + loc2[j] - score[i][j], save);
					}
				}
			}
			//This part determines whether to update the values saved. If a location has been searched, and the value has been  the value in the location is adjusted accordingly. 
			for (i = 0; i < n; i++){
				if (search1[i]){
					loc1[i] = loc1[i] - save;
				}
				if (search2[j]){
					loc2[i] = loc2[i] + save;
				}
			}
		}
	}
	//This final part updates the maxSS for the line with optimized matches.
	double maxSS = 0.00;
	for (i = 0; i < n; i++){
		maxSS = maxSS + score[matched[i]][i];
		//cout << maxSS << endl;
	}
	return maxSS;
}

int main(int argc, char *argv[]){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()){
		getline(file, lineBuffer);
		if (lineBuffer.empty())
			continue; //ignore all empty lines
		else{
			vector<string> cust;
			vector<string> prod;

			parse(cust, prod, lineBuffer);
			

			//Get the SScore for all customer/product combinations for the line
			vector<vector<double> > table(cust.size(), vector<double>(prod.size()));
			for (int i = 0; i < cust.size(); i++){
				for (int j = 0; j < prod.size(); j++){
					table[i][j] = findSScore(cust[i], prod[j]);
					//cout << table[i][j] << endl; 
				}
			}

			//Populates and squares a table, adding 0's where necessary. This has no impact on the SS's of the existing cells.
			n = max(table.size(), table[0].size());
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					if (i >= table.size())
						score[i][j] = 0;
					else if (j >= table[0].size())
						score[i][j] = 0;
					else
						score[i][j] = table[i][j] * 100;
					//cout << score[i][j] << endl;
				}
			}
			cout << fixed << setprecision(2) << getMaxSS() / 100 << endl;
		}
	}
}
