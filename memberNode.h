// Purpose: Header file for the Member Node class
// Name: Nick Francisco
// Class: CS 2020
#ifndef MEMBERNODE_H
#define MEMBERNODE_H
#include <string>

using namespace std;

class memberNode
{
	public:
		//Linked List Node constructor and destructor
		memberNode(int id = 0, string name = "", string policy = "", int year = 0, int premium = 0, memberNode* nextNodeLoc = nullptr);
		~memberNode();

		//Node data member set functions
		void setID(int id);
		void setName(string name);
		void setPolicy(string policy);
		void setYear(int year);
		void setPremium(int premium);
		void setNextNodeLoc(memberNode* nextNodeLoc);

		//Node data member get functions
		int getID();
		string getName();
		string getPolicy();
		int getYear();
		int getPremium();
		memberNode* getNextNodeLoc();

	private:
		//Node data members
		int id;
		string name;
		string policy;
		int year;
		int premium;
		memberNode* nextNodeLoc;
};

#endif
