////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Computer Science 2                                 //
// Spring 2018                                        //
// This program ...                                   //
////////////////////////////////////////////////////////


#ifndef MYSTACK_H
#define MYSTACK_H

//***************************************//
//static stack template                  //
//finish all functions                   //
//***************************************//

#include <iostream>
using namespace std;

template <class T>
class MyStack
{
private:
   T *stackArray;  // Pointer to the stack array
   int stackSize;    // The stack size
   int numElem;		//index of the top element in the stack array

public:
   // Constructor
   MyStack(int);	//pass in an int: tells the maximum size of the stack

   // Copy constructor
   MyStack(const MyStack &);

   //operator= overloading
   MyStack& operator=(const MyStack &);

   // Destructor
   ~MyStack();

   // Stack operations
   void push(T);	//add an item to the stack by passing in a value
   T pop();	//pop a value out by returning the value
   T top();	//return the value at the top position in the stack
   bool isFull() const;	//tell if the stack is full
   bool isEmpty() const;	//tell if the stack is empty
   int size() const;	//tell how many items are in the stack
};

// constructor
template <class T>
MyStack<T>::MyStack(int sizeStack)
{
    stackSize = sizeStack;
    stackArray = new T[sizeStack];
    numElem = -1;
}

// Destructor
template <class T>
MyStack<T>::~MyStack()
{
    delete [] stackArray;
}

// copy constructor
template <class T>
MyStack<T>::MyStack(const MyStack &oldStack)
{
    //create the stack array.
    if (oldStack.stackSize > 0)
    {
        stackArray = new T[oldStack.stackSize];
    }
    else
    {
        stackArray = nullptr;
    }

    //copy the stack size
    stackSize = oldStack.stackSize;

    //copy the stack contents
    for (int i = 0; i < stackSize; i++)
    {
        stackArray[i] = oldStack.stackArray[i];
    }

    // set the top of the stack.
    numElem = oldStack.numElem;
}

// overloaded = operator
template <class T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T> & oldStack)
{
    //create stack array
    if (oldStack.stackSize > 0)
    {
        stackArray = new T[oldStack.stackSize];
    }
    else
    {
        stackArray = nullptr;
    }

    //copy the stack size
    stackSize = oldStack.stackSize;

    //copy the stack contents
    for (int i = 0; i <= stackSize; i++)
    {
        stackArray[i] = oldStack.stackArray[i];
    }

    //set the top of the stack
    numElem = oldStack.numElem;

    //return the object you have created
    return *this;
}

// push function
template <class T>
void MyStack<T>::push(T value)
{
    // don't push if it's full
    if (isFull())
    {
        std::cout << "The stack is full.\n";
    }
    else
    {
        //if it isn't full, add one to the number of elements,
        // then put the value being pushed at that position in
        // the stack array.
        numElem++;
        stackArray[numElem] = value;
    }
}

template <class T>
T MyStack<T>::pop()
{
    // don't pop if the stack is empty
    if (isEmpty())
    {
        std::cout << "The stack is empty.\n";
    }
    else
    {
        //if it isn't empty, set a temporary variable to the
        // value being popped, decrement the topmost element,
        // and return the number being popped.
        int num = stackArray[numElem];
        numElem--;
        return num;
    }
}

// top returns the top item on the stack
template <class T>
T MyStack<T>::top()
{
    // return the topmost item on the stack.
    return stackArray[numElem];
}

//isFull returns true when the stack is full
template <class T>
bool MyStack<T>::isFull() const
{
    if(numElem == stackSize -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// isEmpty returns true when the stack is empty;
template <class T>
bool MyStack<T>::isEmpty() const
{
    if (numElem == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// size function returns the number of discs that are on a peg
template <class T>
int MyStack<T>::size() const
{
    // numelem + 1 because when the stack is empty, numelem is -1
    return numElem + 1;
}

#endif
