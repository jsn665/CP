class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
  	    int n = bank.size();
	    int m = bank[0].size();
	    vector<int> cnt(n);
      	    for(int i = 0; i < n; i++){
		    int curr = 0;
	    	for(int j = 0; j < m; j++){
			curr += (bank[i][j] == '1');
		}
		cnt[i] = curr;
	    }

	    int res = 0;
	 for(int i = 0; i < n; i++){
         	if(cnt[i] > 0){
         		for(int j = i + 1; j < n; j++){
            			if(cnt[j] > 0){
                			res += (cnt[i] * cnt[j]);
                			break;
            			}   
         		}
         	}
	 }
	return res;	 
    }
};

