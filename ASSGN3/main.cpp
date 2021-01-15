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

using namespace std;

// A Sophisticated Rectangle Class
#include <iostream>
#include <stdexcept>
#include "Rectangle.cpp" // include definition of class Rectangle

int main() {
   Point w{1.0, 1.0};
   Point x{5.0, 1.0};
   Point y{5.0, 3.0};
   Point z{1.0, 3.0};
   Point j{0.0, 0.0};
   Point k{1.0, 0.0};
   Point m{1.0, 1.0};
   Point n{0.0, 1.0};

   Rectangle r1{z, y, x, w};
   std::cout << "Rectangle 1:\n";
   std::cout << "length = " << r1.length();
   std::cout << "\nwidth = " << r1.width();
   r1.perimeter();
   r1.area();
   std::cout << "\nThe rectangle "
      << (r1.square() ? "is" : "is not")
      << " a square.\n";

   Rectangle r2{j, k, m, n};
   std::cout << "\nRectangle 2:\n";
   std::cout << "length = " << r2.length();
   std::cout << "\nwidth = " << r2.width();
   r2.perimeter();
   r2.area();
   std::cout << "\nThe rectangle "
      << (r2.square() ? "is" : "is not")
      << " a square.\n";

}
