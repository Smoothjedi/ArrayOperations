/*****************************************************************//**
 * \file   AppendValueResult.h
 * \brief  Result object from the AppendValue operation on ArrayOperations
 * 
 * \author Mike
 * \date   February 2023
 *********************************************************************/
#pragma once
#include <sstream>
#include "OperationResult.h"
class AppendValueResult : public OperationResult
{
public:
	std::string OperationResult::GetResultSummary()
	{
		std::stringstream ss;

		// If successful, summarize the data
		if (Success)
		{
			ss << "The value " << GetValue() << " was appended at index " << GetIndex();
				

			return ss.str();
		}
		// If operation failed, summarize the failure and add the error
		else
		{
			ss << "Sorry the value " << GetValue() << " was not successfully appended!" << std::endl;
			// Only add error line if there is an error given
			if (!Error.empty())
				ss << "Error: " << Error << std::endl;
			return ss.str();
		}
	};
	// Must be constructed with Result data
	AppendValueResult(int index, int value, bool success, std::string error = "")
		: OperationResult(success, error)
	{
		// initialize variables
		this->index = index;
		this->value = value;
	}

	int GetIndex() { return index; };
	int GetValue() { return value; };

private:
	int index;
	int value;
};

