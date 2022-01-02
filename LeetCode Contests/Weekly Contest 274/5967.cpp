class Solution {
public:
    bool checkString(string s) {
  	map<char, int> cnt;
  	for(int i = 0; i < s.length(); i++){
		cnt[s[i]]++;
	}

	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'b' && cnt['a'] > 0){
			return false;
		}
		cnt[s[i]]--;
	}
	return true;	
    }
};


