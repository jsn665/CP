#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define us unordered_set
#define um unordered_map

using namespace std;
const ll md = 1000000007;

// ll lpow(ll a, ll b){ll res = 1;while (b){if ((b & 1) == 1)res *= a;b >>= 1;a *= a;}return res;}
// ll gcd(ll a, ll b){while (b){a %= b;swap(a, b);}return a;}

int main()
{
    string s;
    ll k;
    cin >> s >> k;
    us<char> u;
    for (int i = 0; i < s.length(); i++)
    {
        u.insert(s[i]);
    }
    if (u.size() >= k)
    {
        cout << 0 << "\n";
    }
    else if (u.size() < k && s.length() - u.size() >= k - u.size())
    {
        cout << k - u.size() << "\n";
    }
    else
    {
        cout << "impossible"
             << "\n";
    }

    return 0;
}
