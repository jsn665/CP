#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
using namespace std;
const int mX = 1e5 + 9;
vector<int> colors(mX, -1);
map<int, vector<int>> g;

bool dfs(int cv, int color)
{
    colors[cv] = color;
    for (int neighbor : g[cv])
    {
        if (colors[neighbor] == -1 && !dfs(neighbor, color ^ 1))
        {
            return false;
        }
        if (colors[neighbor] == colors[cv])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int src, trg;
        cin >> src >> trg;
        g[src].pb(trg);
        g[trg].pb(src);
    }
    for (int i = 1; i <= n; i++)
    {
        if (colors[i] == -1 && !dfs(i, 0))
        {
            cout << "IMPOSSIBLE"
                 << "\n";
            exit(0);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << colors[i] + 1 << " ";
    }
}

int main()
{
    solve();
}