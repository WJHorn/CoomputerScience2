#include <iostream>
#include "Tax.cpp"


using namespace std;
using namespace CONSTANT;

int main()
{
    //declare the float variables to be used in the main function
    float income;
    float rate = 0;
    // boolean variable to use for data validation
    bool goodData = false;

    cout << "Please enter the annual income and tax rate for 2 tax payers:" << endl << endl;

    for (int i = 0; i < TAXPAYERS; i++)
    {
        // get the tax payer's income
        cout << endl << endl << "Enter this year's income for tax payer " << (i + 1) << ": ";
        cin >>  income;

        //while loop to validate that the tax rate is valid
        while (goodData == false)
        {
            //get the tax payer's tax rate
            cout << "Enter the tax rate for tax payer # " << (i + 1) << ": ";
            cin >>  rate;
            if ((rate < 0.01) || (rate > 9.9) || cin.fail())
            {
                cin.clear();
                cin.ignore();
                //error message
                cout << "Woah there, buddy. That doesn't seem correct! Let's try that again!" << endl;

            }
            else
            {
                //break out of the while loop
                break;
            }
        }
        taxTaker(income, rate, i);   //input for taxpayer
    }

    cout << "Taxes due for this year:" << endl << endl;

    taxPrint(TAXPAYERS); // output for the taxpayers
}
