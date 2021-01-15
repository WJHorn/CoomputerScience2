////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Computer Science 2                                 //
// Spring 2018                                        //
// This program uses a function "deleteRepeat" that   //
// will delete repeating letters in an array of chars.//
////////////////////////////////////////////////////////

#ifndef DELETEREPEAT_HPP
#define DELETEREPEAT_HPP

#include <iostream>
#include <memory>

// unnamed namespace containing SIZE
namespace{
    const extern int SIZE = 10;
}

//declaration for deleterRepeats function
std::unique_ptr<char[]> deleteRepeats(char arr[]);

#endif // DELETEREPEAT_HPP
