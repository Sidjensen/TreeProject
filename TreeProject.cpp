// TreeProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace::std;

int main()
{
	int id, parent, lHash, rHash, lHist, rHist;
	string rawdata;
	bool end = false;
	while (end == false)
	{
		cout << "Enter 'Q' to quit the program, 'S' to show all tree ID's, 'ID' to manipulate an ID,  or enter a piece of raw data: ";
		cin >> rawdata;
		if (rawdata == "Q")
		{
			end = true;
		}
		else if (rawdata == "S")
		{
			//show tree as a set of ID values
		}
		else if (rawdata == "ID")
		{
			string idTemp;
			cout << "Type 'V' to see the entire record of the ID, and type 'U' to update the contents of the ID";
			cin >> idTemp;
			if (idTemp == "V")
			{
				// Show all records of the ID;
			}
			if (idTemp == "U")
			{
				//make the node have new contents, and probably change ID, and all parent stuff
			}
		}
		else
		{
			// create new node on tree 
			// Set to null, if first, some random thing for parent, and set Id from the data
			// When new node is added, make parent id, and make new id
		}
	}
    return 0;
}

int hash(string rawdata)
{
	// convert to aski? then back????
	int temp = 0;
	temp = rawdata.length();
	temp = temp * 37;
	temp = temp % 10;
}
