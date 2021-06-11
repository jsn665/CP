#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long

using namespace std;
const ll md = 1000000007;

int main()
{

    ll n, k, s, sa, us;
    cin >> n >> k;
    s = ceil((double)n / 2);
    map<ll, ll> m;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        m[a] += 1;
    }
    sa = 0;
    us = 0;
    for (pair<ll, ll> p : m)
    {
        sa += (p.second / 2) * 2;
        us += p.second % 2;
        s -= p.second / 2;
    }
    if (us >= s)
    {
        sa += s;
    }
    else
    {
        sa += us;
    }
    cout << sa << "\n";

    return 0;
}