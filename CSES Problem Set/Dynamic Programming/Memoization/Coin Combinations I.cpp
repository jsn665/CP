#include <bits/stdc++.h>
#define ll long long
using namespace std;

// READ: This program will fail due to stack overflow for large x cases such as 1000000.
// For a working solution, refer to the tabulation (bottom-up) method.
int memo(vector<ll> &dp, vector<int> &coins, int amount){
    if(amount == 0){
        return 1;
    }
    if(dp[amount] != -1){
        return dp[amount];
    }
    int res = 0;
    for(int c : coins){
        if(amount - c >= 0){
            res += memo(dp, coins, amount - c);
        }
    }
    return dp[amount] = res;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<ll> dp(x + 1, -1);
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << memo(dp, coins, x) << "\n";
}
int main()
{
    solve();
    return 0;
}
