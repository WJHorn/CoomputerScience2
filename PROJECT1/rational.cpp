// COPYRIGHT (C) 2017 William Horn(wjh27) All rights reserved.
//
// rational.hpp: Definition of rational class and its interace.

#include "rational.hpp"

#include <iostream>


// -------------------------------------------------------------------------- //
// Helper functions

// Compute the GCD (greatest common divider) of two integer values using Euclid's algorithm.
int
gcd(int a, int b)
{
  a = abs(a);   //make them to be positive numbers
  b = abs(b);
  if(a==0 || b==0){ //if one number is 0, always return 1
    return 1;
  }
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}


// Compute the LCM (Least Common Multiple) of two integer values.
int
lcm(int a, int b)
{
  a = abs(a); //make them positive
  b = abs(b);
  if(a == 0 || b == 0){
    throw "Integers can not be zero in calculating Least Common Multiple";
  }
  return (abs(a) / gcd(a, b)) * abs(b);
}


// -------------------------------------------------------------------------- //
// Rational implementation

// Default constructor
Rational::Rational()
{
    num = 0;
    den = 1;
}

// Default constructor accepting one integer
Rational::Rational(int num)
{
    this->num = num;
    this->den = 1;
}

// Default constructor accepting two integers
Rational::Rational(int num, int den)
{
    if (den == 0)
    {
        throw "You can't divide by 0, silly!";
    }
    this->num = num;
    this->den = den;
    //see if the fraction can be simplified
    if (gcd(num,den) != 1)
    {
        int x = gcd(num,den);
        this->num /= x;
        this->den /= x;
    }
}

// Overloaded operators

    // Overloaded equality operators

bool Rational::operator==(const Rational &rat)
{
    bool isEqual;
    double r1 = num / den;
    double r2 =  rat.num / rat.den;
    if (r1 == r2)
    {
        isEqual = true;
        return isEqual;
    }
    else
    {
        isEqual = false;
        return isEqual;
    }
}

bool Rational::operator!=(const Rational &rat)
{
    bool isEqual;
    double r1 = num / den;
    double r2 =  rat.num / rat.den;
    if(r1 != r2)
    {
        isEqual = false;
        return isEqual;
    }
    else
    {
        isEqual = true;
        return isEqual;
    }
}

    // Overloaded ordering operators

bool Rational::operator<(const Rational &rat)
{
    bool lessThan;
    if(num / den < rat.num / rat.den)
    {
        lessThan = true;
        return lessThan;
    }
    else
    {
        lessThan = false;
        return lessThan;
    }
}

bool Rational::operator>(const Rational &rat)
{
    bool greaterThan;
    if(num / den > rat.num / rat.den)
    {
        greaterThan = true;
        return greaterThan;
    }
    else
    {
        greaterThan = false;
        return greaterThan;
    }
}

bool Rational::operator<=(const Rational &rat)
{
    bool lessEqual;
    if(num / den <= rat.num / rat.den)
    {
        lessEqual = true;
        return lessEqual;
    }
    else
    {
        lessEqual = false;
        return lessEqual;
    }
}

bool Rational::operator>=(const Rational &rat)
{
    bool greaterEqual;
    if(num / den >= rat.num / rat.den)
    {
        greaterEqual = true;
        return greaterEqual;
    }
    else
    {
        greaterEqual = false;
        return greaterEqual;
    }
}

    // Overloaded arithmetic operators

Rational Rational::operator+(const Rational &rat)
{
    int lcd, numL, numR, numNew;
    lcd = lcm(den, rat.den);
    numL = num * (lcd / den);
    numR = rat.num * (lcd / rat.den);
    numNew = numL + numR;
    Rational r(numNew, lcd);
    return r;
}

Rational Rational::operator-(const Rational &rat)
{
    int lcd, numL, numR, numNew;
    lcd = lcm(den, rat.den);
    numL = num * (lcd / den);
    numR = rat.num * (lcd / rat.den);
    numNew = numL - numR;
    Rational r(numNew, lcd);
    return r;
}

Rational Rational::operator*(const Rational &rat)
{
    int numNew, denNew;
    numNew = num * rat.num;
    denNew = den * rat.den;
    Rational r(numNew, denNew);
    return r;
}

Rational Rational::operator/(const Rational &rat)
{
    int numNew, denNew;
    numNew = num * rat.den;
    denNew = den * rat.num;
    Rational r(numNew, denNew);
    return r;
}

//DO NOT CHANGE operators << and >> overloading functions
std::ostream&
operator<<(std::ostream& os, Rational r)
{
  return os << r.getNumerator() << '/' << r.getDenominator();   // Changed r.num and r.den to call functions since r.num and r.den are both private members
}

std::istream&
operator>>(std::istream& is, Rational& r)
{
  // Read the first integer, return on error.
  int p;
  is >> p;
  if (!is)
    return is;

  // Check for the divider. Assuming no spaces.
  if (is.peek() != '/') {
    r = Rational(p);
    return is;
  }
  is.get();

  int q;
  is >> q;
  if (!is)
    return is;
  if (q == 0) {
    is.setstate(std::ios::failbit);
    return is;
  }
  r = Rational(p, q);
  return is;
#if 0
  int p, q;
  char c;
  is >> p >> c >> q;
  if (!is)
    return is;
  // Require that the divider to be a '/'.
  if (c != '/') {
    is.setstate(std::ios::failbit);
    return is;
  }

  // Make sure that we didn't read p/0.

  r = Rational(p, q);
  return is;
#endif
}






