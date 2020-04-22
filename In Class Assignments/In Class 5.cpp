/*
* Author Ryan Spadt
* In Class March 4, 2020 for Computer Science 1 10AM-11:50AM MW with Professor Ann Richards
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;

int main()
{
	int count{ 0 };  // total dice rolls
	int total{ 0 };	// total of 2 dice

	do {


		total = (rand() % 7) + (rand() % 7);
		//cout << total << " Total " << endl;

		while (total <= 1) {
			total = ((rand() % 7) + (rand() % 7));

			//cout << total << " Total in WHILE " << endl;
		}

		cout << total << " Total " << endl;
		count++;
		//if (count == 12)
			//break;
	} while ((count <= 12) && (total >= 2 && total <= 12));

	return 0;
}
