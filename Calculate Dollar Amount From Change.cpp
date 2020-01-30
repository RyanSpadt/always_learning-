// Assignment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
 *   Program gets number of quarters, dimes, and nickels from user input
 *   and displays the collective value of them in pennies
 *
 *   Author Ryan Spadt for Computer Science 1, Assignment 2 due 02/02/2020
*/

#include <iostream>

using namespace std;

int main()
{

    // Variable declartions
    const int quarters = 25, dimes = 10, nickels = 5;
    int inputQuarters, inputDimes, inputNickels, pennies;
    double penniesDollarAmount;

    // Get user input
    cout << '\n' << "Please enter the number of quarters, dimes, and nickels." << endl;
    cout << "To obtain the value of the coins in pennies." << endl;

    cout << '\n' << "Quarters: ", cin >> inputQuarters;
    cout << "Dimes: ", cin >> inputDimes;
    cout << "Nickels: ", cin >> inputNickels;

    // Calculates the value (number) of the pennies based on the input quarters, dimes, and nickels 
    pennies = (inputQuarters * quarters) + (inputDimes * dimes) + (inputNickels * nickels);

    /*
    * Calculates in dollar amount based on user input of quarters, dimes, and nickels
    * By dividing the value of pennies by 100 (the number of pennies in a dollar)
    */
    penniesDollarAmount = (static_cast<double>(pennies) / 100);

    // Displays the value of the coins in pennies.
    cout << '\n' << "The value of the coins is equivalent to " << pennies << " pennies" << endl;

    // Displays the value of the coins in dollar amount. Sets cout precision to two decimal points.
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << '\n' << "The value of the coins in dollar amount is: $" << penniesDollarAmount << endl;

}