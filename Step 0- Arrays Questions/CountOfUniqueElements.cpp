//<------------Brute Force Approach : O(n^2) ------------------------------------------------>
#include <iostream>
#include <vector>
using namespace std;

int countDistinctBrute(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        bool seenBefore = false;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                seenBefore = true;
                break;
            }
        }

        if (!seenBefore)
            count++;
    }

    return count;
}

int main()
{
    vector<int> arr = {2, 3, 2, 4, 4, 5};
    cout << "Count of distinct elements: " << countDistinctBrute(arr) << endl;
    return 0;
}

//<------------Optimize  Approach : O(n) : Using Hash_Map or Hash_Set ------------------------------>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int countDistinctOptimized(vector<int>& arr) {
    unordered_set<int> distinct;

    for (int num : arr) {
        distinct.insert(num);
    }

    return distinct.size();
}

int main() {
    vector<int> arr = {2, 3, 2, 4, 4, 5};
    cout << "Count of distinct elements: " << countDistinctOptimized(arr) << endl;
    return 0;
}
