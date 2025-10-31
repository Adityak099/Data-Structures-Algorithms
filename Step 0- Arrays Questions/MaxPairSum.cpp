// Brute Force - O(n^2)
// #include <iostream>
// #include <limits> // Required for numeric_limits<int>::min()
// using namespace std;

// void maxPairSumBruteForce(int arr[], int n)
// {

//     // Initialize to the smallest possible integer for safety
//     int max_pair_sum = numeric_limits<int>::min();

//     // O(n^2) nested loops to check every unique pair
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {

//             int current_sum = arr[i] + arr[j];

//             // If the current sum is bigger, update the maximum
//             if (current_sum > max_pair_sum)
//             {
//                 max_pair_sum = current_sum;
//             }
//         }
//     }

//     cout << "Brute Force Max Pair Sum: " << max_pair_sum << endl;
// }

// int main()
// {
//     int numbers[] = {5, 2, 9, 1, 7};
//     int size = 5;

//     maxPairSumBruteForce(numbers, size); // Should output 9 + 7 = 16

//     return 0;
// }


//Optimized Approach - O(n)

#include <iostream>
#include <limits> // Required for INT_MIN

void maxPairSumOptimized(int arr[], int n) {
    // Initialize both to the smallest possible integer for safety
    int first_max = std::numeric_limits<int>::min(); 
    int second_max = std::numeric_limits<int>::min(); 

    // O(n) single loop
    for (int i = 0; i < n; i++) {
        
        // 1. Is the current number the new largest?
        if (arr[i] > first_max) {
            second_max = first_max; // The old first_max drops to second place
            first_max = arr[i];     // current_num is the new largest
        } 
        
        // 2. Is the current number the new second largest?
        // (We use 'else if' because a number can't be both first and second max)
        else if (arr[i] > second_max) {
            second_max = arr[i];
        }
    }
    
    // The maximum pair sum is simply the sum of the two largest numbers found
    int max_pair_sum = first_max + second_max;
    
    std::cout << "Optimized Max Pair Sum: " << max_pair_sum << std::endl;
    std::cout << "(Found by adding " << first_max << " and " << second_max << ")" << std::endl;
}

int main() {
    int numbers[] = {5, 2, 9, 1, 7};
    int size = 5;

    maxPairSumOptimized(numbers, size); // Should output 9 + 7 = 16

    return 0;
}