#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
1 ≤ n ≤ 1000
1 ≤ x ≤ 105
1 ≤ hi ,si ≤ 1000
*/
// 0/1 knapsack problem
// O(N^2) time complexity due to having to traverse the entire N * X grid.
// O(N^2) space complexity. dp matrix of size N * X used.
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> prices(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> prices[i];
    }
    vector<int> pages(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> pages[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - prices[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i]] + pages[i]);
            }
        }
    }
    cout << dp[n][x] << "\n";
}

int main()
{
    solve();
    return 0;
}
