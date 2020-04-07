/*
* Ryan Spadt for Computer Science 1
* Meeting time: 10AM-11:50AM MW
* Insutrctor: Ann Richards
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
void type_text(const string&);
void getInput(float&, float&);
void calculateInflation(float, float, float&);
void output(float&);

int main()
{

	// Variable Declarations
	float price_item_curr{ 0.00f }, price_item_prev{ 0.00f }, inflation{ 0.00f };

	type_text("Welcome to the inflation calculator program."); // Welcoming message
	cout << endl;
	type_text("This program will ask you for the current price and previous price of an item, and give you it's inflation."); // Description of what the program will do for the user
	cout << endl;
    	system("pause"); // Pause wait for user to press any button.

	// Function calls
	getInput(price_item_curr, price_item_prev); 
	calculateInflation(price_item_curr, price_item_prev, inflation);
	output(inflation);

    return 0;
}

// Function to get input from user
void getInput(float& price_item_curr, float& price_item_prev)
{

	system("CLS"); // Clear console

	// Looping for error check
	for (;;)
	{
		type_text("Please enter the current price of an item: "); // Price for first item

		if (cin >> price_item_curr)
			break;
		else
		{
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	cout << endl;
	for (;;)
	{
		type_text("Please enter the price of the item two years ago: ");

		if (cin >> price_item_prev)
			break;
		else
		{
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	system("CLS");
	type_text("Thank you.. You have entered."); // Confirming user input
	cout << endl;
	type_text("Current price of item: ");
	cout << price_item_curr << endl;
	type_text("Price of item two years ago: ");
	cout << price_item_prev << endl;
}

void calculateInflation(float price_item_curr, float price_item_prev, float& inflation)
{

	inflation = (price_item_curr - price_item_prev) / price_item_prev * 100.00; // Calculate inflation percentage

}

void output(float& inflation)
{
	cout.setf(ios::fixed); // Set precision for decimal points to two
	cout.precision(2);
	cout << endl;

	// Determine what output to send out.
	if (inflation > 0)
	{
		type_text("Based on your input, the item is inflating. It has inflated by ");
		cout << inflation << "%";
	}
	else if (inflation < 0)
	{
		type_text("Based on your input, this item is deflating. It has deflated by ");
		cout << inflation << "%";
	}
	else
		type_text("Based on your input, this item is not inflating or deflating.");

	cout << endl << endl;
	type_text("Thank you for using the inflation calculator program.");
}

// Function to output as if it was being typed
void type_text(const string& text)
{
	// Loop through each character in the text
	for (size_t i = 0; i < text.size(); ++i)
	{
		// Output one character
		// Flush to make sure the output is not delayed
		cout << text[i] << flush;

		// Sleep 60 milliseconds
		Sleep(60);
	}
}
