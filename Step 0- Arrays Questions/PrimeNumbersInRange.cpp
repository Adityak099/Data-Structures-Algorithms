// Optimized approaach: Time Complexity= O(R⋅√N)
#include <iostream>
#include <cmath>
using namespace std;

// Step 1: The Optimized Primality Check Function (Your logic)
bool isPrime(int N)
{
    // 1.Edge cases
    if (N <= 1)
    {
        return false;
    }
    if (N <= 3)
    {
        return true;
    }

    // 2. Optimized loop:  Check from 2 up to the square root of N
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            return false;
        }
    }
    return true;
}

// Step 2: The Range Function (The missing piece)
void findPrimesInRange(int start, int end)
{
    cout << "Prime numbers between " << start << " and " << end << ":" << endl;

    // Outer loop: iterates through every number in the given range
    for (int i = start; i <= end; i++)
    {

        // Inner check: use our isPrime function on the current number 'i'
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int start_range = 10;
    int end_range = 50;

    findPrimesInRange(start_range, end_range);

    return 0;
}