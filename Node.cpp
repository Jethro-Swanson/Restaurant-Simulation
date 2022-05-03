//CLASS: Node
//
//Author: Jethro Swanson
//
//REMARKS: RNode for a list, contains data in the form of a ListItem
//
//-----------------------------------

#include "Node.h"
#include "ListItem.h"

Node::Node(ListItem* data, Node* next)
{
	setData(data);
	setNext(next);
}

Node* Node::getNext()
{
	return next;
}

void Node::setNext(Node* nextNode)
{
	next = nextNode;
}

ListItem* Node::getData()
{
	return data;
}

void Node::setData(ListItem* newData)
{
	data = newData;
}

void Node::print()
{
	getData()->print();
}
		