#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

/*
Idea: The answer is clearly the minimum of buying the food right now or waiting until 20:00 and increasing the cat's hunger and then buying the food using the discount, or in the case where it is already past 20:00, buying the food right now with the 20% discount and the cat's hunger not increasing at all. 
*/
int main()
{
    double h, m;
    double H, D, C, N;

    cin >> h >> m;
    cin >> H >> D >> C >> N;
    double totalDiff = 60 * (20 - h) + (0 - m);
    double buyNow = ceil((H / N)) * C;
    double waitLater = INT_MAX;
    if (totalDiff < 0)
    {
        waitLater = ceil(H / N) * (C - (0.20 * C));
    }
    else
    {

        waitLater = ceil((((totalDiff * D) + H) / N)) * (C - (0.20 * C));
    }
    cout << min(buyNow, waitLater) << "\n";
}
