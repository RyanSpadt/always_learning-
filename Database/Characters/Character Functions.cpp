
#include <iostream>
#include <cctype> // character functions

int main()
{

	// Testing functions

	isalpha('c'); // true if c is a letter
	isalnum('c'); // test if c is a letter or digit
	isdigit('c'); // true if c is a digit
	islower('c'); // True if c is lowercase
	isprint('c'); // True if c is a printable character
	ispunct('c'); // True if c is a punctuation character
	isupper('c'); // True if c is an uppercase letter
	isspace('c'); // True if c is a white space

	// Converting characters
	tolower('c'); // returns lowercase of c
	toupper('c'); // returns uppercase of c
}
