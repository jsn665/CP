# include <bits/stdc++.h>

using namespace std;

struct Interval{
	int L, R, index;
};

int cmp(Interval a, Interval b){
	if(a.L == b.L){
		return a.R > b.R;
	}
	return a.L < b.L;
}

void solve(){
	int N;
	cin >> N;
	Interval iv[N];
	for(int i = 0; i < N; i++){
		Interval a;
		cin >> a.L >> a.R;
		a.index = i;
		iv[i] = a;
	}
	sort(iv, iv + N, cmp);
	int maxR = iv[0].R;
	vector<int> containsIt(N, 0);
	for(int i = 1; i < N; i++){
		if(iv[i].R <= maxR){
			containsIt[iv[i].index] = 1;
		}
		maxR = max(maxR, iv[i].R);
	}
	int minR = iv[N - 1].R;
	vector<int> containsOther(N, 0);
	for(int i = N - 2; i >= 0; i--){
		if(iv[i].R >= minR){
			containsOther[iv[i].index] = 1;
		}
		minR = min(minR, iv[i].R);
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

