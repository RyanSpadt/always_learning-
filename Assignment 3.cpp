/*
* Author Ryan Spadt
* Computer Science 1, Ann Richards: 10AM-11:50AM MW
* 
* Pseudocode
* 
* This program will prompt the user to enter in the the cost of renting a room by having them enter in how many rooms they want to book, and
* the number of days they want to book.
* The cost for renting one room per night is $100.00, however there are also discounts to be accounted for.
* If they rent 10 rooms there is a 10% discount, 20 rooms a 20% discount, and at least 30 rooms for 30% discount.
* There is also a 5% discount additionally if the rooms are rented for 3 days or more.
* Also include the sales tax at 6%.
* After prompting the user the enter how many rooms they want to rent and for x amount of days.
* The program will calculate the cost of one of the rooms and all of the rooms, the discount per room, the number of rooms booked, the number of days booked, total cost of rooms,
* The sales tax and the total billing amount
*
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

// Function Declarations
void calculateCost(int, int);

int main()
{

    // User input variables
    int input_room_amount, input_days_rented;

    // Prompts the user to input the number of rooms they want to reserve
    cout << "Thank you for choosing Compsci as your hotel of choice." << endl;
    cout << "Please enter the number of rooms you wish to reserve." << endl;

    cout << '\n', cin >> input_room_amount; // Gets user input for number of rooms

    // Confirms user input and prompts for the number of days for the reserved rooms
    cout << "\n" << "You have selected to reserve " << input_room_amount << " room(s)" << endl;
    cout << "Please enter the number of days you wish to reserve the room(s) for." << endl;

    cout << '\n', cin >> input_days_rented; // Gets user input for days they wish to rent the rooms for

    // Confirms both inputs from the user
    cout << "\nYou have selected to reserve " << input_room_amount << " room(s) for " << input_days_rented << " day(s)." << endl;

    // Calls to the calculateDiscounts function
    calculateCost(input_room_amount, input_days_rented);

    return 0;
}

void calculateCost(int input_room_amount, int input_days_rented)
{

    // Variable Declarations
    const float room_cost{ 100.00f }, ten_room_discount{ 0.10f }, twenty_room_discount{ 0.20f }, thiry_room_discount{ 0.30f },
        three_day_discount{ 0.05f }, sales_tax{ 0.06f };

    float total_cost{ 0.00f }, total_discounts{ 0.00f }, original_cost{ 0.00f };

    // Calculates number of rooms discount
    if (input_room_amount < 10)
        total_discounts = 0.00;
    else if (input_room_amount >= 10 && input_room_amount < 20)
        total_discounts += ten_room_discount;
    else if (input_room_amount >= 20 && input_room_amount < 30)
        total_discounts += twenty_room_discount;
    else if (input_room_amount >= 30)
        total_discounts += thiry_room_discount;

    // If the rooms rented for 3 or more days it then adds to the discount total
    if (input_days_rented >= 3)
        total_discounts += three_day_discount;

    // Calculates the total cost for the customer including the discounts.
    total_cost = ((room_cost * input_room_amount) * input_days_rented) * (1.00 - total_discounts);

    // Calculates what the cost would be before discounts.
    original_cost = (room_cost * input_room_amount * input_days_rented);

    // Displays information about the rooms to the user
    cout << "************************************************" << endl;


    // Set cout precision to two for decimal points
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "\nOriginal cost per room for one night: $" << room_cost << endl;
    cout << "Original cost for " << input_room_amount << " room(s): $" << original_cost << endl;
    cout << "You have received " << (total_discounts * 100.0) << "% in discounts." << endl;
    cout << "Rooms booked: " << input_room_amount << endl;
    cout << "Days rooms are booked for: " << input_days_rented << endl;
    cout << "The total cost for the rooms before tax: $" << total_cost << endl;
    cout << "Sales tax: " << (sales_tax  * 100.00) << "%" << endl;
    cout << "\n************************************************" << endl;

    // Adds sales tax to total cost and displays to user
    total_cost += total_cost * sales_tax;
    cout << "Grand total: $" << total_cost << endl;
}
   