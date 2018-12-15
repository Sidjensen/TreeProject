// TreeProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "LinkedList.h"
#include <string>
#include <iostream>
using std::cout;
using std::cin;

void growTree(Node& root, Node* first);
void showID(Node& traversee);
void showRecords(Node& find, string id);
void changeNode(Node& find, string id, string data);
void newNode(Node& parent, string data);
string printOut(vector<string> history);

int main()
{
	string rawdata;
	bool end = false;
	Node* first = new Node();
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
			showID(*first);
		}
		else if (rawdata == "ID")
		{
			string idTemp;
			cout << "Type 'V' to see the entire record of the ID, and type 'U' to update the contents of the ID";
			cin >> rawdata;
			if (rawdata == "V")
			{
				// Show all records of the ID;
				showRecords(*first, idTemp);
			}
			if (rawdata == "U")
			{
				//make the node have new contents, and probably change ID, and all parent stuff
				cout << "Enter new record contents: ";
				cin >> rawdata;
				changeNode(*first, idTemp, rawdata);
			}
		}
		else if (rawdata == "NEW")
		{
			cout << "Enter contents for the record: ";
			cin >> rawdata;
			newNode(*first, rawdata);

			// create new node on tree 
			// Set to null, if first, some random thing for parent, and set Id from the data
			// When new node is added, make parent id, and make new id
		}
	}
	return 0;
}

void growTree(Node& root, Node* first)
{
	if ((root.leftChild() == NULL) && (root.rightChild() == NULL))
	{
		root.addLeftChild(*first);
		root.addRightChild(*first);
	}
	else if (root.leftChild() != NULL)
	{
		growTree(*root.leftChild(), first);
	}
	else if (root.rightChild() != NULL)
	{
		growTree(*root.rightChild(), first);
	}
}

Node& findNextEmpty(Node& traversee)
{
	if (&traversee == NULL)
	{
		return;
	}
	if (&traversee.getID() == NULL)
	{
		return traversee;
	}
	findNextEmpty(*traversee.leftChild());
	findNextEmpty(*traversee.rightChild());
}
Node& findNode(Node& traversee, string ID)
{
	if (&traversee == NULL)
	{
		return;
	}
	if (traversee.getID() == ID)
	{
		return traversee;
	}
	findNode(*traversee.leftChild(), ID);
	findNode(*traversee.rightChild(), ID);
}

void showID(Node& traversee)
{
	while (&traversee != NULL)
	{
		cout << "ID: " << traversee.getID() << endl;
		findNextEmpty(*traversee.leftChild());
		findNextEmpty(*traversee.rightChild());
	}
}

void showRecords(Node& find, string id)
{
	Node& traversee = findNode(find, id);
	cout << "ID: " << traversee.getID() << endl;
	cout << "Parent: " << traversee.parent() << endl;
	cout << "Raw Event: " << traversee.getRawE() << endl;
	cout << "Right Hash: " << traversee.getRhash() << endl;
	cout << "Left Hash: " << traversee.getLhash() << endl;
	cout << "Right Hash History: " << printOut(traversee.getRHist()) << endl;
	cout << "Left Hash History: " << printOut(traversee.getLHist()) << endl;
}

void changeNode(Node& find, string id, string data)
{
	Node& target = findNode(find, id);
	target.addRawE(data);
	// change id
	// change hash
	// change hash history
}

void newNode(Node& parent, string data)
{
	// add a new node with the data, and make a new node
	Node& newNode = findNextEmpty(parent);
	newNode.addRawE(data);
}

string printOut(vector<string> history)
{
	string combination;
	for (int i = 0; i < history.size(); i++)
	{
		combination += history[i];
	}
	return combination;
}
