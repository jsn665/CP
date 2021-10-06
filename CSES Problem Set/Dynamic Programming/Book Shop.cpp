#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
using namespace std;
 
const int mX = 1e3 + 5;
const int mX2 = 1e5 + 5;
int price[mX];
int pages[mX];
int dp[mX][mX2];
void solve()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> pages[i];
    }
    //dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price[i]] + pages[i])
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (i - 1 >= 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            if (i - 1 >= 0 && j - price[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i]] + pages[i]);
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