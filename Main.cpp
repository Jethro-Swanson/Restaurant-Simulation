//-----------------------------------------
// Author  : Jethro Swanson
// Date    : 01/02/2022
// REMARKS : Simulates a chef taking food orders at a reseraunt and processes them once at a time
//           in an event-driven simulation.
//
//-----------------------------------------

#include "FileProcessor.h"

#include <string>
#include <iostream>
using namespace std;

//Expected Arguments:
// argv[0] - The name of the program to be executed
// argv[1] - The file of simulation events that will occur during the run of the program
// argv[2] - The type of simulation to proccess the events with (1, 2, or 3)
int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout<<"USAGE: SampleFile.out filename simulationType"<<endl;
		cout<<"where simulationType is either 1, 2 or 3."<<endl;
		return 0;
	}

	string fileName = argv[1];
	string version = argv[2];
	
	cout << "The filename is: " << fileName << endl;
	cout << "The version selected is: " << version <<endl;
	
	FileProcessor* fileProcessor =new FileProcessor(fileName, version);
	fileProcessor->processFile();
	
	cout<<"Program executed succesfully"<<endl;
}