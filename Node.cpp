// Node.cpp
// Sidney Jensen, Addison Dugal, Evan Staben
// Definitions of the Node class methods


#include "Node.h"


Node::Node(Node & parent)
{
	PARENT = parent.getID();
	parent_ = parent;
}

void Node::addLeftChild()
{
	Node * child = new Node();
	child.setParent(this);
	leftchild_ = child;
}

void Node::addRightChild()
{
	Node child = new Node * (this);
	rightchild_ = child;
}

void Node::addRawE(string e)
{
	RAWE = e;
	ID = hash(RAWE, PARENT);
	// Will add stuff here for updating history
}

void Node::appendRHist(string s)
{
	RHISTH.push_back(s);
}

void Node::appendLHist(string s)
{
	LHISTH.push_back(s);
}

string Node::getID()
{
	return ID;
}
string Node::getRhash()
{
	return RHASH;
}
string Node::getLhash()
{
	return LHASH;
}
Node * Node::parent()
{
	return parent_;
}
Node * Node::leftChild()
{
	return leftchild_;
}
Node * Node::rightChild()
{
	return rightchild_;
}

Node::~Node()
{}
