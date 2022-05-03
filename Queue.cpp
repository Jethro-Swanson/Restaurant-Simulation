//CLASS: Queue
//
//Author: Jethro Swanson
//
//REMARKS: Subset of a linked list that operates on a First-in First-out basis
//
//-----------------------------------

#include "Queue.h"
#include "Node.h"
#include "ListItem.h"
#include "LinkedList.h"

Queue::Queue() : LinkedList() {}

//------------------------------------------------------
// add
//
// PURPOSE: Adds a new ListItem value to the bottom of the Queue as a Node
// PARAMETERS:
//		newItem - item to be added to the Queue as a Node
//
//------------------------------------------------------
void Queue::add(ListItem* newItem)
{
	Node* newNode = new Node(newItem, nullptr);
	Node* curr = LinkedList::getTop();
	
	//finds the last node and adds the new node after it
	if(curr != nullptr)
	{
		while(curr->getNext() != nullptr)
		{
			curr = curr->getNext();
		}
		curr->setNext(newNode);		
	}
	else
	{
		LinkedList::setTop(newNode);
	}
}
