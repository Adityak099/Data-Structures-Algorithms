#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int matrix[n][n];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\nZ Matrix pattern:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || i + j == n - 1)
                cout << matrix[i][j] << " ";
            else
                cout << "  "; // just for visual shape
        }
        cout << endl;
    }

    return 0;
}

//<-------------Z matrix pattern in a single line — without formatting it into the “Z” shape visually.---------------------->
// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter size of square matrix: ";
//     cin >> n;

//     int matrix[n][n];
//     cout << "Enter matrix elements:\n";
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> matrix[i][j];
//         }
//     }

//     cout << "\nZ Pattern Elements (Single Line): ";

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i == 0 || i == n - 1 || i + j == n - 1)
//                 cout << matrix[i][j] << " ";
//         }
//     }

//     return 0;
// }
