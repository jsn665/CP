# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
  	set<int> perfectSquares;
	for(int i = 1; i * i <= n; i++){
		perfectSquares.emplace(i * i);
	}
	vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
	for(int i = 1; i <= n; i++){
		for(auto ps: perfectSquares){
            if(i >= ps)
			    dp[i] = min(dp[i], dp[i - ps] + 1);
		}
	}
	return dp[n];	
    }
};

