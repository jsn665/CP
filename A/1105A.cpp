#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v[i] = a;
    }

    ll cost = INT_MAX;
    ll t = 0;
    for (int i = 1; i <= 100; i++)
    {
        ll temp = 0;
        for (int j = 0; j < n; j++)
        {
            ll k = v[j] - i;
            if (k < 0)
            {
                temp += abs(v[j] - (i - 1));
            }
            else if (k > 0)
            {
                temp += abs(v[j] - (i + 1));
            }
        }
        if (temp < cost)
        {
            cost = temp;
            t = i;
        }
    }
    cout << t << " " << cost << "\n";
}