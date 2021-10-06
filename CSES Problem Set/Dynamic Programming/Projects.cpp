#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
 
int cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
 
void solve()
{
    // dp[i] = max(dp[k] + reward, dp[i - 1]) --> attend and get reward, don't attend
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(a.begin(), a.end(), cmp);
    vector<int> endTimes(n);
    for (int i = 0; i < n; i++)
    {
        endTimes[i] = a[i][1];
    }
    vector<ll> dp(n);
    dp[0] = a[0][2];
    // find the closest end time that is less than the current start time
    for (int i = 1; i < n; i++)
    {
        int start = a[i][0];
        ll reward = a[i][2];
        int k = lower_bound(endTimes.begin(), endTimes.end(), start) - endTimes.begin();
        k--;
        dp[i] = max(dp[i - 1], reward);
        if (k >= 0)
        {
            dp[i] = max(dp[i], dp[k] + a[i][2]);
        }
    }
    cout << dp[n - 1];
}
 
int main()
{
    solve();
    return 0;
}