//CLASS: SimProcessor
//
//Author: Jethro Swanson
//
//REMARKS: Conducts a simulation on input orders orders representing a chef cooking meals 
//
//-----------------------------------

#include "SimProcessor.h"
#include "LinkedList.h"
#include "Order.h"
#include "Queue.h"
#include "Stack.h"
#include "PriorityQueue.h"


#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------
// SimProcessor
//
// PURPOSE: Constructs a SimProcessor object based on input simulation version, 1 for queue, 2 for stack, and 3 for priority queue
// PARAMETERS:
// 		version - The version of simulation to preform, should be 1,2, or 3
//
//------------------------------------------------------
SimProcessor::SimProcessor(string version)
{
	if(version == "1")
	{
		orderList = new Queue();
	}
	else if(version == "2")
	{
		orderList = new Stack(); 
	}
	else if(version == "3")
	{
		orderList = new PriorityQueue();
	}
	
	eventQueue = new Queue();
	simTime = 1;
	completedCount =0;
	revenue = 0;
}

//------------------------------------------------------
// processArrival 
//
// PURPOSE: Handles Arrival events, when a new order is read and sent for processing
// PARAMETERS:
// 		order - order to be processed
//
//------------------------------------------------------
void SimProcessor::processArrival(Order* order)
{
	
	//processes all events at times before the next arrival
	processEvents(order->getTime());
	
	orderList->add(order);
	
	cout<< "TIME: " << simTime << ", FoodOrder " << order->getOrderID() << " arrives -> ";
	order->print();
	
	
}

//------------------------------------------------------
// completeService
//
// PURPOSE: Handles the event when an order has been completed, adding the profit and begining another order if possible
//
//------------------------------------------------------
void SimProcessor::completeService()
{
	ListItem* completedOrder = eventQueue->pop()->getData();
	
	revenue += completedOrder->getPrice();
	completedCount++;
	
	cout<< "TIME: " << completedOrder->getCompleteTime() << ", FoodOrder " << completedOrder->getOrderID() << " has been served! Revenue grew by: $" << revenue << endl;
	
	attemptPreping();
}

//------------------------------------------------------
// attemptPreping
//
// PURPOSE: Trys to begin preping another order if an unexpired one is available, and purges all expired orders found in the search 
//
//------------------------------------------------------
void SimProcessor::attemptPreping()
{
	ListItem* nextOrder;
	
	if(orderList->getTop() != nullptr){
		nextOrder = orderList->getTop()->getData();
	}
	else
	{
		nextOrder = nullptr;
	}
	
	//removes all expired orders found 
	while(nextOrder != nullptr && nextOrder->getExpiry() < simTime)
	{
		orderList->pop();
		
		if(orderList->getTop() != nullptr){
			nextOrder = orderList->getTop()->getData();
		}
		else
		{
			nextOrder = nullptr;
		}
	}
	
	//begins prepeing the first available order
	if(nextOrder != nullptr)
	{
		nextOrder->setCompleteTime(simTime + nextOrder->getPrepTime());
		eventQueue->add(nextOrder);
		orderList->pop();
		cout<< "TIME: " << simTime << ", FoodOrder " << nextOrder->getOrderID() << ", is getting prepared by the chef!" << endl;
	}
}

//------------------------------------------------------
// processEvents
//
// PURPOSE: Simulates time moving forward, handling events as they occur, untill at target time (usually an arrival event time)
// PARAMETERS: 
// 		targetTime - This is the time unit to process up to, all events that would occur before or at this point are processed
//
//------------------------------------------------------
void SimProcessor::processEvents(int targetTime)
{
	ListItem* topOrder;
	
	while(simTime <= targetTime)
	{
		if(eventQueue->getTop() != nullptr){
			topOrder= eventQueue->getTop()->getData();
			if(topOrder != nullptr){
				if(simTime >= topOrder->getCompleteTime())
				{
					completeService();
				}
			}
		}
		else if(orderList->getTop() != nullptr)
		{
			attemptPreping();
		}
		
		simTime++;
	}
	simTime--;
}

//------------------------------------------------------
// finishSim
//
// PURPOSE: Used when the last arrival event has been read, continues the simulation one increment at a time 
//			untill all orders are gone and all events have been processed.
//
//------------------------------------------------------
void SimProcessor::finishSim()
{
	bool finished = true;
	
	//initially determins if there are any remaining events or orders
	if(orderList->getTop() != nullptr){
		finished = false;
	}
	else if(eventQueue->getTop() != nullptr)
	{
		finished = false;
	}
	
	//processes all remaning events and orders
	while(!finished)
	{
		processEvents(simTime+1);
		if(orderList->getTop() == nullptr && eventQueue->getTop() == nullptr){
			finished = true;
		}
	}
	
	cout<< "... simulation ended." << endl;
	cout<< "- Total number of orders completed: " << completedCount << endl;
	cout<< "- Total revenue: $" << revenue << endl;
}
