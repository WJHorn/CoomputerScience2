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



#endif // STACK_HPP_INCLUDED
