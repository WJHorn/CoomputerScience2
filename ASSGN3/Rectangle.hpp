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

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include "Point.cpp"

class Rectangle
{
private:
    // different Cartesian coordinates (p1 has x1 and y1 ...)
    double x1, y1;
    double x2, y2;
    double x3, y3;
    double x4, y4;
public:
    //constructors
    Rectangle();
    Rectangle(Point p1, Point p2, Point p3, Point p4);
    //function to verify that the rectangle is a rectangle, and
    //that the points are non-negative, and that they are not
    //greater than 20
    void setCoords(Point p1, Point p2, Point p3, Point p4);
    //functions for length
    double length();
    //functions for width
    double width();
    //functions for perimeter
    double perimeter();
    //functions for area
    double area();
    //function to find if the rectangle is a square
    bool square();

};

#endif // RECTANGLE_HPP
