#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<ll> dp(x + 1, INT_MAX);
    vector<ll> coin(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
 
        for (int c : coin)
        {
            if (i - c >= 0)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    int res = dp[x] == INT_MAX ? -1 : dp[x];
    cout << res << "\n";
}
int main()
{
    solve();
    return 0;
}