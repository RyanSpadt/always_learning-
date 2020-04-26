    // a pointer is a variable whose value is an address
    // the address can be another variable or function
    // you can use a pointer to access data like pass by ref or value without passing parameters
    // you can also use pointers to operate on arrays very efficiently
    // allocating memory dynamically on the heap or free store
    // OO. ponters are how polymorphism works
    // you can also use points for accessing specific addresses in memory useful for embedded and systems applications.

#include <iostream>
#include <string>

using namespace std;

int main()
{

    // Syntax of pointer
    int* int_ptr;
    double* double_ptr;
    char* char_ptr;
    //string* string_ptr{ nullptr };

    // Declaration
    string* string_ptr{ nullptr }; // nullptr = 0, implies its pointing nowhere

    // Always initialize pointer variables, otherwise they are pointing to garbage data


    // Using Pointer variables

    int num{ 10 };

    cout << "Value of num is: " << num << endl; // 10
    cout << "Size of num is: " << sizeof num << endl; // 4
    cout << "Address of num is: " << &num << endl; // some address where the int is stored in memory

    int* score_num{ nullptr };

    score_num = &num; // storing the address of the integer num

    cout << score_num << endl;


}