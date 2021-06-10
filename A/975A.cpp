#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define us unordered_set
#define um unordered_map

using namespace std;
const ll md = 1000000007;

int main()
{
    ll n;
    cin >> n;
    string s;
    us<string> rs;
    while (n--)
    {
        cin >> s;
        vector<int> f(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            f[s[i] - 'a'] += 1;
        }
        string t;
        for (int i = 0; i < 26; i++)
        {
            if (f[i])
            {
                t += (char)97 + i;
            }
        }
        rs.insert(t);
    }
    cout << rs.size() << "\n";
    return 0;
}