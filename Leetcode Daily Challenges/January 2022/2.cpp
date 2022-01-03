class Solution {
public:
    
    int formula(int n){
        return n * (n - 1) / 2;
    }
    
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<int> cnt(61);
        int res = 0;
        for(int i = 0; i < n; i++){
            int t = 60 - (time[i] % 60);
            res += cnt[t];
            cnt[time[i] % 60]++;
        }
        return res + formula(cnt[0]);
        
} 
};
