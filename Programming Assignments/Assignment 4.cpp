// Project18.cpp : This file contains the 'main' function. Program execution begins and ends there.


/*
* The population of town A is less than the population of town B. However, the population of town A is growing faster than the population of town B.
* Write a program that prompts the user to enter the population and growth rate of each town.
* The program outputs after how many years the population of town A will be greater than or equal to the population of town B and the populations of both the towns at that time.
* (A sample input is: Population of town A 55,000, growth rate of town A 54%, population of town B 58,000, and growth rate of town B 52%.)
*/

/*
* Author Ryan Spadt
* Assignment 4 for Computer Science 1 10AM - 11:50AM MW with Professor Ann Richards
* Due March 8, 2020
*/

#include <iostream>
#include <tuple>

using std::cout;
using std::cin;
using std::endl;
using std::tuple;
using std::make_tuple;
using std::get;
using std::numeric_limits;
using std::streamsize;

// Function Declarations
tuple<int, int, int, int> get_input();
void error_message();
int calculate_data();

int main()
{
    cout << "\nThe year in which town A will have a larger population is: " << calculate_data() << endl;

    return 0;
}

// Function gets input from user validating that it is being stored properly. It then assigns to the declared variables, and returns the variables through the function.
tuple<int, int, int, int> get_input()
{
    int population_town_a{ 0 }, population_town_b{ 0 }, growth_town_a{ 0 }, growth_town_b{ 0 };

    cout << "This program will determine the year, in which population of town A will be greater than town B." << endl;
    cout << "Please ensure your input of population town a is less than the population of town b." << endl;
    cout << "As well as, the growth of town a being greater than the growth of town b." << endl;

    do
    {
        cout << "\nPlease enter the population for town a: ", cin >> population_town_a;

        if (population_town_a >= 1) // Breaks from the do while loop if the population of town a is greater than 1
            break;
        else
            error_message();

    } while (cin.fail() || population_town_a < 1); // Continues loop if the cin fails or the integer entered is less than 1

    do
    {
        cout << "\nPlease enter the population for town b: ", cin >> population_town_b;

        if (population_town_b >= 1 && population_town_b > population_town_a) // Breaks from the do while loop if the pop town b is greater than 1 and it is greater than pop town a
            break;
        else
            error_message();

    } while (cin.fail() || population_town_a < 1 || population_town_b <= population_town_a); // Continues loop if the cin fails, the integer is less than 1 or if it is less than or equal to population of town a

    do
    {
        cout << "\nPlease enter the growth for town a: ", cin >> growth_town_a;

        if (growth_town_a >= 1) // Breaks from loop if growth of town a is greater than 1
            break;
        else
            error_message();

    } while (cin.fail() || growth_town_a < 1); // Continues if the cin fails, or if the growth entered for town a is less than 1

    do
    {
        cout << "\nPlease enter the growth for town b: ", cin >> growth_town_b;

        if (growth_town_b >= 1 && growth_town_b < growth_town_a) // Breaks from loop if growth town b is greater than 1 and less than growth of town a
            break;
        else
            error_message();

    } while (cin.fail() || growth_town_a < 1 || growth_town_b >= growth_town_a); // Continues if the cin fails, or if the growth entered for town a is less than 1, or if the growth for town b is equal or greater than growth town a

    return make_tuple(population_town_a, growth_town_a, population_town_b, growth_town_b); // Returns the data collected from the user
}

// Function accepts the values of the variables from get_input() function, it then retrieves the appropriate data and calculates the desired result.
int calculate_data()
{
    auto data = get_input();

    system("CLS");
    cout << "\nYou have entered." << "\n";
    cout << "Population for town a: " << get<0>(data) << "\n"
        << "Growth of town a: " << get<1>(data) << "%" << "\n"
        << "Population for town b: " << get<2>(data) << "\n"
        << "Growth for town b: " << get<3>(data) << "%" << "\n";
    system("pause");

    float growth_a_to_percent{ static_cast<float>(get<1>(data)) / 100.00f }; // Assigns these floats to the growth integers and converts to float; divides the number by 100.00 to ensure it's a percentage.
    float growth_b_to_percent{ static_cast<float>(get<3>(data)) / 100.00f };
    int year{ 2020 }, pop_growth_a{ 0 }, pop_growth_b{ 0 };

    for (;;)
    {
        if (get<0>(data) > get<2>(data)) // Determines if population for town a is greater than town b. If it is the loop stops, if not it does another calculation.
            break;
        else
        {
            pop_growth_a = (get<0>(data) * growth_a_to_percent); // Multiplies the population entered by the percentage generated, and assigns to new integer variable.
            pop_growth_b = (get<2>(data) * growth_b_to_percent);

            get<0>(data) += pop_growth_a; // Adds the calculated population growth from one year, to the population variable we first accepted input for.
            get<2>(data) += pop_growth_b;

            year++;

            cout << "\nIn the year " << year << " Town A: " << get<0>(data) << ", Town B: " << get<2>(data) << endl;
        }
    }

    return year;
}

// Displays an error message for if the wrong input is entered by the user.
void error_message()
{
    cout << "\nPlease enter a valid integer." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
