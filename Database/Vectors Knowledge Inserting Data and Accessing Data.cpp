#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    vector <int> test_scores{100, 98, 99};

    cout << "\nTest scoures using array syntax:" << endl; // This does not have bounds check

    cout << test_scores[0] << endl;
    cout << test_scores[1] << endl;
    cout << test_scores[2] << endl;

    cout << "\nTest scores using vector syntax:" << endl; // This has bounds checking

    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << "\nThere are " << test_scores.size() << " scores in the vector" << endl;

    cout << "\nEnter 3 test scores: ";
    cin >> test_scores.at(0);
    cin >> test_scores.at(1);
    cin >> test_scores.at(2);

    cout << "\nUpdated test scores: " << endl;

    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;

    cout << "\nEnter a test score to add to the vector: ";

    int score_to_add{ 0 };
    cin >> score_to_add;

    test_scores.push_back(score_to_add);

    cout << "\nEnter one more score to add to the vector: ";

    cin >> score_to_add;

    test_scores.push_back(score_to_add);

    cout << "\nTest scores are now: " << endl;

    for (int i = 0; i < test_scores.size(); i++)
    {
        cout << test_scores.at(i) << endl;
    }

    cout << "\nThere are now " << test_scores.size() << " scores in the vector" << endl;


    // Example of 2D vector a vector of vectors
    vector <vector<int>> movie_ratings
    {
        {1, 2, 3, 4},
        {1, 2, 4, 4},
        {1, 3, 4, 5},
    };

    cout << "\nHere are the move ratings for reviewer #1 using array syntax" << endl;
    for (int x = 0; x < 4; x++)
    {
        cout << movie_ratings[0][x] << endl;
    }

    cout << "\nHere are the movie ratings for reviewer #1 using vector syntax" << endl;
    for (int x = 0; x < 4; x++)
    {
        cout << movie_ratings.at(0).at(x) << endl;
    }

    return 0;
}