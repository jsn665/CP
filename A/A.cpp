#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long

using namespace std;
const ll md = 1000000007;

// ll lpow(ll a, ll b){ll res = 1;while (b){if ((b & 1) == 1)res *= a;b >>= 1;a *= a;}return res;}
// ll gcd(ll a, ll b){while (b){a %= b;swap(a, b);}return a;}

int main()
{
    string s;
    cin >> s;
    bool ok = false;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] == 'B' && s[i - 1] == 'A' && s[i + 1] == 'C') || s[i] == 'B' && (s[i - 1] == 'C' && s[i + 1] == 'A'))
            ok = true;
        else if ((s[i] == 'A' && s[i - 1] == 'B' && s[i + 1] == 'C') || (s[i] == 'A' && s[i - 1] == 'C' && s[i + 1] == 'B'))
            ok = true;
        else if ((s[i] == 'C' && s[i - 1] == 'A' && s[i + 1] == 'B') || (s[i] == 'C' && s[i - 1] == 'B' && s[i + 1] == 'A'))
            ok = true;
    }
    if (ok)
        cout << "Yes"
             << "\n";
    else
        cout << "No"
             << "\n";
    return 0;
}
