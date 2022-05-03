//CLASS: ListItem
//
//Author: Jethro Swanson
//
//REMARKS: Generic abstract Item to be stored in a list node
//
//-----------------------------------

#include "ListItem.h"

//placeholder implementations

double ListItem::getPrice()
{
	return 0;
}

int ListItem::getOrderID()
{
	return 0;
}

int ListItem::getExpiry()
{
	return 0;
}
		 
int ListItem::getCompleteTime()
{
	return 0;
}
		 
int ListItem::getPrepTime()
{
	return 0;
}
		 
void ListItem::setCompleteTime(int){}