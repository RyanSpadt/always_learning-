// Project9.cpp : This file contains the 'main' function. Program execution begins and ends there.

/***************************************
* 
* Author Ryan Spadt
* Feb 02, 2020
*
* Project will be improvement upon prior change counter.
* User will be prompted to enter in amount of
* Quarters, Dimes, Nickels, and Pennies they wish to have the value of in $.
* Function will then take the amounts and values and show the collective value
* Of the coins to the User.
*
***************************************/

#include <iostream>

using namespace std::cout, std::cin, std::endl;

int main()
{

    // Program prompts user to enter the amount of coins they have
    cout << "Hello! This Program will calculate the collective "
         << "total of your coins." << endl;
    cout << '\n' << "Please enter the amount of coins you have:" << endl;


    // Variable Declarations for the User input of Coins
    int input_quarters, input_dimes, input_nickels, input_pennies;

    // Prompts User for coin type and waits for input from user
    cout << '\n' << "********************************************************" << endl;
    cout << "Quarters: ", cin >> input_quarters;
    cout << "Dimes: ", cin >> input_dimes;
    cout << "Nickels: ", cin >> input_nickels;
    cout << "Pennies: ", cin >> input_pennies;


    /*
    * Variable Declarations for the value of the Coins
    * Floats used because precision needed is only 2
    */
    const float quarter_value = 0.25, dime_value = 0.10,
        nickel_value = 0.05, penny_value = 0.01;

    // Variable to hold the collective total of the coins
    float collective_value;

    // Program takes the inputs of the users and collectively adds them to a total amount
    collective_value = (static_cast<float>(input_quarters) * quarter_value);
    collective_value += (static_cast<float>(input_dimes) * dime_value);
    collective_value += (static_cast<float>(input_nickels) * nickel_value);
    collective_value += (static_cast<float>(input_pennies) * penny_value);


    // Program sets decimal point fixed to 2
    cout.setf(ios::fixed);
    cout.precision(2);
    
    // Program outputs the collective value of the coins to the user
    cout << "********************************************************" << endl;
    cout << '\n' << "The collective value of the coins entered is: $"
        << collective_value << endl;


    return 0;
}
