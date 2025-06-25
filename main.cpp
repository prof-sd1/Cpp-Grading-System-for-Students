#include <iostream>      // For input/output operations
#include <vector>        // To use dynamic arrays (vectors)
#include <iomanip>       // For formatting output (setw, setprecision)

using namespace std;

// Function to calculate and return the letter grade based on average marks
string calculateGrade(float average) {
    if (average >= 90)
        return "A+";
    else if (average >= 80)
        return "A";
    else if (average >= 70)
        return "B";
    else if (average >= 60)
        return "C";
    else if (average >= 50)
        return "D";
    else
        return "F";
}

int main() {
    int numStudents, numSubjects;

    // Prompt user for number of students
    cout << "Enter number of students: ";
    cin >> numStudents;

    // Prompt user for number of subjects
    cout << "Enter number of subjects: ";
    cin >> numSubjects;

    // Vector to store subject names
    vector<string> subjectNames(numSubjects);

    // Input names of subjects
    for (int i = 0; i < numSubjects; ++i) {
        cout << "Enter name of subject " << i + 1 << ": ";
        cin >> subjectNames[i];
    }

    // Vector to store each student's name
    vector<string> studentNames(numStudents);

    // 2D vector to store marks of each student in all subjects
    vector<vector<float>> studentMarks(numStudents, vector<float>(numSubjects));

    // Vectors to store total marks, average, and grade for each student
    vector<float> totals(numStudents, 0);         // Initialized with 0
    vector<float> averages(numStudents);
    vector<string> grades(numStudents);

    // Input marks for each student
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nEnter student name: ";
        cin >> studentNames[i];   // Store the student's name
        float sum = 0;            // Sum of marks for current student

        // Input marks for each subject
        for (int j = 0; j < numSubjects; ++j) {
            cout << "Enter marks for " << subjectNames[j] << ": ";
            cin >> studentMarks[i][j];  // Store mark
            sum += studentMarks[i][j];  // Add to sum
        }

        // Calculate total and average
        totals[i] = sum;
        averages[i] = sum / numSubjects;

        // Calculate and store letter grade
        grades[i] = calculateGrade(averages[i]);
    }

    // Display report card header
    cout << "\n📝 Student Report Card\n";
    cout << left << setw(15) << "Name"
         << setw(10) << "Total"
         << setw(10) << "Average"
         << setw(8) << "Grade" << endl;

    cout << "----------------------------------------\n";

    // Display report card for each student
    for (int i = 0; i < numStudents; ++i) {
        cout << left << setw(15) << studentNames[i]                         // Name
             << setw(10) << fixed << setprecision(2) << totals[i]          // Total
             << setw(10) << fixed << setprecision(2) << averages[i]        // Average
             << setw(8) << grades[i] << endl;                              // Grade
    }

    return 0;
}
