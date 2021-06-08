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
    ll n, k, res;
    cin >> n >> k;
    char a;
    vector<char> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v[i] = a;
    }
    sort(v.begin(), v.end());
    k--;
    char l = v[0];
    res = l - 'a' + 1;

    for (int i = 1; i < n && k > 0; i++)
    {
        if ((v[i] - 'a') - (l - 'a') >= 2)
        {
            l = v[i];
            k--;
            res += v[i] - 'a' + 1;
        }
    }
    if (k != 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << res << "\n";
    }

    return 0;
}
