////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Computer Science 2                                 //
// Spring 2018                                        //
// This program uses a function "deleteRepeat" that   //
// will delete repeating letters in an array of chars.//
////////////////////////////////////////////////////////

#include <iostream>
#include <memory>
#include "deleteRepeats.hpp"

// deleteRepeats function. it is a unique pointer of type char so that it can return a unique pointer
//  that can then be set to the variable noRepeats in int main
std::unique_ptr<char[]> deleteRepeats(char arr[])
{
    //tells that this is the original array
    std::cout << std::endl << "Here are the values of the original array:" << std::endl;

    //for loop to print out original array
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    int duplicates = 0;

    // filter through the whole array
    for (int i = 0; i < SIZE; i++)
    {
        // loop to compare to all other elements in array
        for (int j = i + 1; j < SIZE; j++)
        {
            // if there is a duplicate that is not a space, delete it and add one to the duplicate counter.
            if (arr[i]==arr[j] && arr[j] != ' ')
            {
                arr[j] = ' ';
                ++duplicates;
            }
        }
    }

    //easier variable to work with for the size of the new dynamic array
    int uniques = SIZE - duplicates;
    //creating the dynamic array as a unique pointer so that it can be returned by the function
    std::unique_ptr<char[]> dynArr(new char[uniques]);
    //counter for the place in the dynamic array
    int k = 0;
    //phrase to seperate new array from original
    std::cout << std::endl << "Here are the contents of the new array: " << std::endl;

    //for loop to iterate through and place any unique elements into the dynamic array
    for (int i = 0; i < SIZE; i++)
    {
        //spaces are not unique. we don't want those in the dynamic array
        if (arr[i] != ' ')
        {
            //set the value in the dynamic array
            dynArr[k] = arr[i];
            // output that value so it can be seen
            std::cout << dynArr[k] << std::endl;
            k++;
        }
    }

    //shows the number of repeats in the original array.
    std::cout << std::endl << "Number of repeats: " << duplicates << std::endl;

    return dynArr;
}
