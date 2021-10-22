# include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
int main(){

	int n, m;
	cin >> n >> m;
	map<int,int> indegree;
	map<int,vector<int>> g;
	map<int, vector<int>> dependent;
	queue<int> q;
	vector<long long int> dp(n + 1);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		dependent[v].push_back(u);
		indegree[v]++;
	}	

	for(int v = 1; v <= n; v++){
		if(indegree[v] == 0){
			q.emplace(v);
		}
	}

	dp[1] = 1;
	
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto v : g[u]){
			indegree[v]--;
			if(indegree[v] == 0){
				q.emplace(v);
			}
		}
		for(auto prev : dependent[u]){
			dp[u] = ((dp[u] % MOD) + (dp[prev] % MOD)) % MOD;
		}
	}

	cout << dp[n] << "\n";
	return 0;
}

