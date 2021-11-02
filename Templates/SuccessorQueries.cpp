# include <bits/stdc++.h> 

using namespace std;



struct SuccessorQueries{
	vector<vector<int>> st;
	// SuccessorArr -> vector v where v[i] represents the successor of the ith node. (0-indexed)
	// maxK -> the maximum number of successors that will be asked
	SuccessorQueries(vector<int> &successorArr, int maxK){
		int n = successorArr.size();
		int logk = log2(maxK);
		st.resize(logk + 1);
		for(int i = 0; i <= logk; i++){
			st[i].resize(n);
		}

		for(int i = 0; i < n; i++){
			st[0][i] = successorArr[i];
		}

		for(int i = 1; i <= logk; i++){
			for(int j = 0; j < n; j++){
				st[i][j] = st[i - 1][st[i - 1][j]];
			}
		}
	}
	// 0-indexed!	
	int query(int x, int k){
		for(int i = 29; i >= 0; i--){
			if(k & (1 << i)){
				x = st[i][x];
			}
		}
		return x;
	}
};
