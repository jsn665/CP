#include <bits/stdc++.h>

using namespace std;

int main(){
	int x, n;
	cin >> x >> n;
	set<int> s;
	s.insert(0);
	s.insert(x);
	multiset<int> lengths;
	lengths.insert(x);
	for(int i = 0; i < n; i++){
		int tl;
		cin >> tl;
		s.insert(tl);
		auto it = s.find(tl);
		int previousVal = *prev(it);
		int nextVal = *next(it);
		lengths.erase(lengths.find(nextVal - previousVal));
		lengths.insert(nextVal - tl);
		lengths.insert(tl - previousVal);
		cout << *lengths.rbegin() << " ";
	}
	cout << "\n";

	return 0;
}

