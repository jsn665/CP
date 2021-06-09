#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define fr0(i, n) for (; i < n; i++)
#define fr1(i, n) for (; i <= n; i++)

using namespace std;

const ll md = 1000000007;

int main()
{
    ll n, a, b, c, s, cost;
    cin >> n >> a >> b >> c;
    s = min(a, b);
    s = min(s, c);
    cost = 0;
    n--;
    if (n > 0)
    {
        if (s == c)
        {
            cost += min(a, b);
            n--;
            cost += c * n;
        }
        else if (s == a)
        {
            cost += a * n;
        }
        else if (s == b)
        {
            cost += b * n;
        }
    }
    cout << cost << "\n";
    return 0;
}