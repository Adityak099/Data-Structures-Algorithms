#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int diagonalDifference(vector<vector<int>> &arr)
{
    int arrLength = arr.size();

    int main_diagonal_sum = 0;
    int anti_diagonal_sum = 0;

    for (int i = 0; i < arrLength; i++)
    {
        main_diagonal_sum = main_diagonal_sum + arr[i][i];
        anti_diagonal_sum = anti_diagonal_sum + arr[i][arrLength - 1 - i];
    }

    return abs(main_diagonal_sum - anti_diagonal_sum);
}

int main()
{
    int arrLength;
    cout << "Enter the lenght of the array: ";
    cin >> arrLength;   

    vector<vector<int>> arr(arrLength, vector<int>(arrLength)); // Important - It make 2D array.

    for (int i = 0; i < arrLength; ++i)
    {
        for (int j = 0; j < arrLength; ++j)
        {
            cin >> arr[i][j];
        }
    }

    int result = diagonalDifference(arr);
    cout << "The Diagonal Difference is: " << result;
    return 0;
}

//<-----------Code With Edge casees Handling----------------->
// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <stdexcept>

// int diagonalDifference(const std::vector<std::vector<int>>& arr) {
//     // Edge case 1: Empty matrix
//     if (arr.empty()) {
//         return 0;
//     }

//     int n = arr.size();

//     // Edge case 2: Verify square matrix
//     for (const auto& row : arr) {
//         if (row.size() != n) {
//             throw std::invalid_argument("Matrix must be square");
//             // Or return 0 for HackerRank compatibility
//         }
//     }

//     // Edge case 3: Use long long to prevent overflow
//     long long primary_diagonal_sum = 0;
//     long long secondary_diagonal_sum = 0;

//     for (int i = 0; i < n; ++i) {
//         primary_diagonal_sum += arr[i][i];
//         secondary_diagonal_sum += arr[i][n - 1 - i];
//     }

//     // Edge case 4: Handle large differences
//     return std::abs(primary_diagonal_sum - secondary_diagonal_sum);
// }