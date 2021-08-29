#include <bits/stdc++.h>
#define ll long long
using namespace std;
// READ: This program will fail due to stack overflow for large x cases such as 1000000.
// For a working solution, refer to the Tabulation (bottom-up) method.
int memo(vector<ll> &dp, vector<int> &coins, int target)
{
    if (target < 0)
    {
        return -1;
    }
    if (target == 0)
    {
        return 0;
    }
    if (dp[target] != INT_MAX)
    {
        return dp[target];
    }
    int res = INT_MAX;
    for (int c : coins)
    {
        int use = memo(dp, coins, target - c);
        if (use != -1)
        {
            res = min(res, use + 1);
        }
    }
    dp[target] = res == INT_MAX ? -1 : res;
    return dp[target];
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<ll> dp(x + 1, INT_MAX);
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << memo(dp, coins, x) << "\n";
}
int main()
{
    solve();
    return 0;
}
