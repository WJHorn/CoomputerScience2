/*
   COPYRIGHT (C) 2018 William Horn (wjh27) All rights reserved.
   CS assignment
   Author.  Will Horn
            wjh27@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program demonstrates both recursive and iterative uses
            for displaying the Fibonacci numbers. It also demonstrates a recursive quick sort.
*/
#include <iostream>

// prototypes
template <class T>
void printarray(const T[], int);
void chew_system_stack();

/*
 * Recursive version of fibonacci
 */
int fibrecurse(int n) {

    // if n is 0, return the first element (0)
    if (n == 0)
    {
        return 0;
    }
    // if n is 1, then return the second element (1)
    if (n == 1)
    {
        return 1;
    }
    // if n is not 0 or 1, then recursively call the function until the n'th number has been calculated.
    else
    {
        return (fibrecurse(n - 1) + fibrecurse(n - 2));
    }
}

/*
 * Iterative (loop) version of fibonacci
 */
int fibiterate(int n) {
    int temp, t1 = 0, t2 = 1;

    // if n is 0, then return the first element
    if (n == 0)
    {
        return t1;
    }
    // if n is 1, then return the second element
    else if (n == 1)
    {
        return t2;
    }

    // for loop to find the n'th value
    for (int i = 2; i <= n; i++)
    {
        temp = t1 + t2;
        t1 = t2;
        t2 = temp;
    }
    // return the n'th value
    return t2;

}
/*
 * Recursive quicksort
 */
template <class T>
void quicksort(T ar[], int first, int last) {
    // variables to help sort
    int a = first;
    int b = last;
    // using the template so that the any type can be stored to tmp
    T tmp;

    // find the mid point of the array.
    int middle = ar[(first + last) / 2];

    // run while a and b are less than one another
    while (a <= b)
    {
        // move a one to the right while it is still less than the middle
        while (ar[a] < middle)
        {
            a++;
        }
        // move b one to the left while it is still less than the middle
        while (ar[b] > middle)
        {
            b--;
        }
        // if the left side is less than or equal to the right side,
        //  swap the values.
        if (a <= b)
        {
            tmp = ar[a];
            ar[a] = ar[b];
            ar[b] = tmp;
            a++;
            b--;
        }
    }

    // recursive call
    if (first < b)
    {
        quicksort(ar, first, b);
    }
    if (a < last)
    {
        quicksort(ar, a, last);
    }

}

int main() {
    const int FIBLOOPS = 10;
    const int ARSIZ = 16;
    int ar[ARSIZ];

    std::cout << "Recursive fib: ";
    for(int i = 0; i < FIBLOOPS; ++i)
    {
        std::cout << fibrecurse(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Iterative fib: ";
    for(int i = 0; i < FIBLOOPS; ++i)
    {
        std::cout << fibiterate(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Quicksort:" << std::endl;
    // populate random array
    for(int i = 0; i < ARSIZ; ++i)
    {
        ar[i] = (i * 3037) % 2099;  // prime numbers! again!
    }
    printarray(ar, ARSIZ);
    quicksort(ar, 0, ARSIZ-1);
    printarray(ar, ARSIZ);

    //std::cout << "Chewing system stack:" << std::endl;
    //chew_system_stack();

    return 0;
}

/*  utility functions, do not modify  */
template <class T>
void printarray(const T ar[], int s)
{
    for(int i = 0; i < s; ++i)
    {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}

void printstackpointer()
{
    void * stack_pointer;
    // inline assembly language to get stack pointer
    __asm__ __volatile__("movl  %%esp,%%eax"
                             :"=a"(stack_pointer)
                             );
    std::cout << stack_pointer << std::endl;
}

void chew_system_stack()
{
    // Feel free to play with this, but please
    // do NOT enable this for your final commit!
    printstackpointer();
    chew_system_stack();
}
/* end utilities */
