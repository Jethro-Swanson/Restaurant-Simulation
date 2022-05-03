//CLASS: Stack
//
//Author: Jethro Swanson
//
//REMARKS: Subset of a linked list that operates on a first-in last-out basis
//
//-----------------------------------

#pragma once

#include "LinkedList.h"

class ListItem;

class Stack: public LinkedList
{
	public:
		//constructor
		Stack();
	
		//------------------------------------------------------
		// add
		//
		// PURPOSE: Adds a new ListItem value to the top of the Stack a Node
		// PARAMETERS:
		//		newItem - item to be added to the Stack as a Node
		//
		//------------------------------------------------------
		void add(ListItem*);
};