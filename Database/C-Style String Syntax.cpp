
#include <iostream>
#include <cstdlib> // Includes functions to convert c-style strings to other datatypes (only work on null ending strings not c-style strings

using namespace std;

int main()
{
    // Strings in C are terminated by a null character

    // Examples of some C-Style strings

    char str[80];

    strcpy(str, "Hello "); //copy

    strcat(str, "there"); //concatenate

    cout << strlen(str); // 10

    strcmp(str, "Another"); // -1

}