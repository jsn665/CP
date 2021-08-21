// 1975. Maximum Matrix Sum
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long maxMatrixSum(vector<vector<int>> &a){
        int n = a.size();
        int negativeCount = 0;
        int minimum = INFINITY;
        long long res = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                negativeCount += (a[i][j] < 0);
                minimum = min(minimum, abs(a[i][j]));
                res += abs(a[i][j]);
            }
        }
        if ((negativeCount & 1) == 0){
            return res;
        }
        else{
            return res - (minimum * 2);
        }
    }
};