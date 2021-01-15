#include "Tax.hpp"
#include "TaxConstants.hpp"
using namespace std;

void taxTaker(float income, float rate, int i)
{
    //find the amount of taxes for the given taxpayer
    float taxes = income * (rate / 100);

    //put the values into the struct
    payer[i].income = income;
    payer[i].taxRate = rate;
    payer[i].taxes = taxes;

}

void taxPrint(int payers)
{
    // print out all of the tax information for all of  the taxpayers
    for (int i = 0; i < payers; i++)
    {
        cout << "Tax Payer # " << (i+1) << ": $";
        cout << payer[i].taxes << ".00" << endl;
    }
}

