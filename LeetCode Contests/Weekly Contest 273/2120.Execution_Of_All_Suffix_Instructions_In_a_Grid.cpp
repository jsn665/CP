class Solution {
public:

	
    

    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
	int m = s.length();
	unordered_map<char, pair<int,int>> dirs;
	dirs['D'] = make_pair(1, 0);
	dirs['U'] = make_pair(-1, 0);
	dirs['L'] = make_pair(0, -1);
	dirs['R'] = make_pair(0, 1);
	vector<int> res(m);
	for(int i = 0; i < m; i++){
		int x = startPos[0], y = startPos[1];
		int steps = 0;
		for(int j = i; j < m; j++){
			int xp = x + dirs[s[j]].first;
			int yp = y + dirs[s[j]].second;
			if(xp < 0 || yp < 0 || xp >= n || yp >= n){
				res[i] = steps;
				break;
			}
			if(j == m - 1){
				res[i] = steps + 1;
				break;
			}
			x = xp;
			y = yp;
			steps++;
		}
	}
	return res;	
    }
};




