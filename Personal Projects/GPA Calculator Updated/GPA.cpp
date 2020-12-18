#include "GPA.h"
#include <iostream>
#include <iomanip>


using std::cout;
using std::cin;
using std::endl;


void GPA::getInput() 
{
	// Welcomes user and details what the program does
	cout << "Welcome to the GPA calculator." << endl;
	cout << "This Program will help calculate your GPA." << endl;
	cout << "\nFor Grade Please input A, A-, B+, B, B-, C+, C, C-, F" << endl;
	cout << "\nFor credits please enter: Example: 1.0" << endl;

	cout << "\nPlease enter how many classes you wish to calculate for: ";
	cin >> class_amount;

	string grade_input;
	float credit_input;

	for (unsigned int i{ 1 }; i <= class_amount; i++)
	{
		cout << "\nClass " << i << " Grade: ";
		cin >> grade_input;
		insertGrade(grade_input);

		cout << "Class " << i << " Credits: ";
		cin >> credit_input;
		insertCredits(credit_input);
	}
}


void GPA::calculateGPA()
{
	float grade_point{ 0.00f }, credit_hours{ 0.00f };
	string possible_gradesU[9]{ "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "F" };
	string possible_gradesL[9]{ "a", "a-", "b+", "b", "b-", "c+", "c", "c-", "f" };
	float possible_quality_points[9]{ 4.00f, 3.70f, 3.33f, 3.00f, 2.70f, 2.30f, 2.00f, 1.70f, 0.00f };
	unsigned int x{ 0 };

	for (unsigned int i{ 0 }; i < grades.size(); i++)
	{

		while (true)
		{
			if (grades.at(i) == possible_gradesU[x] || grades.at(i) == possible_gradesL[x])
			{
				grade_point += (possible_quality_points[x] * credits.at(i));
				credit_hours += credits.at(i);
				x = 0;
				break;
			}
			else
				x++;
		}

	}

	cout << "<--------------------------------------------------------------->";
	cout << "\nYour Cumulative GPA is: " << std::setprecision(3) << grade_point / credit_hours << endl;
}


void GPA::printAll()
{
	for (unsigned int i{ 0 }; i < grades.size(); i++)
	{
		cout << "\nGrade: " << grades.at(i);
		cout << "\nCredits: " << credits.at(i);
	}
}