//<------------Brute Force Approach : O(n^2) ------------------------------------------------>
#include <iostream>
#include <vector>
using namespace std;

void countFrequencyBrute(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        bool visited = false;

        // Check if we've already counted this element
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                visited = true;
                break;
            }
        }

        if (visited)
            continue;

        int count = 1;
        for (int k = i + 1; k < n; k++)
        {
            if (arr[i] == arr[k])
            {
                count++;
            }
        }

        cout << arr[i] << " → " << count << " times" << endl;
    }
}

int main()
{
    vector<int> arr = {2, 3, 2, 4, 4, 4, 5};
    countFrequencyBrute(arr);
    return 0;
}

//<------------Optimize  Approach : O(n) : Using Hash Map ----------------------------------------->
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void countFrequencyOptimized(vector<int> &arr)
{
    unordered_map<int, int> freq;

    for (int num : arr)
    {
        freq[num]++; // increase count of each number
    }

    for (auto pair : freq)
    {
        cout << pair.first << " --> " << pair.second << " times" << endl;
    }
}

int main()
{
    vector<int> arr = {2, 3, 2, 4, 4, 4, 5};
    countFrequencyOptimized(arr);
    return 0;
}
