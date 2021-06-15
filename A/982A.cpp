#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

/*
Idea: Just do what is being told and be careful with edge cases such as 0011 and 100
*/
int main()
{
    int n;
    cin >> n;
    vector<char> seats(n);
    for (int i = 0; i < n; i++)
    {
        char s;
        cin >> s;
        seats[i] = s;
    }
    if (n == 1 && seats[0] == '0')
    {
        cout << "No"
             << "\n";
        return 0;
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        if (seats[i] == '1' && (seats[i - 1] == '1' || seats[i + 1] == '1'))
        {
            ok = false;
            break;
        }
        else if (seats[i] == '0' && (seats[i - 1] == '0' && seats[i + 1] == '0') || (i == 0 && seats[i] == '0' && seats[i + 1] == '0') || (i == n - 1 && seats[i] == '0' && seats[i - 1] == '0'))
        {
            ok = false;
            break;
        }
    }
    if (ok)
    {
        cout << "Yes"
             << "\n";
    }
    else
    {
        cout << "No"
             << "\n";
    }
    return 0;
}