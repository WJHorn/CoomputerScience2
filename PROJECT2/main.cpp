////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Computer Science 2                                 //
// Spring 2018                                        //
// This program ...                                   //
////////////////////////////////////////////////////////


// towerofhanoi.cpp : Defines the entry point for the console application.
//DO NOT MODIFY THIS FILE

#include <iostream>
#include "towers.h"

using namespace std;

int main()
{
	int numDisk = 4;
	Towers t(numDisk);
	t.start();
	return 0;
}

