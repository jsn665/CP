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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d == b)
    {
        cout << d << "\n";
    }
    else
    {
        ll origB = b;
        ll origD = d;
        set<ll> s;
        set<ll> s2;
        s.insert(d);
        s2.insert(b);
        d += c;
        b += a;
        s.insert(d);
        s2.insert(b);
        for (int i = 2; i <= 100; i++)
        {

            if (s.count(b))
            {
                cout << b << "\n";
                return 0;
            }
            else if (s2.count(d))
            {
                cout << d << "\n";
                return 0;
            }
            b = origB + (i * a);
            d = origD + (i * c);
            s.insert(d);
            s2.insert(b);
        }
        cout << -1 << "\n";
    }
    return 0;
}

int main()
{
    // ll t;cin >> t;while(t--)
    solve();
    return 0;
}
