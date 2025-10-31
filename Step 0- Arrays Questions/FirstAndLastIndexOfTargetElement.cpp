// //<----------------Brute Force Approach : O(n)----------------->
// #include <iostream>
// #include <algorithm>

// using namespace std;

// int First_index = -1;
// int Last_index = -1;

// int main()
// {

//     // int arr[] = {5, 4, 9, 0, 3, 3, 3, 8, 1}; // UnSorted Array
//     int arr[] = {2, 3, 5, 8, 8, 8, 8, 0};
//     int target = 3;
//     int size = sizeof(arr) / sizeof(arr[0]);
//     // sort(arr, arr + size); // When the array is unsorted;
//     // for (int i : arr)
//     // {

//     //     cout << i << " ";
//     // }

//     //<-------Function to find First index------->
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == target)
//         {
//             First_index = i;
//             break;
//         }
//     }

//     //<--------Function to find Last index--------->
//     for (int i = size - 1; i >= 0; i--)
//     {
//         if (arr[i] == target)
//         {
//             Last_index = i;
//             break;
//         }
//     }

//     cout << "Index when target " << target << " " << "first appeared: " << First_index << endl;
//     cout << "Index when target " << target << " " << "last appeared: " << Last_index << endl;

//     return 0;
// }

//<------------------Optimized Approach: O(lon n) ------------->

// We will need two Binary Search Algo here.(08-10-2025)
#include <iostream>
#include <vector>
#include <algorithm> // Not strictly necessary, but good practice

// Function to find the FIRST occurrence (Logic: high = mid - 1)
int findFirstIndex(const std::vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int first_index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            first_index = mid;
            high = mid - 1; // Continue search LEFT
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first_index;
}

// Function to find the LAST occurrence (Logic: low = mid + 1)
int findLastIndex(const std::vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int last_index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            last_index = mid;
            low = mid + 1; // Continue search RIGHT
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last_index;
}

int main()
{
    // NOTE: Array must be sorted for Binary Search!
    std::vector<int> numbers = {5, 7, 7, 8, 8, 8, 10};
    int target = 8;

    int first = findFirstIndex(numbers, target);
    int last = findLastIndex(numbers, target);

    std::cout << "Optimized Search Results:" << std::endl;
    std::cout << "Target: " << target << std::endl;
    std::cout << "First Index: " << first << std::endl; // Expected: 3
    std::cout << "Last Index: " << last << std::endl;   // Expected: 5

    return 0;
}