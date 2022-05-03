//CLASS: PriorityQueue
//
//Author: Jethro Swanson
//
//REMARKS: Subset of a linked list that operates prority basis with respect to price, with the highest priced items are at the top.
//
//-----------------------------------

#pragma once 

#include "LinkedList.h"

class ListItem;

class PriorityQueue: public LinkedList
{
	public:
		PriorityQueue();
		
		//------------------------------------------------------
		// add
		//
		// PURPOSE: Adds a new ListItem value to the PriorityQueue based on its price
		// PARAMETERS:
		//		newItem - item to be added to the PriorityQueue as a Node
		//
		//------------------------------------------------------
		void add(ListItem*);
};