#pragma once
// Node.h

// tom bailey   0755  05 oct 2010
// Declare the Node class.

// Node uses public access to simplify code in the
// container classes that use Nodes.  Client access is
// controlled by the container classes.

// The constructors and destructor are verbose to facilitate
// tracking of memory leaks.

// The default constructor and assignment operator are
// declared private so they cannot be called.

#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;


class Node
{

public:
	// Constructors

	// post: this Node contains entry and NULL pointers, except parent
	explicit Node(Node * parent);

	// Destructor

	~Node();
	//accessors
	string getID();
	string getRhash();
	string getLhash();
	Node * parent();
	Node * leftChild();
	Node * rightChild();
	//mutators
	void appendRHist(string s);
	void appendLHist(string s)

private:
	// Inaccessible standard functions
	Node();
	Node(const Node &);
	const Node & operator=(const Node &);
	string ID;
	string PARENT;
	string RAWE;
	string RHASH;
	string LHASH;
	vector<string> RHISTH;
	vector<string> LHISTH;
	Node * parent_;
	Node * leftchild_;
	Node * rightchild_;
};

#endif
