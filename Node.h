//CLASS: Node
//
//Author: Jethro Swanson
//
//REMARKS: RNode for a list, contains data in the form of a ListItem
//
//-----------------------------------

#pragma once

#include "ListItem.h" 

class Node
{
	private:
		ListItem* data;
		Node* next;
	public:
		//constructor
		Node(ListItem*, Node*);
		
		//instance methods
		Node* getNext();
		void setNext(Node*);
		ListItem* getData();
		void setData(ListItem*);
		void print();
};