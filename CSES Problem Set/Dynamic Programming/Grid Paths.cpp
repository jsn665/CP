#include <bits/stdc++.h>
#define ll long long
using namespace std;
// constraints: 1≤ n ≤ 1000
// O(N^2) time complexity due to having to traverse the entire N * N grid.
// O(N^2) space complexity. 2 matrices --dp, grid-- of size N * N are used.
void solve()
{
    int n;
    cin >> n;
    int mod = 1e9 + 7;
    vector<vector<ll>> dp(n, vector<ll>(n));
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.')
            {
                if (i - 1 >= 0)
                {
                    (dp[i][j] += dp[i - 1][j]) %= mod;
                }
                if (j - 1 >= 0)
                {
                    (dp[i][j] += dp[i][j - 1]) %= mod;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
}
 
int main()
{
    solve();
    return 0;
}