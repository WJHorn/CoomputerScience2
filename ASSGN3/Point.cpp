////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Computer Science 2                                 //
// Spring 2018                                        //
// This program contains a class called Rectangle     //
//  that only stores four x and y coords.             //
//  this class has 6 public member functions.         //
//  the x and y coords. cannot be greater than 20.    //
////////////////////////////////////////////////////////

#include <iostream>
#include "Point.hpp"

//constructor with no data
Point::Point()
{
    x = 0;
    y = 0;
}

//constructor with x and y coordinates
Point::Point(double new_x, double new_y)
{
    x = new_x;
    y = new_y;
}

// return x coordinate for that point
double Point::getX()
{
    return x;
}

// return y coordinate for that point
double Point::getY()
{
    return y;
}
