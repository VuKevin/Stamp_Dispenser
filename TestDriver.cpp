// Programmer Name: Kevin Vu
// Date: 1/28/2016
// Laserfiche® Coding Challenge: Stamp Dispenser
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <sstream>
#include <fstream> // Allows methods for opening, closing, and reading files
#include "StampDispenser.h"
using namespace Laserfiche;
using namespace std; 

int main(int argc, char *argv[])
{
	ifstream fin;
	const int MAX_CHARS_PER_LINE = 512;
	char buf[MAX_CHARS_PER_LINE];
	argv[1] = "stampDenom.txt";
	argc++;
	fin.open(argv[1]);
	if (!fin.good())
	{
		cerr << "Error Opening File: " << argv[1] << endl;
		return 2;
	}

	int stampDenominations[7]; // Edit size here
	int i = 0;
	while (!fin.eof())
	{
		fin.getline(buf, MAX_CHARS_PER_LINE);
		int num = stoi(buf); 
		stampDenominations[i] = num;
		i++;
	}
	// int stampDenominations[] = { 90, 30, 24, 10, 6, 2, 1 };
	StampDispenser stampDispenser(stampDenominations, 7);
	// assert(stampDispenser.CalcNumStampsToFillRequest(18) == 3);
	cerr << "The collection of stamp Denominations consist of: " << '\n';
	for (int index = 0; index < 7; index++)
	{
		cerr << stampDenominations[index] << '\n';
	}
	int userRequest;
	cerr << '\n' << "Please enter your request: ";
	cin >> userRequest;
	int min = stampDispenser.CalcNumStampsToFillRequest(userRequest);
	cerr << "The minimum number of stamps we can dispense for you is: " << min << '\n';
}
