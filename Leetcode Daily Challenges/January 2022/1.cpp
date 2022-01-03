class Solution {
public:
     
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int l = n - 2; l >= 1; l--){
            for(int r = l; r <= n - 2; r++){
                for(int i = l; i <= r; i++){
                    int bl = 1, br = 1;
                    if(l - 1 >= 0) bl = nums[l - 1];
                    if(r + 1 < n) br = nums[r + 1];
                    int gain = nums[i] * bl * br;
                    dp[l][r] = max(dp[l][r], dp[i + 1][r] + dp[l][i - 1] + gain);
                }
            }
        }
        return dp[1][n - 2];
    }
};
