// COPYRIGHT (C) 2017 William Horn(wjh27) All rights reserved.
//
// rational.hpp: Definition of rational class and its interace.

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <stdlib.h>


// Mathematical helper functions.
//
// NOTE: These are defined in rational.cpp.
int gcd(int, int);
int lcm(int, int);


// Represents a rational number. The rational numbers are the set of
// numbers that can be represented as the quotient of two integers.
class Rational
{
  private:
      int num;
      int den;
  public:
      // Constructors
      Rational();
      Rational(int);
      Rational(int, int);

      // Returns the numerator.
      int getNumerator() const { return num; }

      // Returns the denominator
      int getDenominator() const { return den; }

      // Overloaded operators
        // Overloaded equality operators
      bool operator == (const Rational & rat);
      bool operator != (const Rational & rat);

        // Overloaded ordering operators
      bool operator < (const Rational & rat);
      bool operator > (const Rational & rat);
      bool operator <= (const Rational & rat);
      bool operator >= (const Rational & rat);

        // Overloaded arithmetic operators
      Rational operator + (const Rational &rat);
      Rational operator - (const Rational &rat);
      Rational operator * (const Rational &rat);
      Rational operator / (const Rational &rat);

      // Friend functions (to avoid an error i was getting)
      //friend std::ostream& operator<<(std::ostream&, Rational);

};


// These are provided for you.
//
// NOTE: They are defined in rational.cpp.
std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);

#endif
