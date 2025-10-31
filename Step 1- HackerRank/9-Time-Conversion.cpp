#include <iostream>
#include <string>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string timeConversion(string s)
{
    if (s.length() == 9)
    {
        s = "0" + s;
    }
    // 1. Get the period (AM/PM)
    string period = s.substr(8, 2); // Get 2 chars starting at index 8

    // 2. Get the hour string
    string hour_str = s.substr(0, 2); // Get 2 chars starting at index 0

    // 3. Get the middle part (minutes and seconds)
    string middle = s.substr(2, 6); // Get 6 chars starting at index 2

    int hour_int = stoi(hour_str); // Convert hour string to integer

    // 4. Apply conversion rules
    if (period == "AM")
    {
        if (hour_int == 12)
        {
            hour_str = "00"; // 12 AM becomes 00
        }
    }
    else
    { // period must be "PM"
        if (hour_int != 12)
        {
            hour_int += 12; // Add 12 to all PM hours except 12 PM
            hour_str = to_string(hour_int);

            if (hour_str.length() == 1)
            {
                hour_str = "0" + hour_str;
            }
        }
    }

    // 5. Combine and return
    return hour_str + middle;
}

// Main function (provided by HackerRank)
int main()
{
    string s;
    cin >> s;

    string result = timeConversion(s);

    cout << result << endl;

    return 0;
}