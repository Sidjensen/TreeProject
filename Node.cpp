// Node.cpp
// Addison Dugal, Evan Staben, Sidney Jensen
// Definitions of the Node class methods

#include "pch.h"
#include "Node.h"


Node::Node(Node & parent)
{
	setParent(parent);
}

Node::Node()
{

}

void Node::addLeftChild(Node & parent)
{
	Node * child = new Node();
	child->setParent(parent);
	leftchild_ = child;
}

void Node::addRightChild(Node & parent)
{
	Node* child = new Node();
	child->setParent(parent);
	parent.rightchild_ = child;
}

void Node::setParent(Node & parent)
{
	PARENT = parent.getID();
	parent_ = &parent;
}

void Node::addRawE(string e)
{
	RAWE = e;
	ID = hashFunk(RAWE, PARENT);
	if (this == parent_->leftChild())
	{
		parent_->setRHash(funkHash(ID, RAWE, LHISTH));
		parent_->appendLHist(parent_->getLhash());
	}
	if (this == parent_->rightChild())
	{
		parent_->setLHash(funkHash(ID, RAWE, RHISTH));
		parent_->appendRHist(parent_->getRhash());
	}
}

void Node::setRHash(string e)
{
	RHASH = e;
}
void Node::setLHash(string e)
{
	LHASH = e;
}

void Node::appendRHist(string s)
{
	RHISTH.push_back(s);
	if (this == parent()->leftChild())
	{
		parent_->appendLHist(s);
	}
	if (this == parent()->rightChild())
	{
		parent_->appendRHist(s);
	}
}

void Node::appendLHist(string s)
{
	LHISTH.push_back(s);
	if (this == parent()->leftChild())
	{
		parent_->appendLHist(s);
	}
	if (this == parent()->rightChild())
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

string Node::hashFunk(string ID, string other)
{
	return ID.substr(0, 0) + other.substr(0, 0) + ID.substr(1, 1) + other.substr(1, 1) + ID.substr(2, 2) + other.substr(2, 2) + ID.substr(3, 3) + other.substr(3, 3) + ID.substr(4, 4) + other.substr(4, 4);
}
string Node::funkHash(string Child1, string Child2, vector<string> Hist)
{
	string hash1 = hashFunk(Child1, Child2).substr(0, 3);
	string half1 = Hist[0] + Hist[1] + Hist[2] + Hist[3];
	string half2 = Hist[4] + Hist[5] + Hist[6] + Hist[7];
	string hash2 = hashFunk(half1, half2);
	return (hash1 + hash2);
}
