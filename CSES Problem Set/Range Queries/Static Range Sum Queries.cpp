#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define pi pair<int, ll>
using namespace std;
 
const int MX = (1e5 + 10) * 2;
ll a[MX];
ll b[MX];
void solve()
{
 
        int N, Q;
        cin >> N >> Q;
        for (int i = 1; i <= N; i++)
        {
                cin >> a[i];
                b[i] = b[i - 1] + a[i];
        }
        vector<ll> ans(Q);
        for (int i = 0; i < Q; i++)
        {
                int l, r;
                cin >> l >> r;
                ans[i] = b[r] - b[l - 1];
        }
        for (ll a : ans)
        {
                cout << a << endl;
        }
}
 
int main()
{
        solve();
        return 0;
}