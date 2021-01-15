#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <string>

class Complex
{
public:
   Complex(double = 0.0, double = 0.0); // default constructor
   Complex add(const Complex&) const;			  // function add
   Complex subtract(const Complex&) const; // function subtract
   Complex multiply(const Complex&) const; // function multiply
   void setComplexNumber(double, double); // set complex number

   //overloaded operators
   Complex operator+(Complex a);
   Complex operator-(Complex a);
   Complex operator=(Complex a);
   Complex operator*(Complex a);
   //friend functions because they won't work if they aren't friends
   friend std::ostream& operator<<(std::ostream& os,  Complex& a);
   friend std::istream& operator>>(std::istream& is, Complex& a);
   //boolean operators
   bool operator==(Complex a);
   bool operator!=(Complex a);
private:
   double realPart;
   double imaginaryPart;
};

#endif

