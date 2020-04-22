// Project7.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    /*
    *
    * Suppose we may get more and more data as time goes on or even maybe
    * That there is a possibility that our fixed array may get filled up
    * Or overfill. In that case we can use a dynamic array (a vector)
    * we must include the vector type
    * 
    */

    // This is an array that automatically detects the fixed size
    // Arrays have no bound checks, unlike vectors that do
    int array_1[]{ 0, 1, 2 };

    // You can also use this format
    char array_2[]
    {
        'a', 'b', 'c',
        'd', 'e', 'f'
    };

    // This is the syntax for a vector, in this case we created a vector of size 10
    // The 10 integers will automatically be set to 0
    vector <int> vector_1 (10);

    // We can declare and initialize a vector like this
    vector <int> test_scores{ 100, 98, 89, 85, 93 };

    // We can declare a vector like this, where we say the size is 365 and all
    // Of the values are set to 80.0
    vector <double> hi_temperatures(365, 80.0);

    

}