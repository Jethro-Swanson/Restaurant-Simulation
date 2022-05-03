//CLASS: LinkedList
//
//Author: Jethro Swanson
//
//REMARKS: Abstract Linked List object that provides basic list functionality
//
//-----------------------------------

#pragma once

#include "ListItem.h"
#include "Node.h"

class LinkedList : public ListItem
{
	private:
		Node* top;
	public:
		//constructor
		LinkedList();
	
		//virtual methods
		virtual void add(ListItem*) =0;
		
		//instance methods
		Node* getTop();
		void setTop(Node*);
		
		//------------------------------------------------------
		// print
		//
		// PURPOSE: Prints out a representation of the linked list, including all of its nodes values, to the console
		//
		//------------------------------------------------------
		void print();
		
		//------------------------------------------------------
		// pop
		//
		// PURPOSE: Removes the top node of the list from the list
		// Returns: Node pointer to the removed node
		//------------------------------------------------------
		Node* pop();
};