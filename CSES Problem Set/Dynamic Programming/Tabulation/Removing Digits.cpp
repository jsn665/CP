#include <bits/stdc++.h>
#define ll long long
using namespace std;
// constraints: 1 ≤ n ≤ 1000000
// We know that the number of digits in n will not exceed 7, so time complexity is O(N * number of digits in the current iteration of i)
// O(N) space complexity
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
