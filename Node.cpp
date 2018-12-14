// Node.cpp
// Sidney Jensen, Addison Dugal, Evan Staben
// Definitions of the Node class methods


#include "Node.h"


Node::Node(Node * parent)
{
	setParent(parent);
}

Node::Node()
{

}

void Node::addLeftChild()
{
	Node * child = new Node();
	child.setParent(this);
	leftchild_ = child;
}

void Node::addRightChild()
{
	Node * child = new Node();
	child.setParent(this);
	rightchild_ = child;
}

void Node::setParent(Node & parent)
{
	PARENT = parent.getID();
	parent_ = *parent;
}

void Node::addRawE(string e)
{
	RAWE = e;
	ID = hashFunk(RAWE, PARENT);
	if(this == parent_.leftChild())
	{
		//parent_->LHIST = hashFunk(stuff); // This might need funkHash instead? Can we hash a vector?
		parent_->appendLHist(parent_->LHIST);
	}
	if(this == parent_.rightChild())
	{
		//parent_->LHIST = hashFunk(stuff);
		parent_->appendRHist(parent_->RHIST);
	}
}

void Node::appendRHist(string s)
{
	RHISTH.push_back(s);
	if(this == parent_.leftChild())
	{
		parent_->appendLHist(s);
	}
	if(this == parent_.rightChild())
	{
		parent_->appendRHist(s);
	}
}

void Node::appendLHist(string s)
{
	LHISTH.push_back(s);
	if(this == parent_.leftChild())
	{
		parent_->appendLHist(s);
	}
	if(this == parent_.rightChild())
	{
		parent_->appendRHist(s);
	}
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
string Node::getRawE()
{
	return RAWE;
}
vector<string> Node::getRHist()
{
	return RHISTH;
}
vector<string> Node::getLHist()
{
	return LHISTH;
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
