#include <iostream>

using std::cout;
using std::endl;

// Function Prototypes
int* apply_all(const int* const, const size_t, const int* const, const size_t);
void print(const int* const, const size_t);

int main()
{
	// Our two arrays local
	int array1[] { 1,2,3,4,5 };
	int array2[] {10,20,30};

	// Array sizes
	const size_t array1_size { 5 };
	const size_t array2_size { 3 };

	cout << "Array 1: ";
	print(array1, array1_size);

	cout << "Array 2: ";
	print(array2, array2_size);

	int* results = apply_all(array1, array1_size, array2, array2_size);
	cout << "Result: ";

	const size_t array3_size = (array1_size * array2_size);
	print(results, array3_size);

	delete[] results;

	/* Output
	* 
	* Array 1: [1 2 3 4 5 ]
	* Array 2: [10, 20, 30 ]
	* Result: [10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
	* 
	*/
	return 0;
}

// Functions that expects two arrays of integers and their sizes
// It then dynamically allocates a new array of ints whose size is the product of the 2 array sizes
// It will loop through the second array and multiply each element across each element of the first array
// Store the product of that in the newly created array
// Return a pointer to the new array
int* apply_all(const int* const ar1, const size_t s1, const int* const ar2, const size_t s2)
{
	int* result = new int[s1 * s2]; // Dynamically allocate new array of size 15

	for (int i{ 0 }; i < s2; i++) // Loop through the arrays
		for (int j{ 0 }; j < s1; j++)
			*result++ = (*(ar2 + i) * *(ar1 + j)); // result[index] = value at array2 * value at array1 then it increments our result pointer after the assignment

	result -= (s1 * s2); // reset pointer to index 0

	return result;
}

// Function accepts a pointer to an array and an integer of size of the array
// It then loops through the array printing out the values 1 by 1
void print(const int* const p, const size_t s)
{
	cout << "[ ";
	for (int i{ 0 }; i < s; i++)
		cout << *(p + i) << " ";
	cout << "]" << endl;
}