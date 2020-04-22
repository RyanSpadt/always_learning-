// Project16.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
 -Declare two empty vectors of integers named vector1 and vector2
 -Add 10 and 20 to vector 1 dynamically using push back
 -Display the elements in vector 1 using the at() method as well as its size
 -Add 100 and 200 to vector 2 using push back
 -Display the elements in vector2 using the at() method as well as its size
 -Declare an empty 2D vector called vector_2d
 -add vector1 and vector2 into vector_2d using pushback
 -display the elements in the vector_2d using the at() method
 -change vector1.at(0) to 100
 -display the elements in vector_2d again using the at() method
 -display elements in vector1
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector <int> vector1;
    vector <int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "The size of the vector 1 is: " << vector1.size() << endl;
    cout << "At location 0 in vector 1: " << vector1.at(0) << endl;
    cout << "At location 1 in vector 1: " << vector1.at(1) << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "\nThe size of the vector 2 is: " << vector2.size() << endl;
    cout << "At location 0 in vector 2: " << vector2.at(0) << endl;
    cout << "At location 1 in vector 2: " << vector2.at(1) << endl;

    vector <vector<int>> vector_2d;
    
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "\nThe size of the vector 2D is: " << vector_2d.size() << endl;
    cout << "At location 0 0 in vector 2D: " << vector_2d.at(0).at(0) << endl;
    cout << "At location 0 1 in vector 2D: " << vector_2d.at(0).at(1) << endl;
    cout << "At location 1 0 in vector 2D: " << vector_2d.at(1).at(0) << endl;
    cout << "At location 1 1 in vector 2D: " << vector_2d.at(1).at(1) << endl;

    vector1.at(0) = 100;

    cout << "\nAt location 0 0 in vector 2D: " << vector_2d.at(0).at(0) << endl;
    cout << "At location 0 1 in vector 2D: " << vector_2d.at(0).at(1) << endl;
    cout << "At location 1 0 in vector 2D: " << vector_2d.at(1).at(0) << endl;
    cout << "At location 1 1 in vector 2D: " << vector_2d.at(1).at(1) << endl;

    cout << "\nAt location 0 in vector 1: " << vector1.at(0) << endl;
    cout << "At location 1 in vector 1: " << vector1.at(1) << endl;
}