// TreeProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "LinkedList.h"
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using Node::Node;

void addNode();
string hash(string a, string b);
void growTree(* node root);
int main()
{
	string rawdata;
	bool end = false;
	while (end == false)
	{
		cout << "Enter 'Q' to quit the program, 'S' to show all tree ID's, 'ID' to manipulate an ID,  or enter NEW piece of raw data: ";
		cin >> rawdata;
		if (rawdata == "Q")
		{
			end = true;
		}
		else if (rawdata == "S")
		{
			//show tree as a set of ID values
			showIDs();
		}
		else if (rawdata == "ID")
		{
			string idTemp;
			cout << "Type 'V' to see the entire record of the ID, and type 'U' to update the contents of the ID";
			cin >> idTemp;
			if (idTemp == "V")
			{
				// Show all records of the ID;
				showRecords();
			}
			if (idTemp == "U")
			{
				//make the node have new contents, and probably change ID, and all parent stuff
				changeNode();
			}
		}
		else if(rawdata == "NEW")
		{
			
			newNode();
			
			// create new node on tree 
			// Set to null, if first, some random thing for parent, and set Id from the data
			// When new node is added, make parent id, and make new id
		}
	}
    return 0;
}

void addNode()
{
	
}

int hash(string a, string b)
{
	// make a h*cking hash
}
void growTree(* node root)
{
	if (root.leftNode == null) && (root.rightNode == null)
	{
		root.addLeftChild;
		root.addRightChild:
	}
	else if (root.leftNode != null
	{
		growTree(root.leftnode);
	}
	else if (root.rightNode != null)
	{
		growTree(root.rightNode);
	}
)
