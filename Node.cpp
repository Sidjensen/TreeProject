// Node.cpp
// Sidney Jensen, Addison Dugal, Evan Staben
// Definitions of the Node class methods


#include "Node.h"


Node::Node(Node * parent)
{
	PARENT = parent.getID();
	parent_ = parent;
}

void Node::addLeftChild()
{
	Node child = new Node * (this);
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
void Node::showIDs(Node * parent)
{
	// take parent ID and use to print out all other IDs
	Node * Firstparent = parent;
	cout << ID;
	while (Firstparent.leftChild() != NULL)
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
	cout << "Right Hash History: " << printOut(RHISTH) << endl;
	cout << "Left Hash History: " << printOut(LHISTH) << endl;

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
