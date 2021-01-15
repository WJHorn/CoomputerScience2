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

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>

class Point
{
private:
    double x;
    double y;
public:
    //constructors
    Point();
    Point(double new_x, double new_y);
    //functions to set coordinates in the rectangle class
    double getX();
    double getY();
};

#endif // POINT_HPP
