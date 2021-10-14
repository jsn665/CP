# include <bits/stdc++.h>
# define ll long long int
# define pi pair<int,int>
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
int cmp(pair<pi, int> a, pair<pi, int> b){
	if(a.first.first == b.first.first){
		return a.first.second > b.first.second;
	}
	return a.first.first < b.first.first;
}

int compressIndex(vector<int> &sorted, int value){
	return lower_bound(sorted.begin(), sorted.end(), value) - sorted.begin();
}


void solve(){
	int N;
	cin >> N;
	vector<pair<pi, int>> intervals(N);
	vector<int> ends(N);
	for(int i = 0; i < N; i++){
		int L, R;
		cin >> L >> R;
		intervals[i].first.first = L;
		intervals[i].first.second = R;
		intervals[i].second = i;
		ends[i] = R;
	}

	sort(intervals.begin(), intervals.end(), cmp);
	sort(ends.begin(), ends.end());
	vector<int> cnt(N);
	SegmentTree seg(cnt);
	vector<int> containsIt(N);
	for(int i = 0; i < N; i++){
		 int L = intervals[i].first.first;
		 int R = intervals[i].first.second;
		 int indx = intervals[i].second;
		 int compressedVal = compressIndex(ends, R);
		 containsIt[indx] += seg.query(compressedVal, N - 1);
		 seg.update(compressedVal, 1);
	}
	vector<int> containsOther(N);
	vector<int> cnt2(N);
	SegmentTree seg2(cnt2);
	for(int i = N - 1; i >= 0; i--){
		int L = intervals[i].first.first;
		int R = intervals[i].first.second;
		int indx = intervals[i].second;
		int compressedVal = compressIndex(ends, R);
		containsOther[indx] += seg2.query(0, compressedVal);
	        seg2.update(compressedVal, 1);	
	}

	for(int i = 0; i < N; i++){
		cout << containsOther[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < N; i++){
		cout << containsIt[i] << " ";
	}
	cout << endl;

}


int main(){
	solve();
	return 0;
}

