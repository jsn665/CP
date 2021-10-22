# include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
map<int, vector<int>> g;
vector<long long int> dp;
int n, m;
long long int go(int u){
	
	if(dp[u] != -1){
		return dp[u];
	}
	if(u == n){
		return 1;
	}
	long long int res = 0;
	for(auto v: g[u]){
		res = (res % MOD) + (go(v) % MOD);
	}
	return dp[u] = res % MOD;
}

int main(){
	
	cin >> n >> m;
	dp.resize(n + 1);
	for(int i = 1; i <= n; i++){
		dp[i] = -1;
	}
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}

	cout << go(1) << "\n";

	return 0;
}

