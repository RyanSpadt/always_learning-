/*
* Ryan Spadt Computer Science 1 MW 10AM - 11:50 AM
* April 20, 2020 Assignment 6
* Instructor Ann Richards
*/
/*
* 1. Ask user to enter last names and number of votes for 5 candidates
* 2. Program outputs the name, number of votes, and % of total votes for the candidates
* 3. Display the winner of the election
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
void get_input();
void calc_percentage(const string[], const int[]);
void winner(const string[], const int[], const int, const float[]);
void display(const string[], const int[], const int, const float[], const int);

int main()
{
    get_input(); // Call to function get_input()

    return 0;
}

// Function gets input from user for candidate names and their votes
void get_input()
{
    // Parallel array declarations
    string candidates [5] { " " };
    int votes [5] { 0 };

    cout << "Welcome to the election program." << endl;
    cout << "The program will prompt you for 5 candidate names and the amount of votes they received." << endl;
    system("Pause");

    system("CLS");
    for (unsigned int i = 0; i < 5; i++) // Obtaining user input
    {
        cout << "\nPlease enter a candidates name: ";
        cin >> candidates[i];
        cout << "How many votes did " << candidates[i] << " receive? ";
        cin >> votes[i];
    }
    system("CLS");

    cout << "Thank you for your entries.. You have entered: " << endl; // Confirming user input with for loop
    for (unsigned int i = 0; i < 5; i++)
    {
        cout << "\n" << candidates[i] << " with " << votes[i] << " votes.";
    }
    system("Pause");

    calc_percentage(candidates, votes); // Function call to calc_percentage using our user input variables as parameters
}

// Function calculates the percentage of votes each candidate had from the total
void calc_percentage(const string names_copy[], const int votes_copy[])
{
    int total_votes { 0 };
    float percentage [5] { 0.00f };

    for (unsigned int i = 0; i < 5; i++) // Adds all input votes to total_votes variable to get our total number of votes
        total_votes += votes_copy[i];

    for (unsigned int i = 0; i < 5; i++) // Calculates percentage of votes for each candidate and stores in our array
        percentage[i] = (static_cast<float>(votes_copy[i]) / static_cast<float>(total_votes));

    winner(names_copy, votes_copy, total_votes, percentage); // Function call to winner passing our variables in the parameters
}

// Function determines who won the election
void winner(const string names_copy[], const int votes_copy[], const int total_votes_copy, const float percentage_copy[])
{
    int winner_by_index { votes_copy[0] }; // initialize to first array index of votes_copy

    system("CLS");
    for (unsigned int i = 0; i < 5; i++) // For loop runs through our votes_copy array to determine the largest value
    {
        if (winner_by_index < votes_copy[i])
            winner_by_index = votes_copy[i];
    }

    for (unsigned int i = 0; i < 5; i++) // Loop then assigns our winner_by_index to the index of the largest value
    {
        if (winner_by_index == votes_copy[i]) // Break from loop when we find the value again (we just need its index)
        {
            winner_by_index = i;
            break;
        }
    }

    display(names_copy, votes_copy, total_votes_copy, percentage_copy, winner_by_index); // Function call to display passing all of our variables
}

// Function displays the inputs and results to the user
void display(const string names_copy[], const int votes_copy[], const int total_votes_copy, const float percentage_copy[], const int index)
{
    cout << left << setw(20) << "Name" << setw(20) << "Votes" << "% Votes" << endl;

    for (unsigned int i = 0; i < 5; i++)
        cout << left << setw(20) << names_copy[i] << setw(20) << votes_copy[i]  << setprecision(2) << fixed << (percentage_copy[i]*100.00) << "%" << endl;

    cout << left << setw(20) << "Total" << total_votes_copy << endl;

    cout << "\nThe Winner of the Election is " << names_copy[index] << "." << endl;
}