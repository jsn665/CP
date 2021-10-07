# include <bits/stdc++.h>
# define ll long long int
 
using namespace std;
 
 
 
 
 
 
const int MX = (1e5 + 5) * 2;
ll a[MX];
 
vector<ll> tree(MX * 4);
 
void buildTree(int root, int rootL, int rootR){
	if(rootL == rootR){
		tree[root] = a[rootL];
		return;
	}
 
	int leftChild = 2 * root + 1;
	int rightChild = 2 * root + 2;
	int half = (rootL + rootR) / 2;
	buildTree(leftChild, rootL, half);
	buildTree(rightChild, half + 1, rootR);
	tree[root] = tree[leftChild] + tree[rightChild];
}
 
 
void update(int index, int root, int rootL, int rootR, int value){
	if(rootL == rootR){
		tree[root] = value;
		return;
	}
 
	int leftChild = 2 * root + 1;
	int rightChild = 2 * root + 2;
	int half = (rootL + rootR) / 2;
	if(index >= rootL && index <= half){
		update(index, leftChild, rootL, half, value);
	}
	else{
		update(index, rightChild, half + 1, rootR, value);
	}
 
	tree[root] = tree[leftChild] + tree[rightChild];
	
}
 
ll query(int L, int R, int root, int rootL, int rootR){
	if(rootL >= L && rootR <= R){
		return tree[root];
	}
	else if (rootL > R || rootR < L){
		return 0;
	}
 
	int leftChild = 2 * root + 1;
	int rightChild = 2 * root + 2;
	int half = (rootL + rootR) / 2;
	return query(L, R, leftChild, rootL, half) + query(L, R, rightChild, half + 1, rootR);
}
 
 
 
void solve(){
	int N, Q;
	cin >> N >> Q;
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	buildTree(0, 0, N - 1);
	vector<vector<int>> queries(Q, vector<int>(3));
	for(int i = 0; i < Q; i++){
		int C, L, R;
		cin >> C >> L >> R;
		queries[i][0] = C;
		queries[i][1] = L;
		queries[i][2] = R;
	}
 
	for(int i = 0; i < Q;i++){
		int C = queries[i][0], L = queries[i][1], R = queries[i][2];
		if(C == 1){
			L--;
			update(L, 0, 0, N - 1, R);
		}
		else{
			L--, R--;
			cout << query(L, R, 0, 0, N - 1) << "\n";
		}
	}
}
 
 
int main(){
 
	solve();
	return 0;
}