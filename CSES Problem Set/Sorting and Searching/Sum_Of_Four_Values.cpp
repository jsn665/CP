#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	map<int, pair<int, int>> m;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < n; i++){
	
		for(int j = i + 1; j < n; j++){
			if(m.count(k - a[i] - a[j])){
				cout << i + 1 << " " << j + 1 << " " << m[k - a[i] - a[j]].first + 1 << " " << m[k - a[i] - a[j]].second + 1 << "\n";
				return 0;
			}
		}
		for(int j = 0; j < i; j++){
			m[a[i] + a[j]] = {i, j};
		}
	}
	cout << "IMPOSSIBLE" << "\n";
	return 0;
}

