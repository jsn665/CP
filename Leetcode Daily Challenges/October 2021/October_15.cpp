class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<vector<int>> dp(N + 2, vector<int> (2, 0));
        for(int i = N - 1; i >= 0; i--){
            int value = prices[i];
            dp[i][0] = max(dp[i + 1][1] - value, dp[i + 1][0]);
            dp[i][1] = max(dp[i + 2][0] + value, dp[i + 1][1]);
        }
        return dp[0][0];
    }
};

