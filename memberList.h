// Purpose: Header file for the Member List class
// Name: Nick Francisco
// Class: CS 2020
#ifndef MEMBERLIST_H
#define MEMBERLIST_H
#include "memberNode.h"

using namespace std;

class memberList
{
	public:
		//Linked List constructor
		memberList();

		//Big-Three
		~memberList();
		memberList& operator=(memberList& rhs);
		memberList(memberList& rhs);

		//Linked List functions
		void PushBack(memberNode* currNode);
		void addOneMember(memberNode* currNode);
		void removeOneMember(int id);
		void printMemberList();
		void printPolicy(string policy);
		void printYear(int year);
		void printLowPremium();

		//Linked List first and last nodes
		memberNode* head;
		memberNode* tail;
};

#endif
