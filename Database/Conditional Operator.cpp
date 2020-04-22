#include <iostream>

using namespace std;

int main()
{
        int a{ 10 }, b{ 20 };
        int score{ 92 };
        int result{};

        result = (a > b) ? a : b;

        result = (a < b) ? (b - a) : (a - b); // if the result is true b-a if not its a - b

        result = (b != 0) ? (a / b) : 0;
    }