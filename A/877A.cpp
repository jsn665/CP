#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

int main()
{
    string names[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    string s;
    cin >> s;
    int friendOccurrence = 0;
    for (string name : names)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (name == s.substr(i, name.length()))
            {
                friendOccurrence++;
                if (friendOccurrence > 1)
                {
                    cout << "NO"
                         << "\n";
                    return 0;
                }
            }
        }
    }
    if (friendOccurrence == 1)
    {
        cout << "YES"
             << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }
    return 0;
}