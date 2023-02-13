/*****************************************************************//**
 * \file   GetIndexOfValueResult.h
 * \brief  Result object from the GetIndexOfValue operation on ArrayOperations
 *
 * \author Mike
 * \date   February 2023
 *********************************************************************/
#pragma once
#ifndef GET_INDEX_OF_VALUE_RESULT_H
#define GET_INDEX_OF_VALUE_RESULT_H

#include <sstream>
#include "OperationResult.h"
class GetIndexOfValueResult : public OperationResult
{
public:
	std::string OperationResult::GetResultSummary()
	{
		std::stringstream ss;

		// If successful, summarize the data
		if (Success)
		{
			ss << "The value " << GetValue();
			if (GetNumberOfIndicesFound() > 1)
				ss << " was located at the following indicies: ";
			else 
				ss << " was located at the following index: "; 
			
			ss << GetIndicesValues() << std::endl;
			return ss.str();
		}
		// If operation failed, summarize the failure and add the error
		else
		{
			ss << "Sorry the value " << GetValue() << " was not found!" << std::endl
				<< "Error: " << Error << std::endl;
			return ss.str();
		}
	};
	// Must be constructed with Result data
	GetIndexOfValueResult(int * indices, int numberOfIndicesFound, int value, bool success, std::string error = "")
		: OperationResult(success, error)
	{
		// initialize variables
		this->indices = indices;
		this->numberOfIndicesFound = numberOfIndicesFound;
		this->value = value;
	}

	std::string GetIndicesValues() 
	{
		std::stringstream ss;
		for (int i = 0; i < numberOfIndicesFound; i++)
		{
			ss << indices[i];
			if (i != numberOfIndicesFound - 1) 
				ss << ", ";
		}

		return ss.str(); 
	};
	int GetValue() { return value; }
	int GetNumberOfIndicesFound() { return numberOfIndicesFound; }
	~GetIndexOfValueResult() { delete indices; }
private:
	int * indices;
	int numberOfIndicesFound;
	int value;
};

#endif