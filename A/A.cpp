#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long

using namespace std;
const ll md = 1000000007;

// ll lpow(ll a, ll b){ll res = 1;while (b){if ((b & 1) == 1)res *= a;b >>= 1;a *= a;}return res;}
// ll gcd(ll a, ll b){while (b){a %= b;swap(a, b);}return a;}

int main()
{
    ll n, m, l, s, res;
    cin >> n;
    vector<ll> v(n);
    m = 0;
    l = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v[i] = s;
        m = max(m, s);
        l = min(l, s);
    }
    res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (m > v[i] && l < v[i])
        {
            res += 1;
        }
    }
    cout << res << "\n";
    return 0;
}
