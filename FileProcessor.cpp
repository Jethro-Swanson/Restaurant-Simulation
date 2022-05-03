//CLASS: FileProcessor
//
//Author: Jethro Swanson
//
//REMARKS: Allows the opening and reading of an input file and begins the simulation with 
//         the input provided.   
//
//-----------------------------------

#include "FileProcessor.h"
#include "LinkedList.h"
#include "Order.h"
#include "SimProcessor.h"

#include <fstream> 
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------
// FileProcessor
//
// PURPOSE: Constructs FileProcessor object
// PARAMETERS:
// 		fileName - Name of file containing orders to be processed
//      version - The version of the simulation to run, accepted values are 1,2, and 3		 	
//
//------------------------------------------------------
FileProcessor::FileProcessor(string fileName, string version) : fileName(fileName), version(version) {}

//------------------------------------------------------
// processFile
//
// PURPOSE: Reads the file of the name given when the object was constructed. Processing each line one
//          at a time, sending each to be processed by the simulation as they are reached.  
//------------------------------------------------------
void FileProcessor::processFile(){
	
	ifstream myFile;        //holds the contents of the input file
	myFile.open(fileName);  // opening the file specifed during construction
	string line;            //current line of the file being read
	
	SimProcessor* orderProcessor =new SimProcessor(version); //creates a simulation of the requested version to run the file inputs
	Order* newOrder;
	
	//continuously grabs and proccesses lines from myFile untill all have been proccessed
	while(getline(myFile, line))  
	{
		string token;
		int tokenounter = 0;
		int arrivalTime = 0; //time in the simulation this order will arrive
		int expiry = 0; //time in the sim wich this order will no longer be valid
		string meal = "";  //item the custormer is ordering 
		int numIngredients = 0; //quantity of additional items with order
		
		//proccesses the current line 1 token at a time, seperated by spaces
		token = strtok(line, " ");
		while(NULL != token) 
		{
			if(tokenCounter == 0) 
				arrivalTime = stoi(token);
			else if(tokenCounter == 1) 
				expiry = stoi(token);
			else if(tokenCounter == 2)
				meal = token;
			else //counts all remaning items, all of which are considered ingredients
			{
				numIngredients++;
			}
			counter++;
			token = strtok(NULL, " ");
		}

		newOrder = new Order(arrivalTime, expiry, meal, numIngredients);
		orderProcessor->processArrival(newOrder);
	}
	orderProcessor->finishSim();
}