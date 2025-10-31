// Brute Foce Approach - O(n^3)
#include <iostream>
using namespace std;

void findTripletSumBruteForce(int arr[], int n, int target)
{
    bool found = false;

    // Outer loop (i)
    for (int i = 0; i < n - 2; i++)
    {

        // Middle loop (j) starts after i
        for (int j = i + 1; j < n - 1; j++)
        {

            // Inner loop (k) starts after j
            for (int k = j + 1; k < n; k++)
            {

                // YOUR CORE LOGIC:
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    cout << "Triplet found: "
                         << arr[i] << ", " << arr[j] << ", " << arr[k]
                         << " at indices (" << i << ", " << j << ", " << k << ")"
                         << endl;
                    found = true;
                    // Note: In real scenarios, you might return or use 'goto' to exit all loops here.
                }
            }
        }
    }

    if (!found)
    {
        cout << "No triplet found that sums to " << target << "." << endl;
    }
}

int main()
{
    int numbers[] = {2, 7, 4, 0, 9, 5};
    int target_sum = 13;
    int size = 6;

    findTripletSumBruteForce(numbers, size, target_sum);
    // Triplet: 2 + 7 + 4 = 13

    return 0;
}

// Optimized Approach - O(n^2)
#include <iostream>
#include <algorithm> // Needed for sort
#include <vector>
using namespace std;

void findTripletSumOptimized(vector<int> &nums, int target)
{
    int n = nums.size();

    // Step 1: Sort the array (O(n log n) time)
    sort(nums.begin(), nums.end());

    cout << "Target: " << target << endl;
    cout << "Triplets Found (O(n^2) method):" << endl;

    // Outer Loop: Fix the first number (O(n) time)
    for (int i = 0; i < n - 2; i++)
    {

        // Skip duplicates for the first number (optional, but good practice)
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // Step 2: Initialize Two Pointers for the remaining array (O(n) time for this inner section)
        int L = i + 1;
        int R = n - 1;

        // Inner Search Loop: Runs as long as the pointers haven't crossed
        while (L < R)
        {
            int current_sum = nums[i] + nums[L] + nums[R];

            if (current_sum == target)
            {
                // Case 3: Found a triplet!
                cout << "(" << nums[i] << ", " << nums[L] << ", " << nums[R] << ")" << endl;

                // Move both pointers to continue the search for other unique triplets
                L++;
                R--;

                // Optional: Skip inner duplicates if needed for the 3-Sum problem's specific requirements
                while (L < R && nums[L] == nums[L - 1])
                    L++;
                while (L < R && nums[R] == nums[R + 1])
                    R--;
            }
            else if (current_sum < target)
            {
                // Case 1: Sum is too small, need a larger number
                L++; // Move Left pointer to the right
            }
            else
            { // current_sum > target
                // Case 2: Sum is too large, need a smaller number
                R--; // Move Right pointer to the left
            }
        }
    }
}

int main()
{
    // Example: -1 + 0 + 1 = 0, -1 + -1 + 2 = 0
    vector<int> numbers = {-1, 0, 1, 2, -1, 4};
    int target_sum = 0;

    findTripletSumOptimized(numbers, target_sum);

    return 0;
}