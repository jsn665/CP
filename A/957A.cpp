#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

int solve()
{

    int n;
    string s;
    cin >> n >> s;

    for (int i = 1; i < n; i++)
    {
        if (s[i] != '?' && s[i] == s[i - 1])
        {
            cout << "NO"
                 << "\n";
            return 0;
        }
    }
    if (s[0] == '?' || s[n - 1] == '?')
    {
        cout << "YES"
             << "\n";
        return 0;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == '?')
        {

            if (s[i - 1] == '?')
            {
                cout << "YES"
                     << "\n";
                return 0;
            }
            else if (s[i - 1] == s[i + 1])
            {
                cout << "YES"
                     << "\n";
                return 0;
            }
        }
    }
    cout << "NO"
         << "\n";
    return 0;
}

int main()
{
    // ll t;cin >> t;while(t--)
    solve();
    return 0;
}
