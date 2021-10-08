# include <bits/stdc++.h>
# define ll long long int
# define pb push_back
using namespace std;



class Solution {
public:
   static int cmp(string &a, string &b){
        return a.length() < b.length();
   }

    int numOfPairs(vector<string>& nums, string target) {
              sort(nums.begin(), nums.end(), cmp);
              map<int, vector<string>> m;
              for(auto str : nums){
                 m[str.length()].pb(str);
              }
              int res = 0;
              for(auto str : nums){
                if(str.length() > target.length()) break;
                int goal = target.length() - str.length();
                bool self_considered = false;
                for(auto cand : m[goal]){
                        if(str + cand == target){
                                
                                res++;
                                if(!self_considered && str == cand){
                                    res--;
                                    self_considered = true;
                                }
                            
                        }
                }
              }
              return res;
    }
};