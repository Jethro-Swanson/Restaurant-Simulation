//CLASS: Stack
//
//Author: Jethro Swanson
//
//REMARKS: Subset of a linked list that operates on a first-in last-out basis
//
//-----------------------------------

#include "Stack.h"
#include "Node.h"
#include "ListItem.h"
#include "LinkedList.h"

Stack::Stack(): LinkedList(){}

//------------------------------------------------------
// add
//
// PURPOSE: Adds a new ListItem value to the top of the Stack a Node
// PARAMETERS:
//		newItem - item to be added to the Stack as a Node
//
//------------------------------------------------------
void Stack::add(ListItem* newItem)
{
	Node* newNode = new Node(newItem, nullptr);
	Node* topNode = LinkedList::getTop();
	newNode->setNext(topNode);
	LinkedList::setTop(newNode);
}


