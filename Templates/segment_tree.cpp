# include <bits/stdc++.h>
# define ll long long int
using namespace std;



class SegmentTree{
	
	public:
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
	
		void updateHelper(int root, int rootL, int rootR, int index, int value){
                	if(rootL == rootR) {
                        	tree[root] += value;
                        	return;
                }
                	int half = (rootL + rootR) / 2;
                	int leftChild = 2 * root + 1;
                	int rightChild = 2 * root + 2;
                	if(index >= rootL && index <= half){
                        	updateHelper(leftChild, rootL, half, index, value);
                	}
                	else{
                        	updateHelper(rightChild, half + 1, rootR, index, value);
                	}
                	tree[root] = tree[leftChild] + tree[rightChild];
        		}
	
	
        	void update(int index, int value){
                	updateHelper(0, 0, N - 1, index, value);
			}
};
