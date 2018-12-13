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
}

void Node::showRecords(string id)
{
	// show all values stored at the id
}

void Node::changeNode(string id, string data)
{
	// change node data, then update the rest
}

void Node::newNode(string data)
{
	// add a new node with the data, and make a new node
}
