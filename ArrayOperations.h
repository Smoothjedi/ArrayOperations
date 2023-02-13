/*****************************************************************//**
 * \file   ArrayOperations.h
 * \brief  Operations class that has functions built for manipulating data in an array.
 * 
 * \author Mike
 * \date   February 2023
 *********************************************************************/
#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include "ArrayOperations.h"
#include "UpdateValueByIndexResult.h"
#include "AppendValueResult.h"
#include "RemoveValueByIndexResult.h"
#include "LoadArrayDataFromCsvResult.h"
#include "GetIndexOfValueResult.h"
#include "GetValueAtIndexResult.h"
#include "LoadRandomArrayDataResult.h"

class ArrayOperations 
{
public:
	ArrayOperations();
	~ArrayOperations() { delete[] IntegerArray;	};
	int GetCurrentCapacity() const;
	int GetCurrentNumberOfItems() const;
	GetIndexOfValueResult* GetIndexOfValue(int value) const;
	GetValueAtIndexResult* GetValueAtIndex(int index) const;
	LoadRandomArrayDataResult* LoadRandomArrayData(int seed, int amount);
	LoadArrayDataFromCsvResult* LoadArrayDataFromCsv(std::string pathToFile);
	RemoveValueByIndexResult* RemoveValueByIndex(int index);
	UpdateValueByIndexResult* UpdateValueByIndex(int value, int index);
	AppendValueResult* AppendValue(int value);
	void EraseAllArrayData();
private:
	const int initialCapacity = 100;
	int numberOfItems;
	int currentCapacity;
	int* IntegerArray;
	void ResizeArray();
};

#endif