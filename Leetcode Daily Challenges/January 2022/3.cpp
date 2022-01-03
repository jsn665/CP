class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n + 1), outdeg(n + 1);
        for(auto &e : trust){
            int u = e[0], v = e[1];
            indeg[v]++;
            outdeg[u]++;
        }
        for(int i = 1; i <= n; i++){
            if(indeg[i] == n - 1 && outdeg[i] == 0){
                return i;
            }
        }
        return -1;
    }
};
