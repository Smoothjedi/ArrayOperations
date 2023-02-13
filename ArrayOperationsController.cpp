/*****************************************************************//**
 * \file   ArrayOperationsController.cpp
 * \brief  This file contains the 'main' function. Program execution begins and ends there.
 *		   Uses an input driven menu to make calls to the ArrayOperations object.	 
 * 
 * \author Mike
 * \date   February 2023
 *********************************************************************/

#include "ArrayOperations.h"
#include "OperationResult.h"
#include <iostream>
#include <stdlib.h>

int main()
{
	// Set to true when ready to complete loop
	bool terminateFlag = false;

	ArrayOperations* arrayOperations = new ArrayOperations();

	std::cout << "The array begins with " << arrayOperations->GetCurrentNumberOfItems() << 
		" elements with a capacity of " << arrayOperations->GetCurrentCapacity() << "." 
		<< std::endl << std::endl;

	do
	{
		// Menu interface
		int userSelection = 0;
		std::cout << "Please select an option:" << std::endl;
		std::cout << " 1: Get the index of a value in the array" << std::endl;
		std::cout << " 2: Modify a value in the array" << std::endl;
		std::cout << " 3: Add a value to the end of the array" << std::endl;
		std::cout << " 4: Remove a value from the array with an index" << std::endl;
		std::cout << " 5: Get a value from the array with an index" << std::endl;
		std::cout << " 6: Get the current capacity of the array" << std::endl;
		std::cout << " 7: Get the current number of integers in the array" << std::endl;
		std::cout << " 8: Load integers into array from csv file" << std::endl;
		std::cout << " 9: Load random integers into array" << std::endl;
		std::cout << "10: Erase all values from array" << std::endl;
		std::cout << std::endl << "Any other value will exit" << std::endl;
		std::cin >> userSelection;

		switch (userSelection)
		{
		case 1:
		{
			system("cls");
			int valueToFind = 0;
			std::cout << "Please enter a value to find: " << std::endl;
			std::cin >> valueToFind;
			//Call to get the index of a value
			OperationResult* result = arrayOperations->GetIndexOfValue(valueToFind);
			std::cout << result->GetResultSummary()
				<< std::endl << std::endl;
			delete result;
			break;
		}
		case 2:
		{
			system("cls");
			int newValue = 0;
			int indexToModify = 0;
			std::cout << "Please enter an index to modify: " << std::endl;
			std::cin >> indexToModify;
			std::cout << "Please enter a value to assign " << std::endl;
			std::cin >> newValue;
			// Call to update the value with the index provided.
			OperationResult* result = arrayOperations->UpdateValueByIndex(newValue, indexToModify);
			std::cout << result->GetResultSummary() 
				<< std::endl <<std::endl;
			delete result;
			break;
		}
		case 3:
		{
			system("cls");
			int valueToAdd = 0;
			std::cout << "Please enter a value to add: " << std::endl;
			std::cin >> valueToAdd;
			// Call to append the value to the end of the array
			OperationResult* result = arrayOperations->AppendValue(valueToAdd);
			std::cout << result->GetResultSummary()
				<< std::endl << std::endl;
			delete result;
			break;
		}
		case 4:
		{
			system("cls");
			int indexToRemove = 0;
			std::cout << "Please enter an index's value to remove: " << std::endl;
			std::cin >> indexToRemove;
			//Call to Remove value whose index is given
			OperationResult* result = arrayOperations->RemoveValueByIndex(indexToRemove);
			std::cout << result->GetResultSummary()
				<< std::endl << std::endl;
			delete result;
			break;
		}
		case 5:
		{
			system("cls");
			int index = 0;
			std::cout << "Please enter the index of the value you would like to get: " << std::endl;
			std::cin >> index;
			// Get the value from the provided index
			OperationResult* result = arrayOperations->GetValueAtIndex(index);
			std::cout << result->GetResultSummary()
				<< std::endl << std::endl;
			delete result;
			break;
		}
		case 6:
		{
			system("cls");
			// Get current capacity
			std::cout << "The current capacity is " << arrayOperations->GetCurrentCapacity()
				<< std::endl << std::endl;
			break;
		}
		case 7:
		{
			system("cls");
			// Get the current amount of items
			std::cout << "The current number of items is " << arrayOperations->GetCurrentNumberOfItems()
				<< std::endl << std::endl;
			break;
		}
		case 8:
		{
			system("cls");
			std::string filename;
			std::cout << "Please enter the filename and path of the file you would like to load: " << std::endl;
			std::cin.ignore();
			std::getline(std::cin, filename);
			// Load provided file from csv
			OperationResult* result = arrayOperations->LoadArrayDataFromCsv(filename);
			std::cout << result->GetResultSummary()
				<< std::endl << std::endl;
			delete result;
			break;
		}
		case 9:
		{
			system("cls");
			int seed = 0;
			std::cout << "Please enter an integer seed" << std::endl;
			std::cin >> seed;
			int amount = 0;
			std::cout << "How many random values would you like to add?" << std::endl;
			std::cin >> amount;
			OperationResult* result = arrayOperations->LoadRandomArrayData(seed, amount);
			std::cout << result->GetResultSummary()
				<< std::endl << std::endl;
			delete result;
			break;
		}
		case 10:
		{
			system("cls");
			arrayOperations->EraseAllArrayData();
			std::cout << "The data was cleared"
				<< std::endl << std::endl;
			break;
		}
		default:
		{
			terminateFlag = true;
		}
		}
	} while (!terminateFlag);
}