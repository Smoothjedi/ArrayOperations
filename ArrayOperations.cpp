/*****************************************************************//**
 * \file   ArrayOperations.cpp
 * \brief  
 * 
 * \author Mike
 * \date   February 2023
 *********************************************************************/
#include "ArrayOperations.h"

using namespace std;

ArrayOperations::ArrayOperations()
{
    IntegerArray = new int[initialCapacity];
    numberOfItems = 0;
    currentCapacity = initialCapacity;
}

int ArrayOperations::GetCurrentCapacity() const
{
    return currentCapacity;
}

int ArrayOperations::GetCurrentNumberOfItems() const
{
    return numberOfItems;
}

GetIndexOfValueResult * ArrayOperations::GetIndexOfValue(int value) const
{
    int* indices = new int[numberOfItems];
    int numberOfIndicesFound = 0;
    // Cycle through the array looking for the given value
    for (int i = 0; i < numberOfItems; i++)
    {
        // if found, return the index of the given value
        if (IntegerArray[i] == value)
        {
            indices[numberOfIndicesFound] = i;
            numberOfIndicesFound++;
        }
    }
    // return an impossible index if not found
    if (numberOfIndicesFound > 0)
        return new GetIndexOfValueResult(indices, numberOfIndicesFound, value, true);
    else 
        return new GetIndexOfValueResult(indices, numberOfIndicesFound, value, false, 
            "That value was not found in the array.");

}

GetValueAtIndexResult * ArrayOperations::GetValueAtIndex(int index) const
{
    try
    {
        if (numberOfItems == 0)
            throw std::exception("Array is empty!");
        if (index >= numberOfItems || index < 0)
        {
            // generate error message
            stringstream ss;
            ss << "Invalid index. ";
            if (numberOfItems == 1)
                ss << "The only valid index is 0.";
            else ss << "Index must be between 0 and " << numberOfItems - 1;

            throw std::exception(ss.str().c_str());
        }
        return new GetValueAtIndexResult(index, IntegerArray[index], true);
    }
    catch (std::exception& error)
    {
        // If an exception caught, populate result class with error
        return new GetValueAtIndexResult(index, 0, false, error.what());
    }

}

UpdateValueByIndexResult * ArrayOperations::UpdateValueByIndex(int value, int index)
{
    try 
    {
        // If we are updating values, only allow existing records to be modified
        if (index >= numberOfItems || index < 0)
            throw std::exception("No value at index.");
        int oldValue = IntegerArray[index];
        IntegerArray[index] = value;
        // Return multiple data by populating result class
        return new UpdateValueByIndexResult(index, value, true, oldValue);
    }
    catch (std::exception &error)
    {
        // If an exception caught, populate result class with error
        return new UpdateValueByIndexResult(index, value, false, 0, error.what());
    }
}

AppendValueResult * ArrayOperations::AppendValue(int value)
{
    try
    {
        // Zero is not a valid value to search for
        if (value == 0)
            throw std::exception("Zero is not a valid value");
        // if full, we resize and try again. 
        if (numberOfItems == currentCapacity)
        {
            ResizeArray();
            AppendValue(value);
        }
        // Otherwise we set the value and increment the number of items
        else
        {
            IntegerArray[numberOfItems] = value;
            numberOfItems++;
        }
        // Return result object
        return new AppendValueResult(numberOfItems - 1, value, true);
    }
    catch (std::exception& error)
    {
        // If an exception caught, populate result class with error
        return new AppendValueResult(numberOfItems - 1, value, false, error.what());
    }
}

RemoveValueByIndexResult* ArrayOperations::RemoveValueByIndex(int index)
{
    try
    {
        // ensure given index is valid
        if (index >= numberOfItems || index < 0)
            throw std::exception("No value at that index");
        // temporarily save old value
        int oldValue = IntegerArray[index];
        // shift values starting one higher than the target down
        for (int i = index + 1; i < numberOfItems; i++)
            IntegerArray[i - 1] = IntegerArray[i];
        // reduce the number of items
        numberOfItems--;
        // return result response
        return new RemoveValueByIndexResult(index, oldValue, true);
    }
    catch (std::exception& error)
    {
        // If an exception caught, populate result class with error
        return new RemoveValueByIndexResult(error.what(), index, false);
    }
}

LoadRandomArrayDataResult * ArrayOperations::LoadRandomArrayData(int seed, int amount)
{
    int amountPopulated = 0;
    try
    {
        if (amount < 1)
            throw std::exception("Must request at least 1 value to be added.");

        srand(seed);
        // populate array with random values
        for (int i = 0; i < amount; i++)
        {
            int randomValue = rand();
            OperationResult* result = AppendValue(randomValue);
            if (!result->Success)
            {
                stringstream ss;
                ss << "Unable to append " << randomValue << std::endl
                    << result->Error;
                delete result;
                throw std::exception(ss.str().c_str());
            }
            else
            {
                amountPopulated++;
                delete result;
            }
        }
        return new LoadRandomArrayDataResult(seed, amountPopulated, true);
    }
    catch (std::exception &error)
    {
        return new LoadRandomArrayDataResult(seed, amountPopulated, false, error.what());
    }
}

LoadArrayDataFromCsvResult* ArrayOperations::LoadArrayDataFromCsv(std::string filename)
{
    // tracking how many values get added
    int amountAdded = 0;

    std::string line;

    try 
    {
        std::ifstream csvFile(filename);
        // Read lines from file
        if (!csvFile.good())
            throw std::exception("File not found!");
        while (getline(csvFile, line))
        {
            std::stringstream sStream(line);
            // read string line and split with delimiter
            while (getline(sStream, line, ','))
            {
                // convert string to int and append value
                AppendValue(std::stoi(line));
                amountAdded++;
            }
        }
        // close the file
        csvFile.close();
        return new LoadArrayDataFromCsvResult(filename, numberOfItems, amountAdded, true);
    }
    catch (std::exception& error)
    {
        // If an exception caught, populate result class with error
        return new LoadArrayDataFromCsvResult(filename, numberOfItems, amountAdded, false, error.what());
    }
}

void ArrayOperations::ResizeArray()
{
    // double the size of the array
    currentCapacity *= 2;
    int* newArray = new int[currentCapacity];
    // copy data from old array to new one
    for (int i = 0; i < numberOfItems; i++)
        newArray[i] = IntegerArray[i];
    // delete old data
    delete[] IntegerArray;
    // update pointer to the new array
    IntegerArray = newArray;
}

void ArrayOperations::EraseAllArrayData()
{
    // create new, empty array
    int* newArray = new int[initialCapacity];
    // delete old data
    delete[] IntegerArray;
    // update pointer to the new array
    IntegerArray = newArray;
    // clear number of items
    numberOfItems = 0;
}
