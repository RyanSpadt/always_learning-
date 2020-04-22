// Project5.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

using namespace std;

// Program displays the use of global variables

// Global variable accessible to the enter program.
int global_age{ 17 };

int main()
{

    // Local variable only available to main function
    int age{ 18 };

    // Outputs the global and local variables
    cout << global_age << " " << age;
    
    return 0;
}