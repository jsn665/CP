#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

// ll lpow(ll a, ll b){ll res = 1;while (b){if ((b & 1) == 1)res *= a;b >>= 1;a *= a;}return res;}
// ll gcd(ll a, ll b){while (b){a %= b;swap(a, b);}return a;}


int solve()
{
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        if (s == t)
        {
            cout << "YES"
                 << "\n";
            return 0;
        }
        else
        {
            cout << "NO"
                 << "\n";
            return 0;
        }
    }

    int i = 0;
    for (; i < n; i++)
    {
        if (s[i] != t[i])
        {
            break;
        }
    }
    int j = n - 1;
    int temp = m - 1;
    while (j > i && temp >= i)
    {
        if (s[j] != t[temp])
        {
            break;
        }
        j--;
        temp--;
    }

    if (i == j && s[i] == '*' && s[j] == '*')
    {
        cout << "YES"
             << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }
    return 0;
}

int main()
{
    // ll t;cin >> t;while(t--)
    solve();
    return 0;
}