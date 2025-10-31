#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//Works for both sorted and unsorted array

void miniMaxSum(const vector<int> &arr)
{
    int min_element = INT_MAX;
    int max_element = INT_MIN;

    long long total_sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        total_sum = total_sum + arr[i]; // Important , Remember carefully;

        if (arr[i] > max_element)
        {
            max_element = arr[i];
        }

        if (arr[i] < min_element)
        {
            min_element = arr[i];
        }
    }
    // 5. Calculate the minimum sum (by excluding the max element)
    long long min_sum = total_sum - max_element;

    // 6. Calculate the maximum sum (by excluding the min element)
    long long max_sum = total_sum - min_element;

    // 7. Print the results
    cout << min_sum << " " << max_sum << endl;
}

int main()
{
    vector<int> arr(5);

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    miniMaxSum(arr);

    return 0;
}