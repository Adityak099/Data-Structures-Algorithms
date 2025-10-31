#include <iostream>
using namespace std;

int main()
{
    int row, col;
    cout << "Enter no. of rows: " << endl;
    cin >> row;
    cout << "Enter no. of columns: " << endl;
    cin >> col;

    int matrix[row][col];

    //<----------taking Input for the Matrix------------->
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    //<----------------Printing the Original Matrix------------------>
    cout << "Matrix formed from the input :" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //<--------------Printing the Transpose of the Matrix------------------->
    cout << "Printing the Transpose of the Original Matrix: " << endl;
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //<--------------Printing the pattern in Snake Pattern--------------->
    cout << "Matrix in Snake Pattern: " << endl;
    /* Printing Logic:
            For even rows--> Print Left to right
            For odd rows--> Print right to left
    */

    for (int i = 0; i < row; i++)
    {
        if (i % 2 == 0) // BE CAREFUL HERE
        {
            // even row - Left to right
            for (int j = 0; j < col; j++)
            {
                cout << matrix[i][j] << " ";
            }
        }
        else
        {
            for (int j = col - 1; j >= 0; j--)
            {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
