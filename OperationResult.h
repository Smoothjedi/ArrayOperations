/*****************************************************************//**
 * \file   OperationResult.h
 * \brief  Base class to be returned that contains results from ArrayOperations
 * 
 * \author Mike
 * \date   February 2023
 *********************************************************************/
#pragma once
#ifndef OPERATION_RESULT_H
#define OPERATION_RESULT_H

#include <string>

class OperationResult
{
public:
	// Creates a string that summarizes the relevant data for the result
	virtual std::string GetResultSummary() =0;
	virtual ~OperationResult() {}
	// Determines if operation was successful
	bool Success;
	// Error message to describe a problem
	std::string Error;
	// Must be constructed with Result data
	OperationResult(bool success, std::string error)
	{
		// initialize variables
		this->Error = error;
		this->Success = success;
	}
};

#endif