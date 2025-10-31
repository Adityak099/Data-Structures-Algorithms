// Include all standard libraries for convenience
#include <bits/stdc++.h>

// Use the standard namespace to avoid prefixing std::
using namespace std;

/*
 * Function: aVeryBigSum
 * Purpose: Computes the sum of all elements in the given vector.
 * Parameters: arr - a constant reference to a vector of long long integers.
 * Returns: The total sum as a long long (note: function signature uses 'long' but should be 'long long' for consistency).
 */
long long aVeryBigSum(const vector<long long> &arr)
{
    // Initialize total_sum to 0 to start accumulation
    long long total_sum = 0;

    // Loop through each element in the array using range-based for loop
    for (long long element : arr)
    {
        // Add the current element to the running total
        total_sum = total_sum + element;
    }

    // Return the computed sum
    return total_sum;
}

// Main function where program execution begins
int main()
{
    // Declare a variable to store the number of elements in the array
    long long total_elements;

    // Prompt the user to enter the number of elements
    cout << "Enter no. of elements in the array: ";

    // Read the number of elements from standard input
    cin >> total_elements;

    // Declare a vector to store the array elements, size equal to total_elements
    vector<long long> arr(total_elements);

    // Loop to read each element into the vector
    for (long long i = 0; i < total_elements; i++)
    {
        // Read the i-th element from standard input
        cin >> arr[i];
    }

    // Call the aVeryBigSum function to compute the sum and store the result
    long long result = aVeryBigSum(arr);

    // Output the total sum to the console
    cout << "Total sum of array elements: " << result;

    // Return 0 to indicate successful program execution
    return 0;
}
