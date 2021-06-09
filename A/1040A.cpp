#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long

using namespace std;

int main()
{
    ll t, a, b, c;
    cin >> t >> a >> b;
    vector<int> v(t);
    for (int i = 0; i < t; i++)
    {
        cin >> c;
        v[i] = c;
    }
    unordered_map<ll, ll> m;
    m.emplace(mk(0, a));
    m.emplace(mk(1, b));
    ll d = 0;
    ll e = v.size() - 1;
    ll cost = 0;
    while (d <= e)
    {
        if ((v[d] != v[e]) || (v[d] == 2 && v[e] == 2))
        {
            if (v[d] == 2 && v[e] == 2)
            {
                ll lp = min(a, b);
                if (e == d)
                {
                    cost += lp;
                }
                else
                {
                    cost += lp * 2;
                }
            }
            else if ((v[d] == 1 && v[e] == 2) || (v[d] == 2 && v[e] == 1))
            {
                cost += m[1];
            }
            else if ((v[d] == 0 && v[e] == 2) || (v[d] == 2 && v[e] == 0))
            {
                cost += m[0];
            }
            else
            {
                cout << -1 << "\n";
                return 0;
            }
        }
        d++;
        e--;
    }
    cout << cost << "\n";
    return 0;
}
