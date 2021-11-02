# include <bits/stdc++.h> 

using namespace std;



struct SuccessorQueries{
	vector<vector<int>> st;
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
	
	int query(int x, int k){
		for(int i = 29; i >= 0; i--){
			if(k & (1 << i)){
				x = st[i][x];
			}
		}
		return x;
	}
};

int main(){
	int n, q;
	cin >> n >> q;
	vector<int> successorArr(n);
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		a--;
		successorArr[i] = a;
	}
	vector<int> qAns(q);
	SuccessorQueries sq(successorArr, 1e9);
	for(int i = 0; i < q; i++){
		int x, k;
		cin >> x >> k;
		qAns[i] = sq.query(x - 1, k) + 1;
	}

	for(int &res : qAns){
		cout << res << "\n";
	}

	return 0;
}


