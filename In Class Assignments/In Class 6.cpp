/*
* Author Ryan Spadt
* For Computer Science 1 10AM-11:50AM with Professor Ann Richards
* In Class 6
*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Function Declarations
void getInput(int&, int&, int&);
void calcAvg(double&, int, int, int);
void displayAvg(double, int, int, int);

int main()
{
	// Variable Declarations
	int user_score_1{ 0 }, user_score_2{ 0 }, user_score_3{ 0 };
	double average{ 0.00 };

	// Call to functions
	getInput(user_score_1, user_score_2, user_score_3);
	calcAvg(average, user_score_1, user_score_2, user_score_3);
	displayAvg(average, user_score_1, user_score_2, user_score_3);

	return 0;
}

//Function Definitions
void getInput(int& score_1, int& score_2, int& score_3)
{
	cout << "Please enter score 1." << endl;
	cin >> score_1;
	cout << "Please enter score 2." << endl;
	cin >> score_2;
	cout << "Please enter score 3." << endl;
	cin >> score_3;

	system("CLS");
	cout << "You have entered: " << endl;
	cout << "Score 1: " << score_1 << endl;
	cout << "Score 2: " << score_2 << endl;
	cout << "Score 3: " << score_3 << endl;
	system("pause");

}

void calcAvg(double& average, int var_1, int var_2, int var_3)
{
	average = (var_1 + var_2 + var_3) / 3;
}

void displayAvg(double average, int a, int b, int c)
{
	cout << "\nYour average is: " << average << endl;
}
