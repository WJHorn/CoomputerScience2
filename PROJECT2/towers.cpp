////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Computer Science 2                                 //
// Spring 2018                                        //
// This program ...                                   //
////////////////////////////////////////////////////////


#include <iostream>
#include "towers.h"
#include "mystack.h"

using namespace std;
// Constructor
Towers::Towers(int disks)
{
    numDisk = disks;
    setDisks();
}

// Destructor
Towers::~Towers()
{
    delete &numDisk;
}

// Copy Constructor
Towers::Towers(const Towers &tower)
{
    // copy all values to the new object's address
    numDisk = tower.numDisk;
    peg1 = tower.peg1;
    peg2 = tower.peg2;
    peg3 = tower.peg3;
}

// Overloaded = operator
Towers& Towers::operator=(const Towers &tower)
{
    // copy all values
    numDisk = tower.numDisk;
    peg1 = tower.peg1;
    peg2 = tower.peg2;
    peg3 = tower.peg3;
    // return the new object
    return *this;
}

// Initialize placement of the towers
void Towers::setDisks()
{
    // dynamically allocate the pegs.
    peg1 = new MyStack<int>(numDisk);
    peg2 = new MyStack<int>(numDisk);
    peg3 = new MyStack<int>(numDisk);

    //fill the first peg with discs , bottom being the largest, top being the smallest
    for (int i = numDisk; i > 0; i--)
    {
        peg1->push(i);
    }
}

// Function to move the discs around
void Towers::move(int n, MyStack<int>* s, MyStack<int>* t, MyStack<int>* d)
{
    // before peg2 has 3 discs on it
    while (peg2->size() != (numDisk - 1))
    {
        plotPegs();         //print out status of the pegs
        moveOne(s, t);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(s, d);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(t, d);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(s, t);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(d, s);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(d, t);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(s, t);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
    }
    // before peg 3 has 4 discs on it
    while (!(peg3->isFull()))
    {
        moveOne(s, d);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(t, d);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(t, s);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(d, s);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(t, d);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(s, t);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(s, d);          //move a disc from one peg to the next
        plotPegs();         //print out status of the pegs
        moveOne(t, d);          //move a disc from one peg to the next
    }
    plotPegs();             //print out status of the pegs
}

// function to move one disc from tower s to tower d
void Towers::moveOne(MyStack<int>* s, MyStack<int>* d)
{
    d->push(s->pop());
}

//display disks on the three pegs in the console window (stdout)
//DO NOT MODIFY THIS FUNCTION
void Towers::plotPegs()
{
  	if (peg1==NULL || peg2==NULL || peg3==NULL) return;

	int n1=peg1->size();
	int n2=peg2->size();
	int n3=peg3->size();
	int numDisk = n1+n2+n3;

	MyStack<int> tmp1(*peg1);
	MyStack<int> tmp2(*peg2);
	MyStack<int> tmp3(*peg3);

	//plot
	for (int i=0; i<numDisk; i++) {
		//peg1
		if (numDisk-n1-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m1 = tmp1.top();
			tmp1.pop();
			for (int j=0; j<m1; j++)
				cout << "*";
			for (int j=m1; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg2
		if (numDisk-n2-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m2 = tmp2.top();
			tmp2.pop();
			for (int j=0; j<m2; j++)
				cout << "*";
			for (int j=m2; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg3
		if (numDisk-n3-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m3 = tmp3.top();
			tmp3.pop();
			for (int j=0; j<m3; j++)
				cout << "*";
			for (int j=m3; j<numDisk; j++)
				cout << " ";
		}
		cout<<endl;
	}
	cout << "_________________________________________\n";
}
