//CLASS: SimProcessor
//
//Author: Jethro Swanson
//
//REMARKS: Conducts a simulation on input orders orders representing a chef cookin meals 
//
//-----------------------------------

#pragma once

#include <string>
using namespace std;

class LinkedList;
class Order;
class Queue;

class SimProcessor 
{
	private:
		LinkedList* orderList;
		double revenue;
		int completedCount;
		int simTime;
		Queue* eventQueue;
		
		//------------------------------------------------------
		// completeService
		//
		// PURPOSE: Handles the event when an order has been completed, adding the profit and begining another order if possible
		//
		//------------------------------------------------------
		void completeService();
		
		//------------------------------------------------------
		// attemptPreping
		//
		// PURPOSE: Trys to begin preping another order if an unexpired one is available, and purges all expired orders found in the search 
		//
		//------------------------------------------------------
		void attemptPreping();
		
		//------------------------------------------------------
		// processEvents
		//
		// PURPOSE: Simulates time moving forward, handling events as they occur, untill at target time (usually an arrival event time)
		// PARAMETERS: 
		// 		targetTime - This is the time unit to process up to, all events that would occur before or at this point are processed
		//
		//------------------------------------------------------
		void processEvents(int);
		
	public:
		//------------------------------------------------------
		// SimProcessor
		//
		// PURPOSE: Constructs a SimProcessor object
		// PARAMETERS:
		// 		version - The version of simulation to preform, should be 1,2, or 3
		//
		//------------------------------------------------------
		SimProcessor(string);
		
		//------------------------------------------------------
		// processArrival 
		//
		// PURPOSE: Handles Arrival events, when a new order is read and sent for processing
		// PARAMETERS:
		// 		order - order to be processed
		//
		//------------------------------------------------------
		void processArrival(Order*);
		
		//------------------------------------------------------
		// finishSim
		//
		// PURPOSE: Used when the last arrival event has been read, continues the simulation one increment at a time 
		//			untill all orders are gone and all events have been processed.
		//
		//------------------------------------------------------
		void finishSim();
};