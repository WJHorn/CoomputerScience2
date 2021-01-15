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
   pop(sum);
   pop(num);

   // Add the two values, store in sum.
   sum += num;

   // Push sum back onto the stack.
   push(sum);
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
   pop(diff);
   pop(num);

   // Subtract num from diff.
   diff -= num;

   // Push diff back onto the stack.
   push(diff);
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
    pop(num);
    pop(prod);

    //multiply them together
    prod *= num;

    //push the product back onto the stack
    push(prod);
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
    pop(denom);
    pop(num);

    //divide the second by the first
    quot = num / denom;

    //push the quotiont back onto the stack
    push(quot);
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
        pop(num);
        sum += num;
    }
    push(sum);
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
        pop(num);
        prod *= num;
    }
    push(prod);
}

