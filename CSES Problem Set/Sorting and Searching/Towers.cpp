# include <bits/stdc++.h>
# define pb push_back

using namespace std;

// Patience sort
void solve(){
	int N;
	cin >> N;
	vector<int> patience;
	int a;
	cin >> a;
	patience.pb(a);
	for(int i = 1; i < N; i++){
		cin >> a;
		int K = upper_bound(patience.begin(), patience.end(), a) - patience.begin();
		if(K == (int)patience.size()){
			patience.pb(0);
		}
		patience[K] = a;
	}
	cout << patience.size() << endl;
}


int main(){
	
	solve();

	return 0;
}

