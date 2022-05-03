Restaurant Simulation

Description: 
	Simulates a chef taking an preparing orders based on an input text file of orders, continuing untill
	all orders are either fullfilled or expire.
	The file is expected to be a text file containing one (1) order per line in the following format
	
	ArrivalTime ExpiryTime Meal ExtraIngredient1 ExtraIngredient2 ExtraIngredient3 ...

	ArrivalTime - time in the simulation the order is received
	ExpiryTime - time in the simulation the order is no longer valid
	Meal - The main dish being ordered, must be one of the following items:
		Pizza, Stew, Salad, Burger
		(each item has unique cost and prep time values associated with it so arbitrary meals are not allowed)
	ExtraIngredient# - any number of additional arbitrary strings seperated by whitespace, each adds prep time
		and cost to the meal.
		(there can be any number of ExtraIngredient# items in an order)
	
	Note: The file SampleInput.txt has been provided for further clarification on proper formatting of input)

How to use:

	1) Compile using version 11 of c, tested on linux servers

		clang++ *.cpp -std=c++11

	2) Run the following command, replacing "SampleInput.txt" with your properly formated input file and "#Version" with a number 1,2, or 3 
	   coresponding to the version of the simulation you would like to run ie "a.out myInput.txt 3". Your txt file must be in the same directory
	   as the program.
	   
	   Versions:
		1 - uses queue for incoming orders (first in first out)
		2 - uses stack for incoming orders (first in last out)
		3 - uses a priority queue for incoming orders (highest value order first)

	   a.out SampleInput.txt #Version
	   
	3) Output of notable simulation events and records of the final values for the simulation will be printed to console

