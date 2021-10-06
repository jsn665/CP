#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<ll> dp(x + 1);
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j - coins[i] >= 0)
            {
                (dp[j] += dp[j - coins[i]]) %= 1000000007;
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