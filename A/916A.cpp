#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

/*
Idea: Subtract x from the time until there is a 7 in the hours or minutes.
Implementation: Convert the hours and minutes into just minutes by using the formula --> h * 60 + min. Enter an infinite while loop since a solution is guaranteed and search
for the solution. Convert the minutes back into H to check for a 7 using the fomrmula --> total minutes / 60. Do the same for the minutes using the formula --> total minutes % 60.
Substract x minutes from the total minutes by using the formula --> (totalMinutes - x + 1440) % 1440... To avoid any negative values.
*/
int main()
{
    int x, h, m;
    cin >> x >> h >> m;
    int timeInMin = h * 60 + m;

    int res = 0;
    while (true)
    {
        int minToH = timeInMin / 60;
        int minToM = timeInMin % 60;
        if (minToH % 10 == 7 || minToM % 10 == 7)
        {
            cout << res << "\n";
            return 0;
        }
        res++;
        timeInMin = (timeInMin - x + 1440) % 1440;
    }
    return 0;
}
