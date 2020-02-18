#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ios;

void getInput(string, float, int);
float calculateGPA();

// Public Variables
vector <string> grade;
vector <float> credits;

int main()
{
	string grade_input;
	float credit_input{ 0.00f };
	int class_amount{ 0 };

	// Welcomes user and details what the program does
	cout << "Welcome to the GPA calculator." << endl;
	cout << "This Program will help calculate your GPA." << endl;
	cout << '\n' << "For Grade Please input A, A-, B+, B, B-, C+, C, C-, F" << endl;
	cout << '\n' << "For credits please enter: Example: 1.0" << endl;
	
	getInput(grade_input, credit_input, class_amount);

	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "----------------------------------------------";
	cout << "\nYour Cumulative GPA is: " << calculateGPA() << endl;

	return 0;
}

void getInput(string grade_input, float credit_input, int class_amount)
{

	// Gets user input and inserts value input into the back of the appropriate vector
	cout << "\nPlease enter how many classes you wish to calculate for: ", cin >> class_amount;

	for (unsigned int i = 0; i < class_amount; i++)
	{
		cout << '\n' << "Grade: ", cin >> grade_input;
		grade.push_back(grade_input);

		cout << " Credits: ", cin >> credit_input;
		credits.push_back(credit_input);
	}

}

float calculateGPA()
{
	float grade_point{ 0.00f }, gpa{ 0.00f }, credit_hours{0.00f}, quality_point{ 0.00f };
	string possible_grades[9] { "A","A-","B+","B","B-","C+","C","C-","F" };
	float possible_quality_points [9] {4.00f, 3.70f, 3.33f, 3.00f, 2.70f, 2.30f, 2.00f, 1.70f, 0.00f};
	int x{ 0 };

	// Runs through the vectors and uses the data to calculate GPA
	for (unsigned int i = 0; i < grade.size(); i++)
	{
		// Evaluates the vector index and runs through the arrays to find the value equivalent to the vector index.
		while (true)
		{
			if (grade[i] == possible_grades[x])
			{
				quality_point = possible_quality_points[x];
				x = 0;
				break;
			}
			else
				x++;
		}

		grade_point += (quality_point * credits[i]);

		credit_hours += credits[i];
	}

	gpa = (grade_point / credit_hours);

	return gpa;
}
