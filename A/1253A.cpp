#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define unordered_set us
#define unordered_map um

using namespace std;
const ll md = 1000000007;

int main()
{
    ll t, n, j, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> a(n);
        vector<ll> d(n);
        for (int i = 0; i < n; i++)
        {
            cin >> j;
            a[i] = j;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            d[i] = k - a[i];
        }

        ll delta = 0;
        bool in_win = false;
        bool out_win = false;
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if (d[i] != 0)
            {
                if (out_win || (in_win && delta != d[i]) || d[i] < 0)
                {
                    ok = false;
                    break;
                }
                delta = d[i];
                in_win = true;
            }
            else
            {
                if (in_win)
                {
                    out_win = true;
                }
                in_win = false;
            }
        }
        if (ok)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
    return 0;
}