#include <bits/stdc++.h>
using namespace std;

vector<int> compareTriplets(vector<int> &a, vector<int> &b)
{
    int alice_score = 0;
    int bob_score = 0;

    for (int i = 0; i < 3; i++)
    {
        if (a[i] > b[i])
        {
            alice_score++;
        }
        else if (a[i] < b[i])
        {
            bob_score++;
        }
        // If Equal no points awarded
    }
    vector<int> result = {alice_score, bob_score};

    return result;
}

int main()
{
    vector<int> a(3);
    cout << "Enter Alice Score: ";
    for (int i = 0; i < 3; ++i)
    {
        cin >> a[i];
    }

    vector<int> b(3);
    cout << "Enter Bob Score: ";
    for (int i = 0; i < 3; ++i)
    {
        cin >> b[i];
    }

    vector<int> result = compareTriplets(a, b);

    // Printing the results
    // Unsigned Integer: size_t can only hold non-negative values (0 and positive integers). This is appropriate for representing sizes and counts, which are inherently non-negative.
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[0] << " " << result[1] << endl;
    }
    cout << endl;

    return 0;
}