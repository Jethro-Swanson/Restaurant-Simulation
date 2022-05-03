//CLASS: Order
//
//Author: Jethro Swanson
//
//REMARKS: Represents a single meal order, to be used as the data within a list node
//
//-----------------------------------

#include "Order.h"

#include <string>
#include <iostream>
using namespace std;

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
Order::Order(int newTime, int newExpiry, string newMeal, int newNumIngredients) : time(newTime), expiry(newExpiry), meal(newMeal), numIngredients(newNumIngredients) 
{
	//calculates approprate price and prep time for the order based on meal type and ingredient quantity
	if(meal == "Salad")
	{
		prepTime = SALAD_TIME;
		price = SALAD_PRICE;
	}
	else if(meal == "Burger")
	{
		prepTime = BURGER_TIME;
		price = BURGER_PRICE;
	}
	else if(meal == "Pizza")
	{
		prepTime = PIZZA_TIME;
		price = PIZZA_PRICE;
	}
	else if(meal == "Stew")
	{
		prepTime = STEW_TIME;
		price = STEW_PRICE;
	}
	
	prepTime +=  (numIngredients * INGREDIENT_TIME);
	price += (numIngredients * INGREDIENT_PRICE);
	
	orderID = nextID;
	nextID++;
}

void Order::print()
{
	cout <<"Expiry:" << expiry << " Meal:" << meal << " NumIngredients:" 
		 << numIngredients << " Prep Time:" << prepTime<< " Price:"<< price<< endl;
}

//getters
int Order::getTime()
{
	return time;
}

int Order::getExpiry()
{
	return expiry;
}

string Order::getMeal()
{
	return meal;
}

int Order::getNumIngredients()
{
	return numIngredients;
}

int Order::getOrderID()
{
	return orderID;
}

int Order::getPrepTime()
{
	return prepTime;
}

double Order::getPrice()
{
	return price;
}

int Order::getCompleteTime()
{
	return completeTime;
}
		
//setters		
void Order::setTime(int newTime)
{
	time = newTime;	
}

void Order::setExpiry(int newExpiry)
{
	expiry = newExpiry;
}

void Order::setMeal(string newMeal)
{
	meal = newMeal;
}

void Order::setNumIngredients(int newNumIngredients)
{
	numIngredients = newNumIngredients;
}

void Order::setCompleteTime(int cTime)
{
	completeTime = cTime;
}

int Order::nextID =1;