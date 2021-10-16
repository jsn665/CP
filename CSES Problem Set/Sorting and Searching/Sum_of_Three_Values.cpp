# include <bits/stdc++.h>
# define ll long long int
# define pi pair<long,int>
# define mp make_pair
# define pb push_back
using namespace std;

vector<pi> a;
int N, X;

pi twoSumSorted(int i, int j, ll sum){
	while(i < j){
		ll currSum = sum + a[i].first + a[j].first;
		if(currSum == X){
			return mp(a[i].second, a[j].second);
		}
		else if (currSum > X){
			j--;
		}
		else{
			i++;
		}
	}
	return mp(-1, -1);
}

void solve(){
	cin >> N >> X;
	a.resize(N + 1);
	for(int i = 1;i <= N; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<int> res;
	for(int i = 1; i <= N; i++){
		pi find = twoSumSorted(i + 1, N, a[i].first);
		if(find.first != -1){
			res.pb(a[i].second);
			res.pb(find.first);
			res.pb(find.second);
			break;
		}
	
	}
	if((int) res.size() == 3){
		for(int i = 0; i < 3; i++){
			cout << res[i] << " ";
		
		}
		cout << endl;
	}
	else{
		cout << "IMPOSSIBLE" << endl;
	}
}

int main(){
	solve();

	return 0;
}

