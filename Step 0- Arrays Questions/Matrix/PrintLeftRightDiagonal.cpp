//Problem : Print left diagonal and right diagonal with repeating and without repeating
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int matrix[n][n];
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\nLeft Diagonal (Main): ";
    for (int i = 0; i < n; i++)
    {
        cout << matrix[i][i] << " ";
    }

    cout << "\nRight Diagonal (Anti): ";
    for (int i = 0; i < n; i++)
    {
        cout << matrix[i][n - 1 - i] << " ";
    }

    cout << "\n\nDiagonals (Without repeating common element): ";
    for (int i = 0; i < n; i++)
    {
        cout << matrix[i][i] << " "; // Left diagonal
    }
    for (int i = 0; i < n; i++)
    {
        // Skip the middle element if it’s the same
        if (i != n - 1 - i)
            cout << matrix[i][n - 1 - i] << " ";
    }

    return 0;
}

//--------------------------------------------
// #include <iostream>

// using namespace std;

// int main()
// {
//     int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int row = sizeof(arr) / sizeof(arr[0]);
//     int col = sizeof(arr[0]) / sizeof(arr[0][0]);

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (i == j)
//             {
//                 cout << arr[i][j] << " ";
//             }
//         }
//     }

//     cout << endl;

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (i + j == row - 1 && i != j)
//             {
//                 cout << arr[i][j] << " ";
//             }
//         }
//     }
// }