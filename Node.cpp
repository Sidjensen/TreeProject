// Node.cpp
// tom bailey   1050  31 jan 2011
// Definitions of the Node class methods


#include "Node.h"


Node::Node(double entry)
	: entry_(entry), next_(NULL)
{
	cout << "Node( " << entry_ << ", " << next_ <<
		" ) created at " << this << endl;
}

Node::Node(double entry, Node * next)
	: entry_(entry), next_(next)
{
	cout << "Node( " << entry_ << ", " << next_ <<
		" ) created at " << this << endl;
}

Node::~Node()
{
	cout << "Node( " << entry_ << ", " << next_ <<
		" ) at " << this << " destroyed" << endl;
}
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
