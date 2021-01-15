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
#include "Rectangle.hpp"

// constructor for no points
Rectangle::Rectangle()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    x3 = 0;
    y3 = 0;
    x4 = 0;
    y4 = 0;
}

//constructor for four points
Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4)
{
    setCoords(p1, p2, p3, p4);
}

// function to find the length of the rectangle
double Rectangle::length()
{
    double length;
    if (x1 > x2)
    {
        length = x1 - x2;
    }
    else if (x1 < x2)
    {
        length = x2 - x1;
    }
    else
    {
        length = 0;
    }
    return length;
}

// function to find the width of the rectangle
double Rectangle::width()
{
    double width;
    if (y2 > y3)
    {
        width = y2 -y3;
    }
    else if (y2 < y3)
    {
        width = y3 - y2;
    }
    else
    {
        width = 0;
    }
    return width;
}

// function to find the perimeter of the rectangle
double Rectangle::perimeter()
{
    double perimeter;
    perimeter = (length() * 2) + (width() * 2);
    return perimeter;
}

// function to find the area of the rectangle
double Rectangle::area()
{
    double area;
    area = length() * width();
    return area;
}

// if the rectangle is a square, return true. if it isn't a square, return false.
bool Rectangle::square()
{
    if (length() == width())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//function to fill the private members of the class
//it's a bit messy but it works...
void Rectangle::setCoords(Point p1, Point p2, Point p3, Point p4)
{
    if ((p1.getY() == p2.getY()) && (p3.getY() == p4.getY()))
    {
        if ((p1.getX() == p4.getX()) && (p2.getX() == p3.getX()))
        {
            if ((p1.getX() && p1.getY() && p2.getX() && p2.getY() && p3.getX() && p3.getY() && p4.getX() && p4.getY()) >= 0.0)
            {
                if ((p1.getX() && p1.getY() && p2.getX() && p2.getY() && p3.getX() && p3.getY() && p4.getX() && p4.getY()) < 20.0)
                {
                    x1 = p1.getX();
                    y1 = p1.getY();
                    x2 = p2.getX();
                    y2 = p2.getY();
                    x3 = p3.getX();
                    y3 = p3.getY();
                    x4 = p4.getX();
                    y4 = p4.getY();
                }
            }
        }

    }
}
