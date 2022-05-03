//CLASS: ListItem
//
//Author: Jethro Swanson
//
//REMARKS: Generic abstract Item to be stored in a list node
//
//-----------------------------------


#pragma once 

class ListItem
{	
	public: 
		virtual void print() =0;
		
		//Order polymorphic methods
		virtual double getPrice();
		virtual int getOrderID();
		virtual int getExpiry();
		virtual int getCompleteTime();
		virtual int getPrepTime();
		virtual void setCompleteTime(int);
};