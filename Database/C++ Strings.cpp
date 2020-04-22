
#include <iostream>
#include <string>

using namespace std;

int main()
{

    // C++ Strings are dynamic and not fixed in size like C-Style strings. They are safer and have bounds check unlike c-style strings
    
    // C++ strings are always initialized
    string s1; //empty
    string s2{ "Ryan" }; // This is a C-Style literal
    string s3{ s2 }; // initialized from s2
    string s4{ "Ryan", 3 }; // Only using the first 3 characters
    string s5{ s3, 0, 2 }; // First is the starting index, and ending in the second index. this would be Ry
    string s6(3, 'X'); // This is the constructor syntax and would be XXX

    // Concatenation with C++ strings
    string part1{ "C++" };
    string part2{ "is a powerful" };

    string sentence;

    sentence = part1 + " " + part2 + " language"; // Concatenation becomes C++ is a powerful language


    // Accessing string elements
    string s10;
    string s11{ "Ryan" };

    cout << s11[0] << endl; // R
    cout << s11.at(0) << endl; // R, but better because at uses bounds checks

    s11[0] = 'r'; // becomes ryan
    s11.at(0) = 'd'; // becomes dyan

    for (char c : s11) // will output the letters of the string one at a time
        cout << c << endl;

    for (int c : s11) // will output the integer values that represent the characters in the string one at a time ASCII codes
        cout << c << endl;


    // Comparing string elements, they are compared lexically character by character. Values by ASCII
    string sa{ "Apple" };
    string sb{ "Banana" };
    string sc{ "Kiwi" };
    string sd{ "apple" };
    string se{ s1 }; // Apple

    sa == se; // True
    sa == sb; // False
    sa != sb; // True
    sa < sb; // True
    sb > sa; // True
    sd < se; // False
    s1 == "Apple"; // True


    // Sub strings
    string test{ "This is a test" };

    // substr() extracts a substring from a string.      object.substr(start_index, length)
    cout << test.substr(0, 4); // This
    cout << test.substr(5, 2); // is
    cout << test.substr(10, 4); // test

    // find() returns the index of a substring in a string        object.find(search_string)
    cout << test.find("This"); // 0
    cout << test.find("is"); // 2
    cout << test.find("test"); // 10
    cout << test.find('e'); // 11
    cout << test.find("is", 4); // 5 the second criteria is where the start index for the search begins
    cout << test.find("XX"); // string::npos, because there is no position information available

    // erase() and clear(), removes a substring of chars from a string            object.erase(start_index, length)
    cout << test.erase(0, 5); // is a test
    cout << test.erase(5, 4); // is a
    cout << test.clear(); //empties the string

    // length(), shows the length of the string
    cout << test.length() << endl;

    
    // Compound Concantenation with C++ strings
    string name{ "Ryan" };

    name += " Spadt";
    cout << name << endl; // Ryan Spadt


    // Input stream for strings
    string c_name{};

    cin >> c_name; // only accepts up to the first space

    getline(cin, c_name); // read entire line until \n

    getline(cin, c_name, 'x'); // x is called the delimiter, once its read it will stop reading and discard the x.
}