#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll dp[1000001];
int helper(ll target)
{
 
    if (target == 0)
        return 1;
 
    if (target < 0)
        return 0;
    if (dp[target] != -1)
    {
        return dp[target];
    }
    ll res = 0;
    for (int c = 1; c <= 6; c++)
    {
        res += (helper(target - c));
    }
    return dp[target] = res % 1000000007;
}
 
void solve()
{
    for (int i = 0; i < 1000001; i++)
    {
        dp[i] = -1;
    }
    ll n;
    cin >> n;
    cout << helper(n) << "\n";
}
 
int main()
{
    solve();
    return 0;
}