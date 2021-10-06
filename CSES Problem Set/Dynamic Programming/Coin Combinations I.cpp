#include <bits/stdc++.h>
#define ll long long
using namespace std;
// dp[x] = number of ways to make the sum `x`
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<ll> dp(x + 1, 0);
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int c : coins)
        {
            if (i - c >= 0)
            {
                dp[i] += (dp[i - c]);
                dp[i] %= 1000000007;
            }
        }
    }
    cout << dp[x] << "\n";
}
int main()
{
    solve();
    return 0;
}