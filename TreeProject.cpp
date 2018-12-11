// TreeProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace::std;

int main()
{
	int id, parent, lHash, rHash, lHist, rHist;
	string rawdata;
	cout << "enter a piece of raw data: ";
	cin >> rawdata;
	// Set to null, if first, some random thing for parent, and set Id from the data
	// When new node is added, make parent id, and make new id
    return 0;
}

int hash(string rawdata)
{
	int temp = 0;
	temp = rawdata.length();
	temp = temp * 37;
	temp = temp % 10;
}
