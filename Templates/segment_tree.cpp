# include <bits/stdc++.h>
# define ll long long int
using namespace std;



class SegmentTree{
	
	public:
		// 0[0, 7] -> 1[0, 3] -> 3[0, 1] -> 7 [0, 0]
		// 0[0, 7] -> 2[4, 7] -> 6[6, 7] -> 14 [7, 7]
		//
		// (1, 4, 0, 0, 7) -> (1, 4, 1, ) 
		vector<ll> tree;
		int N;
		SegmentTree(vector<int> &nums){
			N = nums.size();
			tree.resize(N * 4);
			buildTree(0, 0, N - 1, nums);
		}

		void buildTree(int root, int rootL, int rootR, vector<int> &nums){
			if(rootL == rootR){
				tree[root] = nums[rootL];
				return;
			}
			int leftChild = 2 * root + 1;
			int rightChild = 2 * root + 2;
			int half = (rootL + rootR) / 2;
			buildTree(leftChild, rootL, half, nums);
			buildTree(rightChild, half + 1, rootR, nums);
			tree[root] = tree[leftChild] + tree[rightChild];
		}

		ll queryHelper(int L, int R, int root, int rootL, int rootR){
			if(rootL >= L && rootR <= R){
				return tree[root];
			}
			else if (rootL > R || rootR < L){
				return 0;
			}
			int leftChild = 2 * root + 1;
			int rightChild = 2 * root + 2;
			int half = (rootL + rootR) / 2;
			return queryHelper(L, R, leftChild, rootL, half) + queryHelper(L, R, rightChild, half + 1, rootR);
		}
		ll query(int L, int R){
			return queryHelper(L, R, 0, 0, N - 1);
		}

};


int main(){
	int N, Q;
	cin >> N >> Q;
	vector<int> a(N);
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	SegmentTree seg(a);
	for(int i = 0; i < Q; i++){
		int L, R;
		cin >> L >> R;
		L--, R--;
		cout << seg.query(L, R) << "\n";
	}

	return 0;
}
