// Purpose: Class that contains the functions for the member nodes,
// and contains a constructor and a destructor
// Name: Nick Francisco
// Class: CS 2020
#include "memberNode.h"
#include <iostream>

//Member Node constructor
memberNode::memberNode(int id, string name, string policy, int year, int premium, memberNode* nextNodeLoc)
{
	this->id = id;
	this->name = name;
	this->policy = policy;
	this->year = year;
	this->premium = premium;
	this->nextNodeLoc = nextNodeLoc;
}
//Member Node destructor that outputs when a member is removed from the linked list
memberNode::~memberNode()
{
	cout << id << " member removed" << endl;
	if (nextNodeLoc != nullptr)
	{
		//cout << id << " member removed" << endl;
		delete nextNodeLoc;
		nextNodeLoc = nullptr;
	}
}

//Sets the id of the member node
void memberNode::setID(int id) 
{
	this->id = id;
}

//Sets the name of the member node
void memberNode::setName(string name)
{
	this->name = name;
}

//Sets the policy of the member node
void memberNode::setPolicy(string policy) 
{
	this->policy = policy;
}

//Sets the year of the member node
void memberNode::setYear(int year)
{
	this->year = year;
}

//Sets the premium of the member node
void memberNode::setPremium(int premium)
{
	this->premium = premium;
}

//Sets the pointer to the next node location
void memberNode::setNextNodeLoc(memberNode* nextNodeLoc)
{
	this->nextNodeLoc = nextNodeLoc;
}

//Returns the id of the member node
int memberNode::getID()
{
	return id;
}

//Returns the name of the member node
string memberNode::getName()
{
	return name;
}

//Returns the policy of the member node
string memberNode::getPolicy()
{
	return policy;
}

//Returns the year of the member node
int memberNode::getYear()
{
	return year;
}

//Returns the premium of the member node
int memberNode::getPremium()
{
	return premium;
}

//Returns the pointer to the next node location
memberNode* memberNode::getNextNodeLoc()
{
	return nextNodeLoc;
}