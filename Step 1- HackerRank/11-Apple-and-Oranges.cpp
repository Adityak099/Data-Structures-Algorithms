#include <iostream>
#include <vector>

using namespace std;
/*
 * Complete the 'countApplesAndOranges' function below.
 *
 * The function accepts following parameters:
 * 1. INTEGER s (house start)
 * 2. INTEGER t (house end)
 * 3. INTEGER a (apple tree position)
 * 4. INTEGER b (orange tree position)
 * 5. INTEGER_ARRAY apples (distances)
 * 6. INTEGER_ARRAY oranges (distances)
 */
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges)
{
    // variable declaration
    int appleCount = 0;
    int orangeCount = 0;

    // looping through apples
    for (int i = 0; i < apples.size(); i++)
    {
        int location = apples[i] + a;
        if (location >= s && location <= t)
        {
            appleCount++;
        }
    }

    // Loop through oranges
    for (int i = 0; i < oranges.size(); i++)
    {
        int loaction = oranges[i] + b;
        if (loaction >= s && loaction <= t)
        {
            orangeCount++;
        }
    }

    // Prinnting results
    cout << "Apple Count: " << appleCount << endl;
    cout << "Orange Count: " << orangeCount << endl;
}

int main()
{
    /*
    s: The starting position of the house (integer).
    t: The ending position of the house (integer).
    a: The position of the apple tree (integer).
    b: The position of the orange tree (integer).
    m: The number of apples (integer).
    n: The number of oranges (integer).

    */

    int s, t, a, b, m, n;
    cin >> s >> t;
    cin >> a >> b;
    cin >> m >> n;
    vector<int> apples(m);
    for (int i = 0; i < m; i++)
    {
        cin >> apples[i];
    }
    vector<int> oranges(n);
    for (int i = 0; i < n; i++)
    {
        cin >> oranges[i];
    }
    countApplesAndOranges(s, t, a, b, apples, oranges);
    return 0;
}
