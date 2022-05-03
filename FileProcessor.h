//CLASS: FileProcessor
//
//Author: Jethro Swanson
//
//REMARKS: Allows the opening and reading of an input file and begins the simulation with 
//         the input provided.   
//
//-----------------------------------

#pragma once 

#include <string>
using namespace std;

class FileProcessor
{
	private:
		string fileName;
		string version;
		
	public:
		//------------------------------------------------------
		// FileProcessor
		//
		// PURPOSE: Constructs FileProcessor object
		// PARAMETERS:
		// 		fileName - Name of file containing orders to be processed
		//      version - The version of the simulation to run, accepted values are 1,2, and 3		 	
		//
		//------------------------------------------------------
		FileProcessor(std::string, std::string);
		
		//------------------------------------------------------
		// processFile
		//
		// PURPOSE: Reads the file of the name given when the object was constructed. Processing each line one
		//          at a time, sending each to be processed by the simulation as they are reached.  
		//------------------------------------------------------
		void processFile();
};