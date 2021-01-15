// Member-function definitions for class Complex.
#include <iostream>
#include <sstream> // for ostringstream class
#include "Complex.hpp"

// these are never really used and i'm not quite sure why they're here...
Complex::Complex(double real, double imaginary)
   : realPart(real), imaginaryPart(imaginary) { }

Complex Complex::add(const Complex &right) const
{
   return Complex(
      realPart + right.realPart, imaginaryPart + right.imaginaryPart);
}

Complex Complex::subtract(const Complex &right) const
{
   return Complex(realPart - right.realPart, imaginaryPart - right.imaginaryPart);
}

Complex Complex::multiply(const Complex &right) const
{
   return Complex((realPart * right.realPart) - (imaginaryPart * right.imaginaryPart),
                  (imaginaryPart * right.imaginaryPart) + (realPart * right.realPart));
}

void Complex::setComplexNumber(double rp, double ip)
{
   realPart = rp;
   imaginaryPart = ip;
}

//here is the useful overloaded + operator
Complex Complex::operator+(Complex a)
{
    return Complex((realPart + a.realPart), (imaginaryPart + a.imaginaryPart));
}

//overloaded - operator
Complex Complex::operator-(Complex a)
{
    return Complex((realPart - a.realPart), (imaginaryPart - a.imaginaryPart));
}

//overloaded = operator
Complex Complex::operator=(Complex a)
{
    return Complex((realPart = a.realPart), (imaginaryPart = a.imaginaryPart));
}

//overloaded * operator
Complex Complex::operator*(Complex a)
{
    return Complex(((realPart * a.realPart) - (imaginaryPart * a.imaginaryPart)),
                  ((realPart * a.imaginaryPart) + (imaginaryPart * a.realPart)));

}

//overloaded << operator
std::ostream& operator<<(std::ostream& os, Complex& a)
{
    os << a.realPart << " + " << a.imaginaryPart << " * i" << std::endl;
    return os;
}

//overloaded >> operator
std::istream& operator>>(std::istream& is, Complex& a)
{
    is >> a.realPart >> a.imaginaryPart;
    return is;
}

//overloaded == operator
bool Complex::operator==(Complex a)
{
    if((realPart == a.realPart) && (imaginaryPart == a.imaginaryPart))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//overloaded != operator
bool Complex::operator!=(Complex a)
{
    if ((realPart != a.realPart) || (imaginaryPart != a.imaginaryPart))
    {
        return true;
    }
    else
    {
        return false;
    }
}
