// #include <iostream>
// using namespace std;

// void findPairSum(int arr[], int n, int target)
// {
//     bool found = false;

//     // Outer loop: picks the first number (index i)
//     for (int i = 0; i < n; i++)
//     {

//         // Inner loop: picks the second number (index j), starting at i + 1
//         for (int j = i + 1; j < n; j++)
//         {

//             // Your Core Logic:
//             if (arr[i] + arr[j] == target)
//             {
//                 cout << "Pair found! "
//                      << "Values (" << arr[i] << ", " << arr[j] << ") "
//                      << "at indices [" << i << ", " << j << "]" << endl;

//                 // Since we found a pair, we can set found to true and break out
//                 // of the inner loop (or even return from the function if only
//                 // one pair is required).
//                 found = true;
//             }
//         }
//     }

//     if (!found)
//     {
//         cout << "No pair found that sums to " << target << "." << endl;
//     }
// }

// int main()
// {
//     int numbers[] = {1, 5, 8, 2, 6};
//     int target_sum = 10;
//     int size = 5;

//     findPairSum(numbers, size, target_sum);

//     return 0;
// }

//-- --OPTIMIZED CODE USING Hash Maps(unordered_map)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function returns the indices of the pair, or {-1, -1} if no pair is found
vector<int> findPairSumOptimized(vector<int> &nums, int target)
{

    // The Hash Map: Key=Number, Value=Index
    unordered_map<int, int> num_map;

    // Single pass through the array (O(n))
    for (int i = 0; i < nums.size(); ++i)
    {
        int current_num = nums[i];

        // 1. Calculate the required complement
        int complement = target - current_num;

        // 2. Check if the complement is already in the map (O(1) check!)
        // The .count() function quickly checks if the key exists.
        if (num_map.count(complement))
        {

            // If found, we have the pair.
            // The pair is (complement's index, current number's index)
            return {num_map[complement], i};
        }

        // 3. Add the current number and its index to the map for future checks
        num_map[current_num] = i;
    }

    // If the loop finishes without finding a pair
    return {-1, -1};
}

int main()
{
    vector<int> numbers = {1, 5, 8, 2, 6};
    int target_sum = 10;

    vector<int> result = findPairSumOptimized(numbers, target_sum);

    if (result[0] != -1)
    {
        cout << "Optimized Pair Found! "
             << "Indices: [" << result[0] << ", " << result[1] << "]"
             << endl;
    }
    else
    {
        cout << "No pair found." << endl;
    }

    return 0;
}
