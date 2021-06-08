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
    ll n, s, a, t1, t2;
    cin >> n;
    s = n * 2;
    vector<ll> v(s);
    for (int i = 0; i < s; i++)
    {
        cin >> a;
        v[i] = a;
    }
    sort(v.begin(), v.end(), greater<ll>());
    t1 = 0;
    t2 = 0;
    for (int i = 0; i < n; i++)
    {
        t1 += v[i];
    }
    for (int i = v.size() - 1; i >= n; i--)
    {
        t2 += v[i];
    }
    if (t1 == t2)
    {
        cout << -1 << "\n";
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}