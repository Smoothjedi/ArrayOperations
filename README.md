# ArrayOperations
ArrayOperations Homework 1 CS303
This project is intended to showcase operations that are possible with an array. This is my first time using Git, so I apologize if the formatting here isn't perfect!
There are several classes involved with the operations. ArrayOperationsController.cpp contains the int main code, which instantiates ArrayOperations.
ArrayOperations contains the array and the operations that can be peformed on it.
The array begins with a capacity of 100 and 0 entries.
There are ten options to choose from once the program begins:
![ArrayOperations](../assets/Startup.png?raw=true)
A good place to start is by loading data from a CSV. A test file, TestData.csv has been provided. 
![ArrayOperations](../assets/LoadDataFromCSV.png?raw=true)
If a bad file name is given or values cannot be added, and error will be shown:
![ArrayOperations](../assets/LoadDataFromCSV_failure.png?raw=true)
Next we can look for a value within the array by picking an index. I chose 23:
![ArrayOperations](../assets/GetValueAtIndex_success.png?raw=true)
If an invalid index is selected, an error will appear displaying the valid options for an index:
![ArrayOperations](../assets/GetValueAtIndex_failure.png?raw=true)
Now that we have our value of 1225 at index 23, we can search the other direction for the index:
![ArrayOperations](../assets/GetIndexOfValue_success.png?raw=true)
If we had searched for a value that is not in the array, we would get an error:
![ArrayOperations](../assets/GetIndexOfValue_failure.png?raw=true)
Next we can Append a value to the end of the array. I will choose a duplicate value:
![ArrayOperations](../assets/AppendValue_success.png?raw=true)
Now when we search for the index of the value, we will have both returned:
![ArrayOperations](../assets/GetIndexOfValue_success-MultipleResults.png?raw=true)
Next we can remove the first value:
![ArrayOperations](../assets/RemoveValueAtIndex_success.png?raw=true)
Now we see that the value is only found at 99, which is one less than its original position because the values were shifted left.
![ArrayOperations](../assets/GetIndexOfValue_AfterRemoval.png?raw=true)
If we were try to remove a value with an invalid index, we would have received an error:
![ArrayOperations](../assets/RemoveValueByIndex_failure.png?raw=true)
We can now query the current capacity to see that the array has expanded its capacity:
![ArrayOperations](../assets/GetCurrentCapacityAfterAppend.png?raw=true)



