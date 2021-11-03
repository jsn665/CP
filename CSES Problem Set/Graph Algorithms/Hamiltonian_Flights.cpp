# include <bits/stdc++.h>

using namespace std;


long long dp[25][(1 << 20)];
int n, m;
const int MOD = 1e9 + 7;
vector<vector<int>> g;

long long dfs(int u, int mask){

	if(__builtin_popcount(mask) == n){
		return 1;
	}
	if(u == n){
		return 0;
	}
	if(dp[u][mask] != -1){
		return dp[u][mask];
	}
	long long res = 0;
	for(auto &v : g[u]){
		if((mask & (1 << v)) == 0){
			res += dfs(v, mask | (1 << v));
			res %= MOD;
		}
	}
	return dp[u][mask] = res;
}

int main(){

	cin >> n >> m;
	g.resize(n + 1);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(1, 2) << "\n";




	return 0;
}

