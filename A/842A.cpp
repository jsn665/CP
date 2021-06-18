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

void YES()
{
    cout << "YES"
         << "\n";
    exit(0);
}
void NO()
{
    cout << "NO"
         << "\n";
    exit(0);
}

int solve()
{
    ll l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    for (; l <= r; l++)
    {
        ll n = l / k;
        if (n >= x && n <= y && l % n == 0 && l / n == k)
        {
            YES();
        }
    }
    NO();
    return 0;
}

int main()
{
    // ll t;cin >> t;while(t--)
    solve();
    return 0;
}