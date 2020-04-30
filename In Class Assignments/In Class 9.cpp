/*
* Program re-written manually.
*
* Ryan Spadt Computer Science 1 MW 10-11:50 AM
* Instructor: Ann Richards
* Assignment: In Class 04/29/2020
*
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Constants
const int max_questions{ 20 };
const int max_students{ 30 };

// Struct
struct student_rec
{
    string student_id{};
    string student_answers{};
    int raw_score{};
    double pct_score{};
};

// Prototypes
void open_file(ifstream&);
void get_key(ifstream&, string&);
double calc_score(string[], string[]);
// void headings(); Removed as it served no purpose
void read_data(ifstream&, student_rec[], int&);
void calculate(string, student_rec[], int);
void write_data(student_rec[], int&);


int main()
{
    // Variable Declarations
    ifstream in_file{};
    ofstream out_file{};
    string answer_key{};
    int num_students{};

    // Struct of students that has 30 structs.
    student_rec student[max_students];

    open_file(in_file);
    get_key(in_file, answer_key);
    read_data(in_file, student, num_students);
    calculate(answer_key, student, num_students);

    system("pause");
    return 0;
}

// Open file to read. User inputs the file name.
void open_file(ifstream& is)
{
    string file_name{};

    // is.open("ch8_ex6data.txt");

    cout << "File Name? ";
    cin >> file_name;
    is.open(file_name.c_str());

    if (!is)
    {
        cout << "Unable to open file" << file_name << endl;
        system("pause");
        exit(EXIT_FAILURE);
    }
}

// Read answer key into a string
void get_key(ifstream& is, string& key)
{
    is >> key;
    cout << key;
}

// Compare true/false answers to answer key and return the score
double calc_score(string key, string ans)
{
    double score{ 0 };

    for (unsigned int i{ 0 }; i < max_questions; ++i)
    {
        if (key[i] == ans[i])
            ++score;
    }
    cout << score << endl;
    return score;
}
// Read data into the array of structs
void read_data(ifstream& is, student_rec st[], int& how_many)
{
    how_many = 0;

    do
    {
        is >> st[how_many].student_id;
        is >> st[how_many].student_answers;

        if (is)
        {
            st[how_many].raw_score = 0;
            st[how_many].pct_score = 0;
            ++how_many;
        }
    } while (is);
}

// Updates the score in the struct
void calculate(string key, student_rec st[], int how_many)
{
    for (unsigned int i{ 0 }; i < how_many; ++i)
    {
        st[i].raw_score = calc_score(key, st[i].student_answers);
        st[i].pct_score = static_cast<double>(st[i].raw_score) / max_questions * 100.00;
        cout << st[i].pct_score << endl;
    }
    write_data(st, how_many);
}

// Writes Data to our output file
void write_data(student_rec st[], int& how_many)
{
    ofstream my_file{};
    my_file.open("ch8_ex6output.txt"); // name of output file

    cout << "Writing to file" << endl;

    my_file << fixed << showpoint << setprecision(2);
    my_file << setw(15) << left << "Student ID " << setw(15) << left << "Answers " << setw(15) << right << "Score " << setw(15) << right << "Percentage " << endl;

    for (unsigned int i{ 0 }; i < how_many; ++i)
        my_file << st[i].student_id << st[i].student_answers << st[i].raw_score << st[i].pct_score << endl;

    my_file.close();
}