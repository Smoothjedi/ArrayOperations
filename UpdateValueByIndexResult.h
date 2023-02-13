/*****************************************************************//**
 * \file   UpdateValueByIndexResult.h
 * \brief  A result from the RemoveValueByIndex operation in ArrayOperations
 *
 * \author Mike
 * \date   February 2023
 *********************************************************************/
#pragma once
#include <sstream>
#include "OperationResult.h"

class UpdateValueByIndexResult : public OperationResult
{
public:

	std::string OperationResult::GetResultSummary()
	{
		std::stringstream ss;

		// If successful, summarize the data
		if (Success)
		{
			ss << "The Value " << GetOldValue() << " at index " << GetIndex()
				<< " was changed to " << GetNewValue();

			return ss.str();
		}
		// If operation failed, summarize the failure and add the error
		else
		{
			ss << "Sorry the operation on index " << GetIndex() <<" was not successful!" << std::endl;
			// Only add error line if there is an error given
			if (!Error.empty())
				ss << "Error: " << Error << std::endl;
			return ss.str();
		}
	};
	// Must be constructed with Result data
	UpdateValueByIndexResult(int index, int newValue, bool success, int oldValue = 0, std::string error = "")
		: OperationResult(success, error)
	{
		// initialize variables
		this->index = index;
		this->newValue = newValue;
		this->oldValue = oldValue;
	}

	int GetIndex() { return index; }
	int GetOldValue() { return oldValue; }
	int GetNewValue() { return newValue; }
private:
	int index;
	int newValue;
	int oldValue;
};