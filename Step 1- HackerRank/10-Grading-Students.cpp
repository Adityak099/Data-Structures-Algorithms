#include <iostream>
#include <vector>

using namespace std;

// Function that applies grading rules to student scores
vector<int> gradingStudents(vector<int> grades)
{
    for (int &grade : grades)
    {
        // Only grades >= 38 can be rounded (38 → 40 passes)
        if (grade >= 38)
        {
            int remainder = grade % 5; // How far from next multiple of 5?

            // If difference is less than 3 → round up
            if (remainder > 2)
            {
                grade += (5 - remainder);
            }
        }
    }
    return grades;
}

// Function to display grades
void displayGrades(const vector<int> &grades)
{
    cout << "\nFinal Grades:\n";
    for (int grade : grades)
    {
        cout << grade << endl;
    }
}

int main()
{
    int n;

    // Taking number of grades with validation
    cout << "Enter the number of grades: ";
    cin >> n;

    while (n <= 0)
    {
        cout << "Invalid input! Number of grades must be positive.\n";
        cout << "Enter again: ";
        cin >> n;
    }

    vector<int> grades(n);

    cout << "Enter the grades (0 to 100):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> grades[i];

        // Validate each grade
        while (grades[i] < 0 || grades[i] > 100)
        {
            cout << "Grade must be between 0 and 100. Enter again: ";
            cin >> grades[i];
        }
    }

    // Process and display updated grades
    vector<int> results = gradingStudents(grades);
    displayGrades(results);

    return 0;
}
