//CLASS: PriorityQueue
//
//Author: Jethro Swanson
//
//REMARKS: Subset of a linked list that operates prority basis with respect to price, with the highest priced items are at the top.
//
//-----------------------------------

#include "PriorityQueue.h"

#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue() : LinkedList() {}

//------------------------------------------------------
// add
//
// PURPOSE: Adds a new ListItem value to the PriorityQueue based on its price
// PARAMETERS:
//		newItem - item to be added to the PriorityQueue as a Node
//
//------------------------------------------------------
void PriorityQueue::add(ListItem* newItem)
{
	Node* newNode = new Node(newItem, nullptr);
	Node* curr = LinkedList::getTop();
	Node* prev;
	
	//handles case where input item is the most expensive in list
	if(curr != nullptr && (curr->getData()->getPrice() < newItem->getPrice()))
	{
		LinkedList::setTop(newNode);
		newNode->setNext(curr);
	}
	
	//finds the first node of smaller value and adds the new node before it
	else if(curr != nullptr)
	{
		while(curr != nullptr && (curr->getData()->getPrice() >= newItem->getPrice()))
		{
			prev = curr;
			curr = curr->getNext();
		}
		prev->setNext(newNode);	
		newNode->setNext(curr);
	}
	else
	{
		LinkedList::setTop(newNode);
	}
}