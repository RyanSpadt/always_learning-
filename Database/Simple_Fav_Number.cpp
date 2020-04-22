// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

// Adds only what we need from the std namespace
using namespace std::cout, std::cin, std::endl;

int main()
{
    
    // Variable Declarations
    int input;

    // Get user input
    cout << "Please enter your favorite number between 1 and 100: ";
    cin >> input;

    // Respond to user input
    cout << "Amazing! That's my favorite number too!" << endl;
    cout << "No really! " << input << " is my favorite number!" << endl;

    return 0;
}