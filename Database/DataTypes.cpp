// Project6.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

int main()
{

    // Char datatypes
    // Wider types of chars are used to represent wide character sets.

        // One byte. Or at least 8 bits. Representable values 2^8 or 256
            char a{'a'};

        // At least 16 bits. Representable values 2^16 or 65,536
            char16_t b{'b'};

        // At least 32 bits. Representable values 2^32 or 4,294,967,296
            char32_t c{'c'};

        // Can represent the largest available character set. 
        // Representable values 2^64 or 18,446,744,073,709,551,615
            wchar_t d{'d'};


    // Integer datatypes
    // Ints are default signed

        // At least 16 bits.
            signed short int a{ 0 };
            signed int a{ 0 };

            unsigned short int a{ 0 };
            unsigned int a{ 0 };

        // At least 32 bits.
            signed long int a{ 0 };

            unsigned long int a{ 0 };

        // At least 64 bits.
            signed long long int a{ 0 };

            unsigned long long int a{ 0 };


    // Floating-point datatypes

        // No more than 7 decimal points 1.2*10^-38 to 3.4*10^38
            float a{ 1.0 };

        // No more than 15 decimal points. 2.2*10^-308 to 1.8*10^308
            double a{ 1.0 };

        // No less than 19 decimal points. 3.3*10^-4932 to 1.2*10^4932
            long double a{ 1.0 };


    // Boolean datatypes

        // Usually 8 bits. True or false.
        // 0 is false. and non-zero is true.
            bool a{ true };
    

    return 0;
}