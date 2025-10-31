// // Brute force Approach - O(n^3)
// #include <iostream>

// using namespace std;

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6};

//     int n = sizeof(arr) / sizeof(arr[0]);

//     int odd_count = 0;
//     int even_count = 0;

//     for (int i = 0; i < n - 2; i++)
//     {
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             for (int k = j + 1; k < n; k++)
//             {
//                 int triplet_sum = arr[i] + arr[j] + arr[k];
//                 if (triplet_sum % 2 == 0)
//                 {
//                     even_count++;
//                 }
//                 else
//                 {
//                     odd_count++;
//                 }
//             }
//         }
//     }
//     cout << even_count << " " << odd_count;

//     return 0;
// }

// ----------------Optimized Approach - O(n)-----------------------------
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 1. Helper Function: Calculates Combinations (n choose k)
// n is the total number of objects & k is the number of objects choosen at once
// We use long long to prevent overflow, as factorials grow fast.
long long combinations(int n, int k)
{
    if (k < 0 || k > n)
    {
        return 0; // Cannot choose more items than available
    }
    if (k == 0 || k == n)
    {
        return 1;
    }
    if (k > n / 2)
    {
        k = n - k; // Optimization: C(n, k) = C(n, n-k)
    }

    /*
    | Step             | Meaning                                                    |
    | ---------------- | ---------------------------------------------------------- |
    | `if (k > n / 2)` | Check if k is larger than half of n                        |
    | `k = n - k;`     | Replace k with its smaller complement(minus)               |
    | **Why?**         | Because C(n, k) = C(n, n-k), and this reduces calculations |
    | **Example:**     | C(10, 8) = C(10, 2) — compute 2 instead of 8 loops         |

    */

    // Iterative calculation to avoid large factorials (safer)
    long long result = 1;
    for (int i = 1; i <= k; ++i)
    {
        result = result * (n - i + 1) / i;
    }
    return result;
}

// 2. Main Function: Counts Even and Odd Triplets
void countParityTriplets(const vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
    {
        cout << "Array must have at least 3 elements." << endl;
        return;
    }

    // Step 1: Count Evens (CE) and Odds (CO) in the array
    int count_even = 0;
    int count_odd = 0;
    for (int num : nums)
    {
        if (num % 2 == 0)
        {
            count_even++;
        }
        else
        {
            count_odd++;
        }
    }

    // --- CALCULATING EVEN TRIPLETS ---

    // Way 1: Three Even numbers (E + E + E)
    // Formula: C(CE, 3)
    long long even_triplets_way1 = combinations(count_even, 3);

    // Way 2: One Even and Two Odd numbers (E + O + O)
    // Formula: C(CE, 1) * C(CO, 2)
    long long even_triplets_way2 = combinations(count_even, 1) * combinations(count_odd, 2);

    long long total_even_triplets = even_triplets_way1 + even_triplets_way2;

    // --- CALCULATING ODD TRIPLETS ---

    // Way 3: Three Odd numbers (O + O + O)
    // Formula: C(CO, 3)
    long long odd_triplets_way3 = combinations(count_odd, 3);

    // Way 4: Two Even and One Odd number (E + E + O)
    // Formula: C(CE, 2) * C(CO, 1)
    long long odd_triplets_way4 = combinations(count_even, 2) * combinations(count_odd, 1);

    long long total_odd_triplets = odd_triplets_way3 + odd_triplets_way4;

    // --- OUTPUT ---
    cout << "\n--- Triplet Count Results ---" << endl;
    cout << "Even Numbers in Array (CE): " << count_even << endl;
    cout << "Odd Numbers in Array (CO): " << count_odd << endl;
    cout << "Total Even Triplet Sums: " << total_even_triplets << endl;
    cout << "Total Odd Triplet Sums: " << total_odd_triplets << endl;
}

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6}; // CE=3 (2,4,6), CO=3 (1,3,5)

    countParityTriplets(numbers);

    return 0;
}