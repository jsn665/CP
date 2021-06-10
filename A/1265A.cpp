#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define unordered_set us
#define unordered_map um

using namespace std;
const ll md = 1000000007;

int main()
{
    ll t;
    string s;
    cin >> t;
    char c[3] = {'a', 'b', 'c'};
    while (t--)
    {
        cin >> s;
        bool ok = true;
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i - 1] == s[i] || s[i + 1] == s[i]) && s[i] != '?')
            {
                ok = false;
                break;
            }
            if (s[i] == '?')
            {
                for (char ch : c)
                {
                    if (ch != s[i - 1] && ch != s[i + 1])
                    {
                        s[i] = ch;
                    }
                }
            }
        }
        if (ok)
        {
            cout << s << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}