// Project8.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Declaration and Initialization of Vector
    vector <int> test
    {
        100, 90, 90
    };
    
    // Adds value 80 to the end of the vector
    test.push_back(80); // 100, 90, 90, 80

    // Displays the 4th element in the vector
    cout << test[3];

    return 0;
}