/*
Matrix operations generally fall into three categories:

1.Element-wise Operations: Operations performed on corresponding elements (e.g., adding two matrices).
----->Matrix Addition

2.Structural Operations: Operations that change the structure or orientation of the matrix (e.g., swapping rows, transposing).
------>Transpose

3.Aggregate Operations: Operations that calculate a single result from the matrix (e.g., finding the sum, max element).
----->Search


Time Complexity - O(R.C); R-->Row & C-->Column

Traversing the full matrix:
O(rows × columns)

Space Complexity:
O(rows × columns)

Basic Syntax: data_type array_name[rows][columns];
Example: int matrix[3][3];
*/
/*
//<---------------Initialization & Printing------------->
#include <iostream>
using namespace std;

int main() {
    int rows = 2, cols = 3;
    int matrix[2][3];

    cout << "Enter elements (2x3):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix is:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/

//<---------------Taking Input from User------------->
/*#include <iostream>
using namespace std;

int main() {
    int rows = 2, cols = 3;
    int matrix[2][3];

    cout << "Enter elements (2x3):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix is:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/


//<------------Using vector<vector<int>> (Dynamic Matrix)----------------->
//⚙️ Modern C++ way — no need for fixed sizes.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows = 3, cols = 3;
    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter elements (3x3):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix is:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


