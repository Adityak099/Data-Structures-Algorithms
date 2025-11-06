#include <bits/stdc++.h>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2)
{
    // Case 1: Same speed
    if (v1 == v2)
    {
        if (x1 == x2)
        {
            return "YES"; // Start at same spot, same speed
        }
        else
        {
            return "NO"; // Start apart, same speed, will never meet
        }
    }
    // Case 2 : Different speeds
    // Check if (x2 - x1) is perfectly divisible by (v1 - v2)
    if ((x2 - x1) % (v1 - v2) == 0)
    {
        // If divisible, calculate the number of jumps 'j'
        int j = (x2 - x1) / (v1 - v2);

        // Check if 'j' is non-negative (meet happens in the future)
        if (j >= 0)
        {
            return "YES";
        }
        else
        {
            return "NO"; // Meet would have happened in the past
        }
    }
    else
    {
        return "NO"; // Not perfectly divisible, they will "pass over"
    }
}
// Main function (provided by HackerRank)
int main()
{
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;

    string result = kangaroo(x1, v1, x2, v2);

    cout << result << endl;

    return 0;
}