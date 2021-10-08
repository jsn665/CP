# include <bits/stdc++.h>

using namespace std;


class SparseTable{
	public:
        vector<vector<int>> st;
        vector<int> logs;
        SparseTable(vector<int> &nums){
                int N = nums.size();
                logs.resize(N + 1);
                for(int i = 2; i <= N; i++){
                        logs[i] = log2(i);
                }
                int P = logs[N];
                st.resize(P + 1, vector<int> (N));
                for(int i = 0; i < N; i++){
                        st[0][i] = nums[i];
                }

                for(int i = 1; i <= P; i++){
                        for(int j = 0; j + (1 << i) - 1 < N; j++){
                                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                        }
                }

        }
        // 0 indexed!!!
        int query(int L, int R){
                int K = logs[R - L + 1];
                return max(st[K][L], st[K][R - (1 << K) + 1]);
        }
};

