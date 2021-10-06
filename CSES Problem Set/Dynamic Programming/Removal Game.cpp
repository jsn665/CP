#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
 
void solve()
{
    // dp[l][r] = max(rewardL - dp[l + 1][r], rewardR - dp[l][r - 1])
    int n;
    cin >> n;
    vector<int> a(n + 1);
    ll t = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t += a[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for (int l = n; l >= 1; l--)
    {
        for (int r = l; r <= n; r++)
        {
            if (l == r)
            {
                dp[l][r] = a[l];
            }
            else
            {
                dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
            }
        }
    }
    cout << (t + dp[1][n]) / 2;
}
 
int main()
{
    solve();
    return 0;
}