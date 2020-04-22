
#include <iostream>
#include <string> // needed for c-style string functions
#include <cctype> // needed for character based functions

using namespace std;

int main()
{
    // These are arrays of characters of size shown
    char first_name[20]{};
    char last_name[20]{};
    char full_name[50]{};
    char temp[50]{};

    cout << "Please enter your first name: ";
    cin >> first_name;

    cout << "Please enter your last name: ";
    cin >> last_name;
    cout << "----------------------------------------" << endl;

    //strlen(string name) determines how many characters are in a string, it returns a size_t.
    cout << "Hello " << first_name << " your first name has " << strlen(first_name) << " characters" << endl;
    cout << "and your last name, " << last_name << " has " << strlen(last_name) << " characters" << endl;

    strcpy(full_name, first_name); // copy first_name to full_name
    strcat(full_name, " "); // concatenate full_name and a space
    strcat(full_name, last_name); // concatenate last_name to full_name

    cout << "Your full name is " << full_name << endl;

    /****************************************************************************************************************************************/

    cout << "Enter your full name: ";
    cin >> full_name; // If you enter a space after your first name it will only store the first name
    cout << "Your full name is " << full_name << endl;

    cout << "Enter your full name: ";
    cin.getline(full_name, 50); // This will read the entire line of cin, until 50 characters is reached or when the user presses enter
    cout << "Your full name is " << full_name << endl;

    cout << "-------------------------------------------------" << endl;

    strcpy(temp, full_name); // copy full_name to temp
    
    if (strcmp(temp, full_name) == 0) // Comparing the two strings temp and full_name
        cout << temp << " and " << full_name << " are the same" << endl;
    else
        cout << temp << " and " << full_name << " are different" << endl;

    cout << "-------------------------------------------------" << endl;

    /*****************************************************************************************************************************************/

    for (size_t i{ 0 }; i < strlen(full_name); ++i) // we are using datatype size_t for i initializing to 0 and going until its the string length of full_name - 1.
    {
        if (isalpha(full_name[i])) // while looping through the length of full_name if the current space is a character do this
            full_name[i] = toupper(full_name[i]); // Changes the current space to an uppercase letter
    }

    cout << "Your full name is " << full_name << endl;

    cout << "-------------------------------------------------" << endl;

    if(strcmp(temp, full_name) == 0) // These strings are no longer the same because the chars in full_name have been put to uppercase
        cout << temp << " and " << full_name << " are the same" << endl;
    else
        cout << temp << " and " << full_name << " are different" << endl;

}