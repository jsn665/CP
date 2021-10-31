#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}	

	long long prefixSum = 0;
	map<long long, int> cnt;
	cnt[0] = 1;
	int res = 0;
	for(int i = 1; i <= n; i++){
		prefixSum += a[i];
		res += cnt[prefixSum - x];
		cnt[prefixSum]++;
		
	}
	cout << res << "\n";
	return 0;
}

