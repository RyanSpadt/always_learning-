/*
* Author Ryan Spadt Feb 03, 2020
* Computer Science 1 Professor Ann Richards
*
* Psuedocode
*
* Program will read a text file named "Input Data"
* It will then gather the desired data and output it to a file named "Ch3_Ex5Output.dat"
* The data output will be in the format: first name, last name, and updated salary
* The output decimal numbers should be to two decimal places.
*
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using std::ifstream;
using std::ofstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::fixed;
using std::setprecision;

int main()
{
    // Declaration of Input stream
    ifstream input_file;

    // Declaration of Output stream
    ofstream output_file;

    // Open the input file to read
    input_file.open("Input Data.txt");

    // Set cout precision to two for decimal points
    cout.setf(ios::fixed);
    cout.precision(2);

    // Sets preicison to writing to output file
    output_file << fixed << setprecision(2);

    // Determines if the file successfully opened and how to handle it.
    if (!input_file)
    {
        cout << "Error opening file.." << endl; // File could not open
        return 0;
    }
    else
    {
        cout << "\nFile opened successfully." << endl; // File opened successfully

        // Opens output file
        output_file.open("Ch3_Ex5Output.dat");

        if (!output_file)
        {
            cout << "Output file could not be opened." << endl; // Output file could not open
            return 0;
        }
        else
        {

            cout << "\nOutput file opened successfully." << endl;

            // Declaration of variables needed
            string last_name, first_name;
            float salary, raise, new_salary;

            // For statement to run 3 times for the three employees
            for (int i = 0; i < 3; i++)
            {
                input_file >> last_name;// Reads employees last name and assigns it to string last_name
                input_file >> first_name;// Reads employyes first name and assigns it to string first_name
                input_file >> salary;// Reads employees current salary and assigns to float salary
                input_file >> raise;// Reads employees raise and assigns to float raise

                // Calculates the new salary for the employee by adding on their raise to the current salary
                new_salary = (salary * (raise / 100.00)) + salary;

                // Writes the employees info in the order of first name, last name, new salary to output_file
                output_file << '\n' << first_name << " " << last_name
                    << " " << new_salary << endl;

                // Displays information that was assigned to the variables based on the line
                cout << '\n' << last_name << " " << first_name << " "
                    << salary << " " << raise << " " << new_salary << endl;
            }
        }
    }

    // Displays that the operation was completed successfully
    cout << "\nOperation was completed successfully." << endl;

    // Closes input and output file
    input_file.close();
    output_file.close();

    return 0;
}