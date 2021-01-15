#ifndef STACK_HPP
#define STACK_HPP
#include "NumStack.hpp"
template <class T>
class Stack : public NumStack<T>
{
public:
   // Constructor
   Stack(int s) : NumStack<T>(s) {}

   // MathStack operations

   void add();
   void sub();

   // operations added by myself
   void mult();
   void div();
   void addAll();
   void multAll();
};

/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CSII assignment
   Author.  Student Name
            zippy@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program ...
*/
#include "Stack.hpp"

//***********************************************
// Member function add. add pops                *
// the first two values off the stack and       *
// adds them. The sum is pushed onto the stack. *
// pre: no parameters                           *
// post: return the  new stack entry of sum     *
//***********************************************
template <class T>
void Stack<T>::add()
{
   T num, sum;

   // Pop the first two values off the stack.
   this->pop(sum);
   this->pop(num);

   // Add the two values, store in sum.
   sum += num;

   // Push sum back onto the stack.
   this->push(sum);
}

//***********************************************
// Member function sub. sub pops the            *
// first two values off the stack. The          *
// second value is subtracted from the          *
// first value. The difference is pushed        *
// onto the stack.                              *
// pre: no parameters                           *
// post: return the  new stack entry of diff    *
//***********************************************
template <class T>
void Stack<T>::sub()
{
   T num, diff;

   // Pop the first two values off the stack.
   this->pop(diff);
   this->pop(num);

   // Subtract num from diff.
   diff -= num;

   // Push diff back onto the stack.
   this->push(diff);
}

//************************************************
// mult member function:                         *
//  pops the top two values off the stack,       *
//  multiplies them, and pushes their product    *
//  onto the stack                               *
//************************************************
template <class T>
void Stack<T>::mult()
{
    T num, prod;

    //pop the first two values off the stack
    this->pop(num);
    this->pop(prod);

    //multiply them together
    prod *= num;

    //push the product back onto the stack
    this->push(prod);
}

//************************************************
// div member function:                          *
//  Pops the top two values off the stack,       *
//  divides the second value by the first, and   *
//  pushes the quotient onto the stack.          *
//************************************************
template <class T>
void Stack<T>::div()
{
    T num, denom, quot;

    //pop off the first two values
    this->pop(denom);
    this->pop(num);

    //divide the second by the first
    quot = num / denom;

    //push the quotiont back onto the stack
    this->push(quot);
}

//************************************************
// addAll member function:                       *
//  Pops all values off the stack, adds them,    *
//  and pushes their sum onto the stack.         *
//************************************************
template <class T>
void Stack<T>::addAll()
{
    T num, sum = 0;
    while(!this->isEmpty())
    {
        this->pop(num);
        sum += num;
    }
    this->push(sum);
}

//************************************************
// multAll member function:                      *
//  pops all values off the stack, multiplies    *
//  them, and pushes their product onto the      *
//  stack                                        *
//************************************************
template <class T>
void Stack<T>::multAll()
{
    T num, prod = 1;
    while(!this->isEmpty())
    {
        this->pop(num);
        prod *= num;
    }
    this->push(prod);
}



#endif // STACK_HPP_INCLUDED
