// Node.cpp
// tom bailey   1050  31 jan 2011
// Definitions of the Node class methods


#include "Node.h"


Node::Node(Node * parent)
{
	PARENT = parent.getID();
	parent_ = parent;
}

Node::addLeftChild()
{
	leftchild_ = new Node * kid(this);
}

Node::addRightChild()
{
	rightchild_ = new Node * kid(this);
}

Node::addRawE(string e)
{
	RAWE = e;
	ID = hash(RAWE, PARENT);
}

Node::appendRHist(string s)
{
	RHISTH.push_back(s);
}

Node::appendLHist(string s)
{
	LHISTH.push_back(s);
}

// Everything below this is from the original LList so it is probably garbage

Node::~Node()
{}
void Node::showIDs(string parent)
{
	// take parent ID and use to print out all other IDs
	Node * Firstparent = parent_;
	cout << ID;
	while (leftchild_ != NULL)
	{
		// move to the left child
		cout << ID;
	}
}

void Node::showRecords(string id)
{
	// show all values stored at the id
	cout << "ID: " << ID << endl;
	cout << "Parent: " << PARENT << endl;
	cout << "Raw Event: " << RAWE << endl;
	cout << "Right Hash: " << RHASH << endl;
	cout << "Left Hash: " << LHASH << endl;
	cout << "Right Hash History: " << RHISTH << endl;
	cout << "Left Hash History: " << LHISTH << endl;

}

void Node::changeNode(string id, string data)
{
	// change node data, then update the rest
	// go to id
	RAWE = data;
	// change id
	// change hash
	// change hash history
}

void Node::newNode(string data)
{
	// add a new node with the data, and make a new node
}
