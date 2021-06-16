#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

/*
Idea: Make sure all of the 3 constraints are checked off.
1 - The order must be in the form abc (sorted)
2 - There must be at least one a, b, and c (use map)
3 - The occurrence of c must be equal to the occurrence of a or b
*/
int solve()
{
    string s;
    cin >> s;

    if (!is_sorted(s.begin(), s.end()))
    {
        cout << "NO"
             << "\n";
        return 0;
    }

    map<char, int> occ;
    for (int i = 0; i < s.length(); i++)
    {
        occ[s[i]]++;
    }
    if ((!occ.count('a') || !occ.count('b') || !occ.count('c')) || (occ['c'] != occ['a']) && occ['c'] != occ['b'])
    {
        cout << "NO"
             << "\n";
        return 0;
    }
    cout << "YES"
         << "\n";
    return 0;
}

int main()
{
    solve();
    return 0;
}