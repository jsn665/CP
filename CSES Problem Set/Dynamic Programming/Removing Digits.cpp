#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    vector<ll> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (char c : to_string(i))
        {
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }
    cout << dp[n] << "\n";
}
 
int main()
{
    solve();
    return 0;
}