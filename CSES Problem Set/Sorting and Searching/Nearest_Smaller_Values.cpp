# include <bits/stdc++.h>

using namespace std;


int main(){
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	stack<int> s;
	vector<int> res(n);
	for(int i = n - 1; i >= 0; i--){
	
		while(!s.empty() && a[s.top()] > a[i]){
			res[s.top()] = i + 1;
			s.pop();
		}
		s.push(i);
	}
	for(int i = 0; i < n; i++){
		cout << res[i] << " ";
	}
	cout << "\n";
	return 0;
}

