// Project4.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

using namespace std;

// This program will calculate the area of a room in square feet

int main()
{

    // Variable Declarations
    int room_width{ 0 };
    int room_length{ 0 };

    // Get user inputs
    cout << "Enter the width of the room: ";
    cin >> room_width;

    cout << "Enter the length of the room: ";
    cin >> room_length;

    // Display calculation based on user input
    cout << "The area of the room is "
         << room_width * room_length << " square feet.";

    return 0;
}
