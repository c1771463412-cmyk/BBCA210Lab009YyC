// COMSC-210-5293 | Lab 7 | Yuyi Chen

#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int NUM_STUDENTS = 30;
const int TARGET_GRADE = 88;

void readArray(ifstream&, array<int, NUM_STUDENTS>&);
void displayArray(const array<int, NUM_STUDENTS>&);
void readVector(ifstream&, vector<int>&);
void displayVector(const vector<int>&);

int main() {
    array<int, NUM_STUDENTS> grades;
    ifstream fin("grades.txt");

    if (!fin) {
        cout << "Open file error." << endl;
        return 1;
    }

    readArray(fin, grades);

    fin.close();

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