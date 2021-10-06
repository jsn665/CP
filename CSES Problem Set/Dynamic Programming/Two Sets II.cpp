#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    int s = ((n * (n + 1)) / 2);
    if (s % 2 > 0)
    {
        cout << 0 << "\n";
        return;
    }
    s /= 2;
    vector<vector<ll>> dp(n, vector<ll>(s + 1));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = dp[i - 1][j]; // don't take
            if (j - i >= 0)
            {
                dp[i][j] += dp[i - 1][j - i]; // take
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n - 1][s] << "\n";
}
 
int main()
{
    solve();
}