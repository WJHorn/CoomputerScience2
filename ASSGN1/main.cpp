////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Computer Science 2                                 //
// Spring 2018                                        //
// This program uses a function "deleteRepeat" that   //
// will delete repeating letters in an array of chars.//
////////////////////////////////////////////////////////

//includes to allow use of unique pointer and other useful things
#include <iostream>
#include <memory>

//includes the .cpp file containing the function  deleteRepeats
#include "deleteRepeats.cpp"


std::unique_ptr<char[]> noRepeats(char[]);   // unique pointer for noRepeats


int main()
{
    //code given in the assignment
    char originalArray[SIZE];

    originalArray [0] = 'a';
    originalArray [1] = 'b';
    originalArray [2] = 'b';
    originalArray [3] = 'c';
    originalArray [4] = 'a';
    originalArray [5] = 'c';
    originalArray [6] = 'a';
    originalArray [7] = 'c';
    originalArray [8] = 'b';
    originalArray [9] = 'c';

    // unique pointer for noRepeats
    std::unique_ptr<char[]>noRepeats = deleteRepeats(originalArray);

}
