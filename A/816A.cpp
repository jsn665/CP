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
    ll l = 0;
    ll il = 0;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v[i] = a;
        if (a > l)
        {
            l = a;
            il = i;
        }
    }

    bool okR = true;
    if (il + 1 < n && v[il + 1] <= l)
    {
        for (int i = il + 1; i < n - 1; i++)
        {
            if ((v[i] < v[i + 1]) || (v[i] == v[i + 1] && v[i] != l))
            {
                okR = false;
                break;
            }
        }
    }
    else
    {
        if (il + 1 < n && v[il + 1] > v[il])
        {
            okR = false;
        }
    }

    bool okL = true;
    for (int i = 1; i < il; i++)
    {
        if ((v[i] < v[i - 1]) || (v[i] == v[i - 1] && v[i] != l))
        {
            okL = false;
            break;
        }
    }

    if (okR && okL)
    {
        cout << "YES"
             << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }
}
