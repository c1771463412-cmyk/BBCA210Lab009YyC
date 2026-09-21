// COMSC-210-5293 | Lab 9 | Yuyi Chen

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int NUM_STUDENTS = 30;
const int TARGET_GRADE = 88;

// Array prototypes
void readArray(ifstream&, array<int, NUM_STUDENTS>&);
void displayArray(const array<int, NUM_STUDENTS>&);
void analyzeArray(array<int, NUM_STUDENTS>&);

// Vector prototypes
void readVector(ifstream&, vector<int>&);
void displayVector(const vector<int>&);
void analyzeVector(vector<int>&);

int main() {
    cout << fixed << setprecision(2);

    //Array parts
    array<int, NUM_STUDENTS> grades;
    ifstream fin("grades.txt");

    if (!fin) {
        cout << "Error: grades.txt could not be opened.\n";
        return 1;
    }

    readArray(fin, grades);

    fin.close();

    displayArray(grades);
    analyzeArray(grades);

    cout << "\n";
    for (int i = 0; i < 30; i++) {
        cout << "-";
    }

    // Vector parts
    vector<int> gradeVector;

    fin.open("grades.txt");

    if (!fin) {
        cout << "Error: grades.txt could not be opened.\n";
        return 1;
    }

    readVector(fin, gradeVector);

    fin.close();

    displayVector(gradeVector);
    analyzeVector(gradeVector);

    return 0;
}

// readArray() reads student grades from an input file
// arguments: input file and array of student grades
// returns: nothing
void readArray(ifstream& fin, array<int, NUM_STUDENTS>& grades) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        fin >> grades[i];
    }
}

// displayArray() displays student grades and basic array information
// arguments: array of student grades
// returns: nothing
void displayArray(const array<int, NUM_STUDENTS>& grades) {
    cout << "Student grades using STD::ARRAY\n\n";

    cout << "Number of students: " << grades.size() << endl;
    cout << "First grade: " << grades.front() << endl;
    cout << "Last grade: " << grades.back() << endl;
    cout << "Array empty? " << (grades.empty() ? "Yes" : "No") << endl;

    cout << "\nGrades:\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
}

// analyzeArray() analyzes and sorts student grades
// arguments: array of student grades
// returns: nothing
void analyzeArray(array<int, NUM_STUDENTS>& grades) {
    int highest = *max_element(grades.begin(), grades.end());
    int lowest = *min_element(grades.begin(), grades.end());
    int total = accumulate(grades.begin(), grades.end(), 0);
    double average = (double)total / grades.size();

    cout << "\nHighest grade: " << highest << endl;
    cout << "Lowest grade: " << lowest << endl;
    cout << "Average grade: " << average << endl;


    array<int, NUM_STUDENTS>::iterator it;
    it = find(grades.begin(), grades.end(), TARGET_GRADE);
    cout << "\nSearching for grade " << TARGET_GRADE << "...\n";
    if (it != grades.end()) {
        cout << "Grade found at position " << it - grades.begin() << endl;
    }
    else {
        cout << "Grade was not found.\n";
    }


    sort(grades.begin(), grades.end());
    cout << "\nGrades sorted from lowest to highest:\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
}

//----------------------------------------------------------------

// readVector() reads student grades from an input file
// arguments: input file and vector of student grades
// returns: nothing
void readVector(ifstream& fin, vector<int>& grades) {
    int grade;

    for (int i = 0; i < NUM_STUDENTS; i++) {
        fin >> grade;
        grades.push_back(grade);
    }
}

// displayVector() displays student grades and basic vector information
// arguments: vector of student grades
// returns: nothing
void displayVector(const vector<int>& grades) {
    cout << "\n\nStudent grades using STD::VECTOR\n\n";

    cout << "Number of students: " << grades.size() << endl;
    cout << "First grade: " << grades.front() << endl;
    cout << "Last grade: " << grades.back() << endl;
    cout << "Vector empty? " << (grades.empty() ? "Yes" : "No") << endl;

    cout << "\nGrades:\n";
    for (int i = 0; i < grades.size(); i++)
        cout << grades[i] << " ";

    cout << endl;
}

// analyzeVector() analyzes and sorts student grades
// arguments: vector of student grades
// returns: nothing
void analyzeVector(vector<int>& grades) {
    int highest = *max_element(grades.begin(), grades.end());
    int lowest = *min_element(grades.begin(), grades.end());
    int total = accumulate(grades.begin(), grades.end(), 0);
    double average = (double) total / grades.size();

    cout << "\nHighest grade: " << highest << endl;
    cout << "Lowest grade: " << lowest << endl;
    cout << "Average grade: " << average << endl;

    vector<int>::iterator it;
    it = find(grades.begin(), grades.end(), TARGET_GRADE);
    cout << "\nSearching for grade " << TARGET_GRADE << "...\n";
    if (it != grades.end()) {
        cout << "Grade found at position " << it - grades.begin() << endl;
    }
    else {
        cout << "Grade was not found.\n";
    }

    sort(grades.begin(), grades.end());
    cout << "\nGrades sorted from lowest to highest:\n";
    for (int i = 0; i < grades.size(); i++)
        cout << grades[i] << " ";

    cout << endl;
}