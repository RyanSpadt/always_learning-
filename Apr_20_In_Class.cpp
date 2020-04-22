/*
* Ryan Spadt Computer Science 1
* April 20, 2020 In Class Assignment
* Instructor Ann Richards
*/

#include <iostream>

using namespace std;

// Function Prototypes
void get_Scores();
void get_Average(const int[]);
void display(const int[], float&);

int main()
{
    get_Scores(); // Call to get_Scores function in main

    return 0;
}

// Function gets user input for the scores
void get_Scores()
{
    int grades [3] { 0 }; // Array declaration of size 3

    cout << "Please enter the first score: ";
    cin >> grades[0];
    cout << "Please enter a second score: ";
    cin >> grades[1];
    cout << "Please enter a third score: ";
    cin >> grades[2];

    for (unsigned int i = 0; i < 3; i++)
        cout << endl << grades[i] << endl;

    get_Average(grades); // Call to get_Average using grades array as paramater
}

// Takes our array input from the user and calculates the average
void get_Average(const int scores[])
{
    float average { 0.00f };

    for (unsigned int j = 0; j < 3; j++)
        average += scores[j];

    average /= 3;
    cout << average << endl;

    display(scores, average); // Call to display function using parameters
}

// Displays to the user their input and the average
void display(const int scores_copy[], float& avg)
{
    system("CLS"); // Clear console

    cout << "\nYour scores of " << scores_copy[0] << " " << scores_copy[1] << " " << scores_copy[2]
        << " are being computed to an average of: " << avg << endl;
}