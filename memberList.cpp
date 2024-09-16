//****************************************************
// Class: memberList.cpp (Implementation File)       *
// This class maintains a list of objects.           *
//****************************************************
// Name: Nick Francisco
// Class: CS 2020
#include "memberNode.h"
#include "memberList.h"

#include <iostream>
#include <iomanip>
using namespace std;

memberList::memberList()
{
	head = nullptr;
	tail = nullptr;
}

//****************************************************
// Function: ~memberList  (Destructor)               *
// This function destroys the entire list somewhat   *
// recusively?										 *
//****************************************************
memberList::~memberList()
{
	if (head) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
}
//****************************************************
// Function: operator=                               *
// This is an overloaded assignment function. It is  *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
memberList& memberList::operator=(memberList& rhs){
	memberNode* currNode = rhs.head;                // Copy List
	if (head != rhs.head)
	{
		if (head){
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		while (currNode != nullptr) {

			PushBack(new memberNode(currNode->getID(), currNode->getName(), currNode->getPolicy(), currNode->getYear(), currNode->getPremium(), currNode->getNextNodeLoc()));
			currNode = currNode->getNextNodeLoc();					//Traversal Statement
		}													//Important to point to the next node
	}
	return *this;
}
//****************************************************
// Function: memberList(memberList& rhs)                   *
// This is an copy constructor function. It is       *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
memberList::memberList(memberList& rhs){
	memberNode* currNode = rhs.head;                // Copy List

	while (currNode != nullptr) {
		PushBack(new memberNode(currNode->getID(), currNode->getName(), currNode->getPolicy(), currNode->getYear(), currNode->getPremium(), currNode->getNextNodeLoc()));
		currNode = currNode->getNextNodeLoc();					//Traversal Statement
	}													//Important to point to the next node
}

//****************************************************
// Function: PushBack                                *
// Takes the node passed in and adds it to the end   *
// of the linked list. Accounts for an empty list.	 *
//****************************************************
void memberList::PushBack(memberNode* currNode) {
	if (!head) {
		head = tail = currNode;
	}
	else {
		tail->setNextNodeLoc(currNode);
		tail = currNode;
	}
	cout << currNode->getID() << " member added." << endl;
}

//Adds a member node to the front of the linked list
void memberList::addOneMember(memberNode* currNode)
{
	//Makes the new node point to the currect first node
	currNode->setNextNodeLoc(this->head);
	//Makes the new node the first node
	head = currNode;
	cout << currNode->getID() << " member added." << endl;
}

//Removes a selected node from anywhere on the list
void memberList::removeOneMember(int id)
{
	memberNode* currNode = nullptr;
	memberNode* prevNode = nullptr;

	//Makes sure list is not empty
	if (head == nullptr)
	{
		cout << "The list is empty." << endl;
		cout << id << " is not a member." << endl;
		return;
	}

	//Checks if the node being removed is the first node in the list
	if (head->getID() == id)
	{
		currNode = head;

		//If there is only one item in the list
		if (head == tail)
		{
			tail = nullptr;
		}

		//The new head is set to the second item in the list
		head = head->getNextNodeLoc();
		currNode->setNextNodeLoc(nullptr);
		delete currNode;
	}
	//If it is not the first node, traverse until it finds the node to be removed
	else
	{
		currNode = head;

		//Loops until it finds the member to remove, or it reaches the end of the list
		while (currNode != nullptr && currNode->getID() != id)
		{
			prevNode = currNode;
			currNode = currNode->getNextNodeLoc();
		}

		//If it finds the node to remove
		if (currNode != nullptr)
		{
			//Points the previous node to the node after the node to be removed
			prevNode->setNextNodeLoc(currNode->getNextNodeLoc());

			//If the node being removed is the last node, the previous node is the last node now
			if (currNode == tail)
			{
				tail = prevNode;
			}

			currNode->setNextNodeLoc(nullptr);
			delete currNode;
		}
		//If it reaches the end and it does not find the member
		else
		{
			cout << id << " is not a member" << endl;
		}
	}

}

//Traverses through the list and prints the list of members in an organized table
void memberList::printMemberList()
{
	memberNode* currNode = head;
	int memberCount = 0;

	cout << "===============================================================================" << endl;
	cout << left << setw(5) << "Id" << setw(25) << "Name" << setw(15) << "Policy" << setw(10) << "Premium" << setw(8) << "Years" << endl;
	cout << left << setw(5) << "--" << setw(25) << "----" << setw(15) << "------" << setw(10) << "-------" << setw(8) << "-----" << endl;

	while (currNode != nullptr)
	{
		cout << left << setw(5) << currNode->getID() << setw(25) << currNode->getName() << setw(15) << currNode->getPolicy() << setw(10) << currNode->getPremium() << setw(8) << currNode->getYear() << endl;
		memberCount++;

		currNode = currNode->getNextNodeLoc();
	}
	if (memberCount == 0)
	{
		cout << "The list is empty." << endl;
	}
	cout << "===============================================================================" << endl;
}

//Traverses through the list and prints out any members with the matching policy, and the average premium of the policy holders
void memberList::printPolicy(string policy)
{
	memberNode* currNode = head;
	double numPolicy = 0.0;
	int totalPremium = 0;

	cout << "===============================================================================" << endl;
	cout << setw(15) << right << "All " << policy << " Members" << endl;
	cout << "===============================================================================" << endl;

	cout << left << setw(5) << "Id" << setw(25) << "Name" << setw(15) << "Policy" << setw(10) << "Premium" << setw(8) << "Years" << endl;
	cout << left << setw(5) << "--" << setw(25) << "----" << setw(15) << "------" << setw(10) << "-------" << setw(8) << "-----" << endl;

	while (currNode != nullptr)
	{
		if (currNode->getPolicy() == policy)
		{
			cout << left << setw(5) << currNode->getID() << setw(25) << currNode->getName() << setw(15) << currNode->getPolicy() << setw(10) << currNode->getPremium() << setw(8) << currNode->getYear() << endl;

			numPolicy += 1.0;
			totalPremium += currNode->getPremium();
		}

		currNode = currNode->getNextNodeLoc();
	}

	cout << "-------------------------------------------------------------------------------" << endl;
	if (totalPremium > 0)
	{
		cout << "The average " << policy << " premium is: $" << totalPremium / numPolicy << endl;
	}
	else
	{
		cout << "Sorry, no " << policy << " members" << endl;
	}
		
	cout << "===============================================================================" << endl;
}

//Traverses through the list and prints any member that is greater than or equal to the number of years input
void memberList::printYear(int year)
{
	memberNode* currNode = head;
	int yearCount = 0;

	cout << "===============================================================================" << endl;
	cout << setw(15) << right << "Members of at least: " << year << " Years" << endl;
	cout << "===============================================================================" << endl;

	cout << left << setw(5) << "Id" << setw(25) << "Name" << setw(15) << "Policy" << setw(10) << "Premium" << setw(8) << "Years" << endl;
	cout << left << setw(5) << "--" << setw(25) << "----" << setw(15) << "------" << setw(10) << "-------" << setw(8) << "-----" << endl;

	while (currNode != nullptr)
	{
		if (currNode->getYear() >= year)
		{
			cout << left << setw(5) << currNode->getID() << setw(25) << currNode->getName() << setw(15) << currNode->getPolicy() << setw(10) << currNode->getPremium() << setw(8) << currNode->getYear() << endl;
			yearCount++;
		}
		currNode = currNode->getNextNodeLoc();
	}

	if (yearCount == 0)
	{
		cout << "Sorry, no members with " << year << " or more years" << endl;
	}

	cout << "===============================================================================" << endl;
}

//Traverses through the list and prints out the member with the lowest premium
void memberList::printLowPremium()
{
	memberNode* currNode = head;
	memberNode* lowNode = head;

	while (currNode != nullptr)
	{
		if (currNode->getPremium() < lowNode->getPremium())
		{
			lowNode = currNode;
		}
		currNode = currNode->getNextNodeLoc();
	}

	cout << "===============================================================================" << endl;
	cout << lowNode->getName() << " has the lowest premium of $" << lowNode->getPremium() << endl;
	cout << "===============================================================================" << endl;
}