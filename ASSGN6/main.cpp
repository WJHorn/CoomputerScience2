// This program demonstrates the MathStack class.
#include <iostream>
#include "Stack.hpp"


int main()
{
   int catchVar;  // To hold values popped off the stack

   // Create a MathStack object.
   Stack<class T> stack(5);

   //*******************************************************

   // Testing addition
   // Push 3 and 6 onto the stack.
   std::cout << "Pushing 3\n";
   stack.push(3);
   std::cout << "Pushing 6\n";
   stack.push(6);

   // Add the two values.
   stack.add();

   // Pop the sum off the stack and display it.
   std::cout << "The sum is: ";
   stack.pop(catchVar);
   std::cout << catchVar << std::endl << std::endl;
   //*******************************************************

   //Testing subtraction
   // Push 7 and 10 onto the stack
   std::cout << "Pushing 7\n";
   stack.push(7);
   std::cout << "Pushing 10\n";
   stack.push(10);

   // Subtract 7 from 10.
   stack.sub();

   // Pop the difference off the stack and display it.
   std::cout << "The difference is: ";
   stack.pop(catchVar);
   std::cout << catchVar << std::endl << std::endl;
   //*******************************************************

   //Testing multiplication
   // Push 2 and 8 onto the stack
   std::cout << "Pushing 2\n";
   stack.push(2);
   std::cout << "Pushing 8\n";
   stack.push(8);

   //multiply the two values
   stack.mult();

   //pop the product off the stack and display it
   std::cout << "The product is: ";
   stack.pop(catchVar);
   std::cout << catchVar << std::endl << std::endl;
   //*******************************************************

   //Testing division
   // Push 20 and 4 onto the stack
   std::cout << "Pushing 20\n";
   stack.push(20);
   std::cout << "Pushing 4\n";
   stack.push(4);


   // divide the second value by the first
   stack.div();

   //pop the quotient off the stack and display it
   std::cout << "The quotient is: ";
   stack.pop(catchVar);
   std::cout << catchVar << std::endl << std::endl;
   //*******************************************************

   //Testing addAll
   //push a bunch of different variables;
   std::cout << "Pushing 9\n";
   stack.push(9);
   std::cout << "Pushing 4\n";
   stack.push(4);
   std::cout << "Pushing 11\n";
   stack.push(11);
   std::cout << "Pushing 6\n";
   stack.push(6);

   // add all the values together
   std::cout << "Adding all the values together\n";
   stack.addAll();

   //display the sum.
   std::cout << "The sum is: ";
   stack.pop(catchVar);
   std::cout << catchVar << std::endl << std::endl;
   //*******************************************************

   //Testing multAll
   //push 4 variables onto the stack
   std::cout << "Pushing 4\n";
   stack.push(4);
   std::cout << "Pushing 2\n";
   stack.push(2);
   std::cout << "Pushing 8\n";
   stack.push(8);
   std::cout << "Pushing 3\n";
   stack.push(3);

   //multiply all the values in the stack together
   std::cout << "Multiplying all the values together\n";
   stack.multAll();

   //display the product
   std::cout << "The product is: ";
   stack.pop(catchVar);
   std::cout << catchVar << std::endl << std::endl;

   return 0;
}
