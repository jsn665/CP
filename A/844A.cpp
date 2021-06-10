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
    string s;
    ll k;
    cin >> s >> k;
    us<char> u;
    for (int i = 0; i < s.length(); i++)
    {
        u.insert(s[i]);
    }
    if (u.size() >= k)
    {
        cout << 0 << "\n";
    }
    else if (u.size() < k && s.length() - u.size() >= k - u.size())
    {
        cout << k - u.size() << "\n";
    }
    else
    {
        cout << "impossible"
             << "\n";
    }

    return 0;
}
