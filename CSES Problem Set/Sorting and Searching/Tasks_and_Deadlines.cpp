# include <bits/stdc++.h>
# define pi pair<int,int>
# define ll long long int
using namespace std;

vector<pi> tasks;
void solve(){
	int N;
	cin >> N;
	tasks.resize(N);
	for(int i = 0; i < N; i++){
		cin >> tasks[i].first >> tasks[i].second;
	}

	sort(tasks.begin(), tasks.end());
	ll time = 0;
	ll res = 0;
	for(int i = 0; i < N; i++){
		time += tasks[i].first;
		res += (tasks[i].second - time);
	
	}

	cout << res << endl;


}



int main(){
	solve();

	return 0;
}

