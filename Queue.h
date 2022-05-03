//CLASS: Queue
//
//Author: Jethro Swanson
//
//REMARKS: Subset of a linked list that operates on a First-in First-out basis
//
//-----------------------------------

#pragma once

#include "LinkedList.h"

class ListItem;

class Queue : public LinkedList
{
	public:
		//constructor
		Queue();
		
		//------------------------------------------------------
		// add
		//
		// PURPOSE: Adds a new ListItem value to the bottom of the Queue as a Node
		// PARAMETERS:
		//		newItem - item to be added to the Queue as a Node
		//
		//------------------------------------------------------
		void add(ListItem*);
};