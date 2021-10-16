# include <bits/stdc++.h> 
# define ll long long int
using namespace std;


bool check(ll guess, vector<int> &nums, ll T){
	ll res = 0;
	for(int i = 0; i <(int) nums.size(); i++){
	
		res += (guess / nums[i]);
		if(res >= T) return true;
	}
	return res >= T;
}


void solve(){
	ll N, T;
	cin >> N >> T;
	vector<int> nums(N);
	for(int i = 0; i < N; i++){
		cin >> nums[i];
	}
	ll L = 1, R = 1e18;
	ll res = R;
	while(L <= R){
		ll guess = (L + R) / 2;
		if(check(guess, nums, T)){
			R = guess - 1;
			res = guess;
		}
		else{
			L = guess + 1;
		}
	}
	cout << res << endl;
}



int main(){


	solve();
	return 0;
}

