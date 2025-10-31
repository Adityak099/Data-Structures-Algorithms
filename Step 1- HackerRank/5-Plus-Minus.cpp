#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void plusMinus(vector<int> &arr)
{
    int positive_count = 0, negative_count = 0, zero_count = 0;

    // 3. Loop and count
    for (int element : arr)
    {
        if (element > 0)
        {
            positive_count++;
        }
        else if (element < 0)
        {
            negative_count++;
        }
        else
        {
            zero_count++;
        }
    }

    // // Finding Ratios: & static casting
    double positive_count_ratio = static_cast<double>(positive_count) / arr.size();
    double negative_count_ratio = static_cast<double>(negative_count) / arr.size();
    double zero_count_ratio = static_cast<double>(zero_count) / arr.size();

    // // Printing Results:

    cout << fixed << setprecision(6) << positive_count_ratio << endl;
    cout << fixed << setprecision(6) << negative_count_ratio << endl;
    cout << fixed << setprecision(6) << zero_count_ratio << endl;
}

int main()
{

    int arrLength;
    cout << "Enter the length of the vector array: ";
    cin >> arrLength; // 5

    // vector declaration
    vector<int> arr(arrLength);

    // Input elements in vector array:
    for (int i = 0; i < arrLength; i++)
    {
        cin >> arr[i];
    }

    plusMinus(arr);

    return 0;
}