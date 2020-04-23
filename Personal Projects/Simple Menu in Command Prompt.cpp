
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Function prototypes
void main_menu(vector <int>);
void error_message(int);
void print_numbers(vector <int>);
void add_number(vector <int>&, bool);
void display_mean(vector <int>);
void display_small(vector <int>);
void display_large(vector <int>);
void quit();
void option(vector <int>, int);
void clear_screen(bool);

int main()
{
    vector <int> numbers; // This will store our numbers

    main_menu(numbers);

    return 0;
}

// Function displays the main menu for the user, and gets their input.
void main_menu(vector <int> numbers)
{
    char input{}; // local
    string valid_choices[12]{ "PpAaMmSsLlQq" };

    system("CLS");
    for (;;)
    {   
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> input;

        if (cin.fail()) // No extraction took place
        {
            error_message(0);
            continue; // Try again
        }

        if (valid_choices->find(input) == string::npos)
        {
            error_message(1);
            continue; // Try again
        }

        switch (input) // Determine what button was pressed
        {
            case('P'):
            case('p'):
                print_numbers(numbers);
                break;
            case('A'):
            case('a'):
                add_number(numbers, true);
                break;
            case('M'):
            case('m'):
                display_mean(numbers);
                break;
            case('S'):
            case('s'):
                display_small(numbers);
                break;
            case('L'):
            case('l'):
                display_large(numbers);
                break;
            case('Q'):
            case('q'):
                quit();
                break;
            default:
                error_message(0);
                continue; // try again
        }

        break;
    }
}

// Function to print numbers
void print_numbers(vector <int> numbers)
{
    system("CLS");
    cout << "PRINT MENU\n" << endl;

    char selection{};// local

    if (numbers.size() == 0)
    {
        cout << "There are currently no numbers added.\n" << endl;

        option(numbers, 1); // ask if they want to enter another number
    }

    if (numbers.size() > 0)
    {
        for (size_t i{ 0 }; i < numbers.size(); i++)
        {
            cout << numbers.at(i) << endl;
        }
    }

    option(numbers, 0); // return to main menu option for user
}

// Adds a number to our vector of numbers
void add_number(vector <int>& numbers, bool clear)
{
    clear_screen(clear); // if true in function call it will clear the screen
    int number_to_add{}; // local

    for (;;)
    {
        cout << "\nPlease enter an integer you wish to add: ";
        cin >> number_to_add;

        if (cin.fail()) // No extraction took place
        {
            error_message(1);
            continue; // Try again
        }

        numbers.push_back(number_to_add);

        cout << "The number " << number_to_add << " has been added." << endl;
        
        option(numbers, 1); // ask if they want to enter another number

        break;
    }

    option(numbers, 0); // return to main menu option for user
}

// Displays the average of the data set
void display_mean(vector <int> numbers)
{
    float average{}; // local

    clear_screen(true); // clears screen

    if (numbers.size() == 0) // if there are no numbers in the data set
    {
        cout << "There are currently no numbers input." << endl;
        option(numbers, 0); // return to main menu option for user
    }

    average = static_cast<float>(accumulate(numbers.begin(), numbers.end(), 0.0)) / numbers.size();

    cout << "The mean of the data set is currently " << average << endl;

    option(numbers, 0); // return to main menu option for user
}

// Displays the smallest number in the data set
void display_small(vector <int> numbers)
{
    int smallest{}; // local

    clear_screen(true); // clears screen

    if (numbers.size() == 0) // if there are no numbers in the data set
    {
        cout << "There are currently no numbers input." << endl;
        option(numbers, 0); // return to main menu option for user
    }

    smallest = *min_element(numbers.begin(), numbers.end());

    cout << "The smallest number is currently " << smallest << endl;

    option(numbers, 0); // return to main menu option for user
}

// Displays largest number in data set
void display_large(vector <int> numbers)
{
    int largest{}; // local

    clear_screen(true); // clears screen

    if (numbers.size() == 0) // if there are no numbers in the data set
    {
        cout << "There are currently no numbers input." << endl;
        option(numbers, 0); // return to main menu option for user
    }

    largest = *max_element(numbers.begin(), numbers.end());

    cout << "The smallest number is currently " << largest << endl;

    option(numbers, 0); // return to main menu option for user
}

// Ends the program
void quit()
{

    clear_screen(true);
    cout << "Thank you for using our menu" << endl;
    exit(0); // exits program
}

// Function that determines what error message to be displayed based on an intege in its function call
void error_message(int code)
{
    switch (code)
    {
        case 0:
            cout << "\nPlease enter a character provided in the menu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            system("CLS");
            break;
        case 1:
            cout << "\nThat is not a valid selection, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            system("CLS");
            break;
        default:
            cout << "\nOption not found please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            system("CLS");
            break;
    }
}

// if true clears screen, if false does not clear screen
void clear_screen(bool clear)
{
    if (clear == true)
    {
        system("CLS");
    }
}

// All options for the user within the interface
void option(vector <int> numbers, int option)
{
    char selection{}; // local

    switch (option)
    {
        case 0: // Return to main menu option
        {
            for (;;)
            {
                cout << "Would you like to return to the main menu? (Y/N) ";
                cin >> selection;

                if (cin.fail()) // No extraction took place
                {
                    error_message(1);
                    continue; // Try again
                }

                switch (selection)
                {
                case 'Y':
                case 'y':
                    main_menu(numbers);
                    break;
                case 'N':
                case 'n':
                    system("CLS");
                    cout << "OK. I will return you to the main menu..\n" << endl;
                    system("pause");
                    main_menu(numbers);
                    break;
                default:
                    error_message(1);
                    break;
                }

                break;
            }

            break;
        }
        case 1: // add another number?
        {
            for (;;)
            {
                cout << "Would you like to add a number? (Y/N) ";
                cin >> selection;

                if (cin.fail())
                {
                    error_message(1);
                    continue;
                }

                switch (selection)
                {
                case 'Y':
                case 'y':
                    add_number(numbers, false); // send to add_number function without clearing screen
                    break;
                case 'N':
                case 'n':
                    system("CLS");
                    cout << "OK. I will return you to the main menu..\n" << endl;
                    system("pause");
                    main_menu(numbers);
                    break;
                default:
                    error_message(1);
                    break;
                }

                break;
            }

            break;
        }
        default:
            break;
    }
}