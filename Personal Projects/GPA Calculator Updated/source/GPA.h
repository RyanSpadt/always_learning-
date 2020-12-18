#pragma once

#include <vector>
#include <string>


// using section
using std::vector;
using std::string;


class GPA {
private:
	vector<string> grades;
	vector<float> credits;
	unsigned int class_amount;

public:
	// Constructor
	GPA() { class_amount = 0; }

	// Destructor
	//~GPA();

	// Get Input From Console
	void getInput();

	// Push the grade input to the back of the grades vector
	void insertGrade(const string& g) { grades.push_back(g); }

	// Push the credit value input to the back of the credits vector
	void insertCredits(const float& f) { credits.push_back(f); }

	// Calculates the GPA based off of the input from the user (stored in our vectors)
	void calculateGPA();

	// Prints out the elements in the vectors
	void printAll();
};
