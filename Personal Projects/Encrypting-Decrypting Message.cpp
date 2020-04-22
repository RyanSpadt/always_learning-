
#include <iostream>
#include <string>

using namespace std;

/*
1. ask user to enter a secret message
2. program then encrypts this message using substitution cipher and display the encrypted message
3. decrypt the encrypted message back to the original message
*/

// Function Prototypes
void get_message(string&);
void encrypt_message(string&, string, string);
void decrypt_message(string&, string, string);
void another_way(string&, string, string);

int main()
{
    string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    string key{ "QwErTyUiOpAsDfGhJkLzXcVbNmMnBvCxZlKjHgFdSaPoIuYtReWq" };
    string message{};

    get_message(message);
    encrypt_message(message, alphabet, key);
    decrypt_message(message, alphabet, key);
    another_way(message, alphabet, key); // Another way of doing the encryption

    return 0;
}

// Gets input from user
void get_message(string& message)
{
    cout << "Please enter your message: ";
    getline(cin, message); // This will get the whole line of the message we want and store it into message
}

// Encrypts the message the user submitted
void encrypt_message(string& message, string alphabet, string key)
{
    cout << endl << "Encrypting message.." << endl;

    for (size_t i{ 0 }; i < message.length(); i++) // Runs through the message length
    {
        for (size_t j{ 0 }; j < alphabet.length(); j++) // Runs through the alphabet string length
        {
            if (message.at(i) == alphabet.at(j) && message.at(i) != string::npos) // Looks for an equivalent in alphabet at position i in message string and replaces it with whatever is at position i in key string then breaks
            {
                message.at(i) = key.at(j);
                break;
            }
        }
    }

    cout << endl << message << endl;
    system("pause");
}

// Decrypts the message back to its original form
void decrypt_message(string& message, string alphabet, string key)
{
    cout << endl << "Decrypting message.." << endl;

    for (size_t i{ 0 }; i < message.length(); i++) // Runs through the message length
    {
        for (size_t j{ 0 }; j < key.length(); j++) // Runs through the key string length
        {
            if (message.at(i) == key.at(j) && message.at(i) != string::npos) // Looks for an equivalent in alphabet at position i in message string and replaces it with whatever is at position i in key string then breaks
            {
                message.at(i) = alphabet.at(j);
                break;
            }
        }
    }

    cout << endl << message << endl;
}

// This is another way of going through and encrypting the message using c++ string functions
void another_way(string& message, string alphabet, string key)
{

    string encrypted_message{};

    for (char c : message)
    {
        size_t position = alphabet.find(c);
        if (position != string::npos)
        {
            char new_char{ key.at(position) };
            encrypted_message += new_char;
        }
        else
        {
            encrypted_message += c;
        }
    }

    cout << endl << encrypted_message << endl;
}