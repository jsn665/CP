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
    ll n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    a -= 1;
    x -= 1;
    b -= 1;
    y -= 1;
    bool ok = false;
    while (b != y && a != x)
    {
        a = (a + 1 + n) % n;
        b = (b - 1 + n) % n;
        if (a == b)
        {
            ok = true;
            break;
        }
    }
    if (ok == true)
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