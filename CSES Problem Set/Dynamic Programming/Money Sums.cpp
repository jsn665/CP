#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
using namespace std;
 
const int mX = 500505;
const int mxN = 1e2 + 5;
int a[mxN];
bool dp[mxN][mX];
void solve()
{
    int n;
    cin >> n;
    //dp[i][j] = dp[i - 1][j - a[i]] | dp[i - 1][j]
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 500500; j++)
        {
            dp[i][j] |= dp[i - 1][j];
            if (j - a[i] >= 0)
            {
                dp[i][j] |= dp[i - 1][j - a[i]];
            }
        }
    }
 
    vector<int> res;
    for (int i = 1; i <= 500500; i++)
    {
        if (dp[n][i])
        {
            res.pb(i);
        }
    }
    cout << res.size() << "\n";
    for (int can : res)
    {
        cout << can << " ";
    }
}
 
int main()
{
    solve();
    return 0;
}