#include <iostream>
#include <cmath>
#include <algorithm> // For swap if needed, but not strictly necessary here
using namespace std;

// Step 1: Your function to reverse a single number
long long reverseNumber(int N)
{
    long long reversed_num = 0;
    int temp = N;

    while (temp > 0)
    {
        int digit = temp % 10;

        // The core logic we figured out: shift and add
        reversed_num = (reversed_num * 10) + digit;

        temp = temp / 10;
    }
    return reversed_num;
}

// Step 2: Function to iterate the range and sum the reversed numbers
long long reverseNumberSumInRange(int start, int end)
{
    // Accumulator initialized to 0, just as you said
    long long total_reversed_sum = 0;

    // Outer loop: Iterate through every number in the range
    for (int i = start; i <= end; i++)
    {

        // Reverse the current number
        long long reversed_val = reverseNumber(i);

        // Add the reversed value to the running total
        total_reversed_sum += reversed_val;
    }

    return total_reversed_sum;
}

int main()
{
    int start_range = 10;
    int end_range = 15; // Numbers: 10, 11, 12, 13, 14, 15

    long long final_sum = reverseNumberSumInRange(start_range, end_range);

    cout << "The total sum of reversed numbers from "
         << start_range << " to " << end_range << " is: "
         << final_sum << endl;

    // Expected output check: Rev(10)=1, Rev(11)=11, Rev(12)=21, Rev(13)=31, Rev(14)=41, Rev(15)=51
    // Sum: 1 + 11 + 21 + 31 + 41 + 51 = 156

    return 0;
}