//<-------------------Using Normal Method: Index based for loop-------------------------->
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 10, 11};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     int total_sum = 0;

//     for (int i = 0; i < size; i++)
//     {
//         total_sum = total_sum + arr[i];
//     }

//     cout << "Size of Array: " << size << endl;
//     cout << "Total Sum of the elements of the array is: " << total_sum << endl;

//     return 0;
// }

//<-------------------------Using Custom function, Vector and range based Loop----------------------->
#include <iostream>
#include <vector>
using namespace std;

int arraySum(const vector<int> &arr)
{
    int total_sum = 0;

    // Range based looping through each elements in the array
    for (int element : arr)
    {
        total_sum = total_sum + element;
    }

    return total_sum;
}

int main()
{
    int total_elements; // stores the total number of elements in the array.
    cout << "Enter no. of elements in the array: ";
    cin >> total_elements;

    vector<int> arr(total_elements);

    for (int i = 0; i < total_elements; i++)
    {
        cin >> arr[i];
    }

    int result = arraySum(arr);
    cout << "Total sum of array elements: " << result;

    return 0;
}