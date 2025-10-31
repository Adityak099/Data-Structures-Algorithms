#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int birthdayCakeCandles(vector<int> &candles)
{
    // 1. Initialize max height to the smallest possible integer
    long long max_height = INT_MIN;
    // 2. Initialize the counter
    int tallest_candele_count = 0;

    // 3. Loop through each candle
    for (int i = 0; i < candles.size(); i++)
    {
        // 4. Check the cases
        if (max_height < candles[i])
        {
            // Case 1: Found a new tallest candle
            max_height = candles[i];
            tallest_candele_count = 1; // Reset the count
        }
        else if (max_height == candles[i])
        {
            // Case 2: Found another candle of the same max height
            tallest_candele_count++;
        }
    }

    // 5. Return the final count
    return tallest_candele_count;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> candles(n); // Vector with n elements;

    for (int i = 0; i < n; i++)
    {
        cin >> candles[i];
    }

    int result = birthdayCakeCandles(candles);

    cout << "Result : " << result;

    return 0;
}