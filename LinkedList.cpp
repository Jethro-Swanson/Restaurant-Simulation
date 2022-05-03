//CLASS: LinkedList
//
//Author: Jethro Swanson
//
//REMARKS: Abstract Linked List object that provides basic list functionality
//
//-----------------------------------

#include "LinkedList.h"
#include "Node.h"

#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
	top = nullptr;
}

Node* LinkedList::getTop()
{
	return top;
}
		
void LinkedList::setTop(Node* newTop)
{
	top = newTop;
}

//------------------------------------------------------
// print
//
// PURPOSE: Prints out a representation of the linked list, including all of its nodes values, to the console
//
//------------------------------------------------------
void LinkedList::print() 
{
	Node* curr = getTop();
	
	cout<<"[ ";
	
	//prints all nodes within the list
	while(nullptr != curr)
	{
		curr->print();
		
		curr = curr->getNext();
		if(nullptr != curr)
		{
			cout<<", ";
		}
	}
	
	cout<<"]"<<endl;
}

//------------------------------------------------------
// pop
//
// PURPOSE: Removes the top node of the list from the list
// Returns: Node pointer to the removed node
//------------------------------------------------------
Node* LinkedList::pop()
{
	Node* topNode = LinkedList::getTop();
	if(nullptr != topNode)
	{
		LinkedList::setTop(topNode->getNext());
	}
	
	return topNode;
}