#include <bits/stdc++.h>

using namespace std;

/*
 * Time : O(N)
 * Space: O(N)
 * Approach: Monotonic Stack
 *
 * Intuition: Monotonic stack allows us to solve problems where a single element can satisfy a constraint for a sequence.
 * i.e : In the stack, we maintained temperatures that were decreasing in order, so when we found a larger temperature than the one on top of the stack,
 * we knew that temperature would be greater than at least one other temperature in the stack, thus satisfying a contrainst for at least a sequence of size 1.
 * */
class Solution{


	public:
		vector<int> dailyTemperatures(vector<int> &t){
			int n = t.size();
			stack<int> s;
			vector<int> res(n);
			for(int i = 0; i < n; i++){
				while(!s.empty() && t[s.top()] < t[i]){
					res[s.top()] = i - s.top();
					s.pop();
				}
				s.push(i);
			}
			while(!s.empty()){
				res[s.top()] = 0;
				s.pop();
			}

			return res;
			
		}
};

