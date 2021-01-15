#ifndef TAXDATATYPE_HPP
#define TAXDATATYPE_HPP

#include "TaxConstants.hpp"
using namespace CONSTANT;

//struct that will hold the information of various taxpayers
struct TaxPayer
{
    float taxRate;
    float income;
    float taxes;
};

// create a certain number of taxpayers specified by the value of TAXPAYERS in the namespace CONSTANT
TaxPayer payer[TAXPAYERS];


#endif // TAXDATATYPE_HPP
