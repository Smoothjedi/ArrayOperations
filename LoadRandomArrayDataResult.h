/*****************************************************************//**
 * \file   LoadRandomArrayDataResult.h
 * \brief  Result object from the LoadRandomArrayData operation in ArrayOperations
 *
 * \author Mike
 * \date   February 2023
 *********************************************************************/
#pragma once
#include <sstream>
#include "OperationResult.h"
class LoadRandomArrayDataResult : public OperationResult
{
public:
	std::string OperationResult::GetResultSummary()
	{
		std::stringstream ss;

		// If successful, summarize the data
		if (Success)
		{
			ss << GetAmount();
			if (GetAmount() > 1) ss << " values were ";
			else ss << "value was ";
			ss << "generated with seed : " << GetSeed() << std::endl;
			return ss.str();
		}
		// If operation failed, summarize the failure and add the error
		else
		{
			if (GetAmount() > 0)
				ss << "Not all data could be loaded. Managed to add " << GetAmount() << " values with seed: ";
			else 
				ss << "Sorry no data could not be generated with seed: ";
			ss << GetSeed() << std::endl;
			// Only add error line if there is an error given
			if (!Error.empty())
				ss << "Error: " << Error << std::endl;
			return ss.str();
		}
	};
	// Must be constructed with Result data
	LoadRandomArrayDataResult(int seed, int amount, bool success, std::string error = "")
		: OperationResult(success, error)
	{
		// initialize variables
		this->seed = seed;
		this->amount = amount;
	}

	int GetSeed() { return seed; }
	int GetAmount() { return amount; }
private:
	int seed;
	int amount;
};