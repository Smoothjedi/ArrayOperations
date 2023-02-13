/*****************************************************************//**
 * \file   LoadArrayDataFromCsvResult.h
 * \brief  A result from the LoadArrayDataFromCsv operation in ArrayOperations
 *
 * \author Mike
 * \date   February 2023
 *********************************************************************/
#pragma once
#ifndef LOAD_ARRAY_DATA_FROM_CSV_RESULT_H
#define LOAD_ARRAY_DATA_FROM_CSV_RESULT_H

#include <sstream>
#include "OperationResult.h"
class LoadArrayDataFromCsvResult : public OperationResult
{
public:
	std::string OperationResult::GetResultSummary()
	{
		std::stringstream ss;
		// If successful, summarize the data
		if (Success)
		{
			ss << numberOfItems << " integers were successfully loaded from " << GetFilename() << std::endl
				<< "There are now " << GetNumberOfItems() << " in the array after " << GetAmountAdded() << " were added."
				<< std::endl;

			return ss.str();
		}
		// If operation failed, summarize the failure and add the error
		else
		{
			ss << "Sorry " << GetAmountAdded() << " values were loaded from " << GetFilename() << std::endl
				<< "There are currently " << GetNumberOfItems() << " in the array." << std::endl;
			// Only add error line if there is an error given
			if (!Error.empty())
				ss << "Error: " << Error << std::endl;
			return ss.str();
		}
	};
	// Must be constructed with Result data
	LoadArrayDataFromCsvResult(std::string filename, int numberOfItems, int amountAdded, bool success, std::string error = "")
		: OperationResult(success, error)
	{
		// initialize variables
		this->filename = filename;
		this->numberOfItems = numberOfItems;
		this->amountAdded = amountAdded;
	}

	std::string GetFilename() { return filename; }
	int GetNumberOfItems() { return numberOfItems; }
	int GetAmountAdded() { return amountAdded; }

private:
	std::string filename;
	int numberOfItems;
	int amountAdded;
};

#endif
