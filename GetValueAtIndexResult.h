/*****************************************************************//**
 * \file   GetValueAtIndexResult.h
 * \brief  Result object from the AppendValue operation on ArrayOperations
 *
 * \author Mike
 * \date   February 2023
 *********************************************************************/
#pragma once
#include <sstream>
#include "OperationResult.h"
class GetValueAtIndexResult : public OperationResult
{
public:
	std::string OperationResult::GetResultSummary()
	{
		std::stringstream ss;

		// If successful, summarize the data
		if (Success)
		{
			ss << "The value at index " << GetIndex() << " is: " << GetValue() << std::endl;
			return ss.str();
		}
		// If operation failed, summarize the failure and add the error
		else
		{
			ss << "Sorry the value at index " << GetIndex() << " was not found!" << std::endl;
			// Only add error line if there is an error given
			if (!Error.empty())
				ss << "Error: " << Error << std::endl;
			return ss.str();
		}
	};
	// Must be constructed with Result data
	GetValueAtIndexResult(int index, int value, bool success, std::string error = "")
		: OperationResult(success, error)
	{
		// initialize variables
		this->index = index;
		this->value = value;
	}
	GetValueAtIndexResult(int index, bool success, std::string error = "")
		: OperationResult(success, error)
	{
		// initialize variables
		this->index = index;
	}

	int GetValue() { return value; }
	int GetIndex() { return index; }
private:
	int index;
	int value;
};

