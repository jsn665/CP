#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

/*
Idea: The minimum cost is the min(the closest airport whose company is the same as b to the left of a, the closest airport whose company is the same as b to the right of a)... We want 
to reach the same airport company as b since the cost will be 0.
Implementation: A for loop to check for airports to the left of a and a for loop to check for airports to the left of b.
*/
int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector<char> airp(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        airp[i] = s[i - 1];
    }

    if (airp[a] == airp[b])
    {
        cout << 0 << "\n";
        return 0;
    }
    else
    {
        ll diffCompAirp;
        ll lastSameCompAirp;

        for (int i = a; i < airp.size(); i++)
        {
            if (airp[a] != airp[i])
            {
                diffCompAirp = i;
                break;
            }
            else
            {
                lastSameCompAirp = i;
            }
        }
        ll res1 = abs(diffCompAirp - lastSameCompAirp);
        for (int i = a; i >= 0; i--)
        {
            if (airp[a] != airp[i])
            {
                diffCompAirp = i;
                break;
            }
            else
            {
                lastSameCompAirp = i;
            }
        }
        ll res2 = abs(diffCompAirp - lastSameCompAirp);
        cout << min(res1, res2) << "\n";
    }
    return 0;
}
