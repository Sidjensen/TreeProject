// Node.cpp
// tom bailey   1050  31 jan 2011
// Definitions of the Node class methods


#include "Node.h"


Node::Node(Node * parent)
{
	PARENT = parent.getID();
	parent_ = parent;
}

Node::void addLeftChild()
{
	leftchild_ = new Node * kid(this);
}

Node::void addRightChild()
{
	rightchild_ = new Node * kid(this);
}

Node::void addRawE(string e)
{
	RAWE = e;
	ID = hash(RAWE, PARENT);
}

Node::void appendRHist(string s)
{
	RHISTH.push_back(s);
}

Node::void appendLHist(string s)
{
	LHISTH.push_back(s);
}

Node::string getID()
{
	return ID;
}
Node::string getRhash()
{
	return RHASH;
}
Node::string getLhash()
{
	return LHASH;
}
Node::Node * parent()
{
	return parent_;
}
Node::Node * leftChild()
{
	return leftchild_;
}
Node::Node * rightChild()
{
	return rightchild_;
}

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
