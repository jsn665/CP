#include <bits/stdc++.h>
const int MX = (1e5 + 5) * 2;
int a[MX];
 
using namespace std;
 
 
 
void solve(){
int N, Q;
cin >> N >> Q;
int P = (int) log2(N);
vector<vector<int>> sparse_table(P + 1, vector<int> (N));
for(int i = 0; i < N; i++){
	cin >> a[i];
	sparse_table[0][i] = a[i];
}
 
for(int i = 1; i <= P; i++){
	for(int j = 0; j + (1 << i) - 1 < N; j++){
		sparse_table[i][j] = min(sparse_table[i - 1][j], 
				sparse_table[i - 1][j + (1 << (i - 1))]);
	}
}
vector<pair<int, int>> queries(Q);
for(int i = 0; i < Q; i++){
	int L, R;
	cin >> L >> R;
	L--;
	R--;
	queries[i].first = L;
	queries[i].second = R;
}
 
for(auto q: queries){
	int L = q.first, R = q.second;
	int len = R - L + 1;
	int K = (int) log2(len);
	cout << min(sparse_table[K][L], sparse_table[K][R - (1 << K) + 1]) << "\n";
}
 
 
 
}
 
 
int main(){
solve();
 
return 0;
}