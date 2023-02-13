/*****************************************************************//**
 * \file   RemoveValueByIndexResult.h
 * \brief  A result from the RemoveValueByIndex operation in ArrayOperations
 * 
 * \author Mike
 * \date   February 2023
 *********************************************************************/
#pragma once
#ifndef REMOVE_VALUE_BY_INDEX_RESULT_H
#define REMOVE_VALUE_BY_INDEX_RESULT_H

#include <sstream>
#include "OperationResult.h"
class RemoveValueByIndexResult : public OperationResult
{
public:
	std::string OperationResult::GetResultSummary()
	{
		std::stringstream ss;
		// If successful, summarize the data
		if (Success)
		{
			ss << "The Value " << GetOldValue() << " at index " << GetIndex()
				<< " was removed " << std::endl;

			return ss.str();
		}
		// If operation failed, summarize the failure and add the error
		else
		{
			ss << "Sorry the value at index " << GetIndex()
				<< " was not successfully removed!" << std::endl;
			// Only add error line if there is an error given
			if (!Error.empty())
				ss << "Error: " << Error << std::endl;
			return ss.str();
		}
	};
	// Must be constructed with Result data
	RemoveValueByIndexResult(int index, int oldValue, bool success, std::string error = "")
		: OperationResult(success, error)
	{
		// initialize variables
		this->index = index;
		this->oldValue = oldValue;
	}

	// Must be constructed with Result data
	RemoveValueByIndexResult(std::string error, int index, bool success)
		: OperationResult(success, error)
	{
		// initialize variables
		this->index = index;
		this->oldValue = 0;
	}

	int GetIndex() { return index; }
	int GetOldValue() { return oldValue; }
private:
	int index;
	int oldValue;
};

#endif
