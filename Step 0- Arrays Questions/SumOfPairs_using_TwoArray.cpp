// Brute Force Approach - TC - O(N.M)
#include <iostream>

void findPairInTwoArrays(int A[], int N, int B[], int M, int target)
{
    bool found = false;

    // Outer loop iterates over Array A
    for (int i = 0; i < N; i++)
    {
        // Inner loop iterates over Array B
        for (int j = 0; j < M; j++)
        {
            // Your Core Logic:
            if (A[i] + B[j] == target)
            {
                std::cout << "Pair found! "
                          << "Values (" << A[i] << ", " << B[j] << ") "
                          << "at indices [A:" << i << ", B:" << j << "]" << std::endl;

                found = true;
                // If we only need the first pair, we can use a break or return here
                return;
            }
        }
    }

    if (!found)
    {
        std::cout << "No pair found that sums to " << target << "." << std::endl;
    }
}

int main()
{
    int A[] = {1, 5, 8, 2};
    int B[] = {3, 7, 4, 9};
    int target_sum = 10;

    findPairInTwoArrays(A, 4, B, 4, target_sum); // 1 + 9 = 10, 3 + 7 = 10, etc.

    return 0;
}

// //Optimized approact by using hash Maps , TC - O(N+M)
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// // Function returns true if a pair is found, false otherwise
// bool findPairInTwoArraysOptimized(const vector<int> &A, const vector<int> &B, int target)
// {

//     // Phase 1: Build the map from the FIRST array (O(N) time)
//     // Key: Number from Array A, Value: Index in Array A
//     unordered_map<int, int> map_A;

//     for (int i = 0; i < A.size(); ++i)
//     {
//         map_A[A[i]] = i;
//     }

//     // Phase 2: Iterate through the SECOND array and search (O(M) time)
//     for (int j = 0; j < B.size(); ++j)
//     {
//         int complement = target - B[j];

//         // Check the map instantly for the required complement (O(1) time)
//         if (map_A.count(complement))
//         {

//             // Found a pair!
//             cout << "Optimized Pair Found! "
//                  << "Values (" << complement << ", " << B[j] << ") "
//                  << "at indices [A:" << map_A[complement] << ", B:" << j << "]"
//                  << endl;
//             return true;
//         }
//     }

//     // If the loop finishes
//     cout << "No pair found that sums to " << target << "." << endl;
//     return false;
// }

// int main()
// {
//     vector<int> A = {1, 5, 8, 2}; // N=4
//     vector<int> B = {3, 7, 4, 9}; // M=4
//     int target_sum = 10;

//     findPairInTwoArraysOptimized(A, B, target_sum);

//     return 0;
// }