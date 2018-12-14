#pragma once
// Node.h
// Addison Dugal, Sidney Jensen, Evan Staben
// Delcaration of node class and functions

#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;


class Node
{

public:
	// Constructor
	// This Node contains only a parent pointer. All other data is null until entered with addRawE
	explicit Node(Node * parent);
	// Destructor
	~Node();
	// Accessors
	string getID();
	string getRhash();
	string getLhash();
	Node * parent();
	Node * leftChild();
	Node * rightChild();
	// Mutators
	void addRightChild();
	void addLeftChild();
	void addRawE(string e);
	void appendRHist(string s);
	void appendLHist(string s);
	
	void showIDs(string parent);
	void showRecords(string id);
	void changeNode(string id, string data);
	void newNode(string data);
	string printOut(vector<string> history);

private:
	Node();
	Node(const Node &);
	const Node & operator=(const Node &);
	string ID = NULL;
	string PARENT = NULL;
	string RAWE = NULL;
	string RHASH = NULL;
	string LHASH = NULL;
	vector<string> RHISTH;
	vector<string> LHISTH;
	Node * parent_;
	Node * leftchild_;
	Node * rightchild_;
};

#endif
