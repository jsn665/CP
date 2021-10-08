# include <bits/stdc++.h>
# define ll long long int
using namespace std;



class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m * n != original.size()){
            return vector<vector<int>>();
        }
        vector<vector<int>> res(m, vector<int> (n, INT_MAX));
        int p = 0;
        for(int i = 0; i < m; i++){
                 for(int j = 0; j < n; j++){
                        
                        res[i][j] = original[p];
                        p++;
                 }
        }
        return res;
    }
};