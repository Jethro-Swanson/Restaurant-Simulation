//CLASS: Order
//
//Author: Jethro Swanson
//
//REMARKS: Represents a single meal order, to be used as the data within a list node
//
//-----------------------------------


#pragma once

#include "ListItem.h"

#include <string>
using namespace std;

class Order : public ListItem
{
	private:
		//set preptime and prices for items
		const int SALAD_TIME = 3;
		const int BURGER_TIME = 4;
		const int PIZZA_TIME = 6;
		const int STEW_TIME = 7;
		const int INGREDIENT_TIME =1; //per extra ingredient
		const double SALAD_PRICE = 6.99;
		const double BURGER_PRICE = 8.99;
		const double PIZZA_PRICE = 12.99;
		const double STEW_PRICE = 14.99;
		const double INGREDIENT_PRICE = 1;//per extra ingredient
	
		int time;
		int expiry;
		string meal;
		int numIngredients;
		int orderID;
		int prepTime;
		double price;
		int completeTime;
		
		static int nextID;
	public:
		
		//------------------------------------------------------
		// Order
		//
		// PURPOSE: Constructs an Order object
		// PARAMETERS:
		// 		newTime - Simulation time unit the order arrived
		//      newExpiry - Sim time value at wich the order will be deleted if not prepped
		//      newMeal - name of meal to be made, valid values are "Salad","Burger","Pizza", and "Stew"
		//      newNumIngredients - The number of extra ingredients used in the meal
		//
		//------------------------------------------------------
		Order(int,int,string,int);
		
		//instance methods
		void print() override;
		
		//getters
		int getTime();
		int getExpiry() override;
		string getMeal();
		int getNumIngredients();
		int getOrderID() override;
		int getPrepTime() override;
		double getPrice() override;
		int getCompleteTime() override;
		
		//setters
		void setTime(int);
		void setExpiry(int);
		void setMeal(string);
		void setNumIngredients(int);
		void setCompleteTime(int) override;
};