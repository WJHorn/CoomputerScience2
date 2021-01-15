/*
   COPYRIGHT (C) 2018 William Horn (wjh27) All rights reserved.
   CSII assignment 9
   Author.  Will Horn
            wjh27@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program is the test cases for the assignment
*/
#include <iostream>
#include <iomanip>

// prototypes
void unpackCharacters(char[], unsigned);
void displayBits(unsigned);

int main() {
   char characters[4];
   unsigned packed{1633903975}; // a, c, e, g

   std::cout << "The packed character representation is:\n";
   displayBits(packed);

   // demonstrate unpacking of characters
   unpackCharacters(characters, packed);
   std::cout << "\nThe unpacked characters are: ";
   for (size_t i{0}; i < 4; ++i) {
      std::cout << characters[i] << " ";
   }
   std::cout << std::endl;

   std::cout << "\nThe unpacked characters in bits are:" << std::endl;
   for (size_t i{0}; i < 4; ++i) {
      displayBits(characters[i]);
   }
}

// take apart the characters
void unpackCharacters(char characters[], unsigned pack)
{
    // the four masks that were given
    const unsigned mask1 = 4278190080;
    const unsigned mask2 = 16711680;
    const unsigned mask3 = 65280;
    const unsigned mask4 = 255;

    // set the values in the character array to the characters obtained from
    //  combining pack with the masks and shifting the bits accordingly.
    characters[0] = (pack & mask1) >> 24;
    characters[1] = (pack & mask2) >> 16;
    characters[2] = (pack & mask3) >> 8;
    characters[3] = (pack & mask4);
}

// display the bits of value
void displayBits(unsigned value)
{
    const int SHIFT = 8 * sizeof(unsigned) - 1;
    const unsigned MASK = 1 << SHIFT;

    std::cout << std::setw(10) << value << " = ";

    for (unsigned i = 1; i <= SHIFT + 1; i++)
    {
        std::cout << (value & MASK ? '1' : '0');
        value <<= 1;
        if (i % 8 == 0)
        {
            // put a space between the bytes to make it nicer to look at.
            std::cout << ' ';
        }
    }
    // new like when the for loop is finished
    std::cout << std::endl;
}
