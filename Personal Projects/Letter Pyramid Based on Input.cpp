
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string input{}, line_output{}, post_output{};

    cout << "Please enter something with no spaces: ";

    cin >> input;

    cout << "\nThank you for your entry, please wait for the construction of the pyramid.." << endl;
    cout << "--------------------------------------------------" << endl;

    for (size_t i{ 1 }; i <= input.length(); i++) // This will determine how many rows we will have, we know it will be equal to how many characters are in the input
    {
        line_output = input.substr(0, i);
        cout << setw(input.length()) << line_output;

        if (i == 1) // if its line 1 we need to throw an endl
            cout << endl;

        for (size_t n{ i-1 }; n --> 0;) // loop through decrementally including 0 without the unsigned int hitting below 0 and throwing an error
        {
            post_output = line_output.at(n);
            cout << post_output;
        }

        if ( i > 1) // if the line is below the first line we need to endl after we finish our for loop
            cout << endl;
    }
}