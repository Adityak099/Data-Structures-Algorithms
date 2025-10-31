// Problem: Printing Boundary Elements of a Matrix
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    int matrix[n][m];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\nBoundary elements are:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                cout << matrix[i][j] << " ";
            else
                cout << "  "; // just for clear visualization
        }
        cout << endl;
    }

    return 0;
}
