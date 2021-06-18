#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

/*
Idea: log2 (n) is how many times you must divide n by 2 until it is 1. Namely, it is the amount of times you must 
shift (>>) bits to the right until n is equal to 1. Therefore, log2 (n) + 1 is the length of the bit string of n. Let k represent the length of the bit string of n.
The length of the bit string of a number n (k) is the same as the closest 2^k such that 2^k is less than or equal to n.
*/

int solve()
{
    ll n;
    cin >> n;
    cout << floor(log2(n) + 1) << "\n";
    return 0;
}

int main()
{
    // ll t;cin >> t;while(t--)
    solve();
    return 0;
}