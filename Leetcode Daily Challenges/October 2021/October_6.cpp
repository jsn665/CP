# include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int N = nums.size();
        vector<int> res;
        for(int i = 0; i < N; i++){
                int indx = abs(nums[i]) - 1;
                if(nums[indx] < 0){
                    res.push_back(abs(nums[i]));
                }
                nums[indx] = -nums[indx];
        }
        return res;
    }
};

                              
