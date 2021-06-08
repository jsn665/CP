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
    ll l, r;
    cin >> l >> r;
    if (l == r){
        cout << l << "\n";
    }
    else{
        cout << 2 << "\n";
    }
    return 0;
}