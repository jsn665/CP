#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

/*
You want to solve for x for the following inequality : (M * x) - K >= L
All but x are given and x is equal to the minimum number of coins that each friend can give.
You can rewrite the above equation into the following : x >= (K + L) / M
Once you get x, remember that each friend must gift a different coin; therefore,
if x * M > N, it is not possible for each friend to gift a different coin since 
N is the number of different coins and in that case the friends will be giving repeated coins.
*/

int solve()
{
    ll N, M, K, L;
    cin >> N >> M >> K >> L;

    ll x = ceil((double)(K + L) / M);
    if (x * M > N)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << x << "\n";
    }

    return 0;
}

int main()
{
    // ll t;cin >> t;while(t--)
    solve();
    return 0;
}