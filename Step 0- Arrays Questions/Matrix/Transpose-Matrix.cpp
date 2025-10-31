// #include <iostream>
// using namespace std;

// int main() {
//     int rows, cols;
//     cout<<"Enter rows and columns: ";
//     cin >> rows >> cols;

//     int matrix[rows][cols];

//     // Input matrix elements
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             cin >> matrix[i][j];
//         }

//     }

//     cout<<"Original Matrix: "<<endl;
//     //printing Original matrix
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             cout<< matrix[i][j]<< " ";
//         }
//         cout<<endl;

//     }

//     cout<<"Transpose matrix: "<<endl;
//     // Print transpose
//     for (int j = 0; j < cols; j++) {         // start with column
//         for (int i = 0; i < rows; i++) {     // then go to row
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }




//<<------------------------------Using Function method---------------------------------------->
#include <iostream>
#include <vector>
#include <iomanip> // For formatting output

using namespace std;

// Function to print any matrix (used for both original and transposed)
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            // Use setw(4) for cleaner column alignment
            cout << setw(4) << val;
        }
        cout << endl;
    }
}

// Function to perform the transpose operation
vector<vector<int>> transposeMatrix(const vector<vector<int>> &original, int ROWS, int COLS)
{

    // The dimensions of the transposed matrix are swapped: COLS x ROWS
    vector<vector<int>> transposed(COLS, vector<int>(ROWS));

    // Outer loop iterates over the new rows (j index in original)
    for (int j = 0; j < COLS; j++)
    {

        // Inner loop iterates over the new columns (i index in original)
        for (int i = 0; i < ROWS; i++)
        {

            // Core Transpose Logic: Original[i][j] moves to Transposed[j][i]
            transposed[j][i] = original[i][j];
        }
    }

    return transposed;
}

int main()
{
    // Define the original matrix (4 Rows x 3 Columns)
    const int ROWS = 4;
    const int COLS = 3;

    vector<vector<int>> matrixA = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {0, 1, 0}};

    // 1. Print Original Matrix
    cout << "--- Original Matrix A (" << ROWS << "x" << COLS << ") ---" << endl;
    printMatrix(matrixA);

    // 2. Perform Transpose
    vector<vector<int>> matrixT = transposeMatrix(matrixA, ROWS, COLS);

    // 3. Print Transposed Matrix
    cout << "\n--- Transposed Matrix A^T (" << COLS << "x" << ROWS << ") ---" << endl;
    printMatrix(matrixT);

    return 0;
}