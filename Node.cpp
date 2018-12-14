// TreeProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "LinkedList.h"
#include <string>
#include <iostream>
using std::cout;
using std::cin;

void addNode();
string hash(string a, string b);
void growTree(Node& root);
void showIDs(Node * parent);
void showRecords(string id);
void changeNode(string id, string data);
void newNode(string data);
string printOut(vector<string> history);

int main()
{
	string rawdata;
	bool end = false;
	Node first = new Node();
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
			showIDs(first);
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
		else if (rawdata == "NEW")
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

string hash(string a, string b)
{
	// make a h*cking hash
}

void growTree(Node& root)
{
	if ((root.leftChild() == NULL) && (root.rightChild() == NULL))
	{
		root.addLeftChild();
		root.addRightChild();
	}
	else if (root.leftChild() != NULL)
	{
		growTree(*root.leftChild());
	}
	else if (root.rightChild() != NULL)
	{
		growTree(*root.rightChild());
	}
}
void Node::showIDs(Node * parent)
{
	// take parent ID and use to print out all other IDs
	Node * Firstparent = parent;
	cout << ID;
	while (parent.leftChild() != NULL)
	{
		// move to the left child
		cout << ID;
	}
}

void Node::showRecords(string id)
{
	// show all values stored at the id
	cout << "ID: " << getID() << endl;
	cout << "Parent: " << parent() << endl;
	cout << "Raw Event: " << getRawE() << endl;
	cout << "Right Hash: " << getRhash() << endl;
	cout << "Left Hash: " << getLhash() << endl;
	cout << "Right Hash History: " << printOut(getRHist()) << endl;
	cout << "Left Hash History: " << printOut(getLHist()) << endl;

}

void Node::changeNode(string id, string data)
{
	// change node data, then update the rest
	// go to id
	addRawE(data);
	// change id
	// change hash
	// change hash history
}

void Node::newNode(string data)
{
	// add a new node with the data, and make a new node
	Node temp = Node();
	addRawE(data);
}

string Node::printOut(vector<string> history)
{
	string combination;
	for (int i = 0; i < history.size(); i++)
	{
		combination += history[i];
	}
	return combination;
}
