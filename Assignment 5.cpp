/*
* Ryan Spadt for Computer Science 1
* Meeting time: 10AM-11:50AM MW
* Insutrctor: Ann Richards
* Assignment 5 due on 04/12/20
*/

/*
* 1. Ask user for input of the current price and price 1-2 years ago of an item
* 2. Price item 1 - price item 2. Then divide by price item 2 to get percentage change.
* 3. Output that percentage change (as inflation and if it is increasing or decreasing)
* Must include a function for accepting input, a function for calculating, and a function to output. No global variables
*/

#include <iostream>
#include <windows.h>

// Had to undefine max, pre-defined in Visual Studio for some reason
#undef max

using namespace std;

// Function prototypes
void getInput(float&, float&, float&);
void calculateInflation(float, float, float, float&, float&);
void output(float, float);

// Main function
int main()
{
	// Variable Declarations
	float price_item_curr{ 0.00f }, price_item_one{ 0.00f }, price_item_two{ 0.00f }, inflation_01{ 0.00f }, inflation_12{ 0.00f };

	// Function calls
	getInput(price_item_curr, price_item_one, price_item_two);
	calculateInflation(price_item_curr, price_item_one, price_item_two, inflation_01, inflation_12);
	output(inflation_01, inflation_12);

	return 0;
}

// Function to get input from user
void getInput(float& price_item_curr, float& price_item_one, float& price_item_two)
{
	cout << "Welcome to the inflation calculator program." << endl; // Welcoming message
	cout << "This program will ask you for the current price and previous price of an item, and give you it's inflation." << endl; // Description of what the program will do for the user
	system("pause"); // Pause wait for user to press any button.
	system("CLS"); // Clear console

	for (;;) // Looping for error check, current price
	{
		cout << "Please enter the current price of an item: ";

		cin >> price_item_curr;

		if (cin.fail()) // No extraction took place
		{
			cout << "Please enter a valid price." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue; // Try again
		}
		if (price_item_curr <= 0) // Check if value is less than or equal to 0, if it is try again.
		{
			cout << "Price must be greater than 0." << endl;
			continue; // Try again
		}
		
		break;
	}

	cout << endl;
	for (;;) // Looping for price one year ago variable, in separate loops, to not have the disadvantage of starting over if the user has fat fingers and mis-types on the second input
	{
		cout << "Please enter the price of the item one year ago: ";

		cin >> price_item_one;

		if (cin.fail()) // No extraction took place
		{
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue; // Try again
		}	
		if (price_item_one <= 0) // Check if value is less than or equal to 0, if it is try again.
		{
			cout << "Price must be greater than 0." << endl;
			continue; // Try again
		}

		break;
	}

	cout << endl;
	for (;;) // Looping for price two years ago variable, in separate loops, to not have the disadvantage of starting over if the user has fat fingers and mis-types on the second or third input
	{
		cout << "Please enter the price of the item two years ago: ";

		cin >> price_item_two;

		if (cin.fail()) // No extraction took place
		{
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue; // Try again
		}
		if (price_item_two <= 0) // Check if value is less than or equal to 0, if it is try again.
		{
			cout << "Price must be greater than 0." << endl;
			continue; // Try again
		}

		break;
	}

	system("CLS");

	cout << "Thank you.. You have entered." << endl;
	cout << "Current price of item: " << price_item_curr << endl;
	cout << "Price of item one year ago: " << price_item_one << endl;
	cout << "Price of item two years ago: " << price_item_two << endl;
}

// Calculates inflation to get our desired results
void calculateInflation(float price_item_curr, float price_item_one, float price_item_two, float& inflation_01, float& inflation_12)
{
	inflation_01 = (price_item_curr - price_item_one) / price_item_one * 100.00; // Calculate inflation percentage, from one year ago to current.
	inflation_12 = (price_item_one - price_item_two) / price_item_two * 100.00; // Calculate inflation percentage, from two years ago to one year ago.
}

// Displays to the user the results
void output(float inflation_01, float inflation_12)
{
	cout.setf(ios::fixed); // Set precision for decimal points to two
	cout.precision(2);
	cout << endl;

	if (inflation_12 > 0) // Checking what to output for the inflation/deflation from two years ago to one year ago.
		cout << "From two years ago to one year ago, this product inflated by " << inflation_12 << "%" << endl;
	else if (inflation_12 < 0)
		cout << "From two years ago to one year ago, this product deflated by " << inflation_12 << "%" << endl;
	else
		cout << "From two years ago to one year ago, this product has not changed in price." << endl;

	if (inflation_01 > 0) // Checking what to output for the inflation/deflation from one year ago to current.
		cout << "From one year ago to current, this product has inflated by " << inflation_01 << "%" << endl;
	else if (inflation_01 < 0)
		cout << "From one year ago to current, this product has deflated by " << inflation_01 << "%" << endl;
	else
		cout << "From one year ago to current, this product has not changed in price." << endl;

	cout << endl << endl << "Thank you for using the inflation calculator program" << endl;
}
