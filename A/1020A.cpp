#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

/*
Idea: implementation, just get the differences between travelling and sum them
*/
int main()
{
    ll n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    while (k--)
    {
        ll ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;
        ll res = 0;
        if (ta == tb) // if the target tower is the same as starting tower
        {
            res += abs(fb - fa);
        }
        else // target tower is not the same as starting tower
        {
            if (fa >= a && fa <= b) // if you are already on a floor that can cross to an adjacent tower
            {
                res += abs(tb - ta) + abs(fb - fa);
            }
            else // you need to reach the floor that can cross to an adjacent tower
            {
                ll f;
                ll t;
                if (b < fa) // if you are in a floor higher than b
                {
                    f = fa - b; // distance from b
                    t = b;      // new floor you are in
                }
                else // if you are in a floor lower than b
                {
                    t = a;      // new floor you are in
                    f = a - fa; // distance from a
                }
                res += (f + abs(tb - ta)) + abs(fb - t); // distance to get to a or b + distance between towers tb, ta + distance between target floor and the current floor you are in
            }
        }
        cout << res << "\n";
    }
}