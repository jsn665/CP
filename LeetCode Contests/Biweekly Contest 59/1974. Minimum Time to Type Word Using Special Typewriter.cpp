// 1974. Minimum Time to Type Word Using Special Typewriter
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minTimeToType(string word)
    {
        char initial = 'a';
        int res = 0;
        for (char c : word){
            res += min((((c - 'a') - (initial - 'a')) + 26) % 26, (((initial - 'a') - (c - 'a')) + 26) % 26) + 1;
            initial = c;
        }
        return res;
    }
};