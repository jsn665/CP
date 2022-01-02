class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
  	multiset<int> se;
  	for(int i = 0; i < asteroids.size(); i++){
		se.insert(asteroids[i]);
	}
    long long m = mass;
	while(se.size()){
		auto it = se.lower_bound(mass);
		if(it != se.begin() && *it != m){
			it--;
		}
		if(*it > m) return false;
		
		m += *it;
        se.erase(it);
	}
	return true;	
    }
};

