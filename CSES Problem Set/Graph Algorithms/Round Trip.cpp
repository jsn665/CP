#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
using namespace std;
const int mX = 1e5 + 9;
int parent[mX];
int color[mX];
int s, e;
map<int, vector<int>> g;
 
int dfs(int cv)
{
 
    color[cv] = 1;
    for (int neighbor : g[cv])
    {
        if (parent[cv] == neighbor)
        {
            continue;
        }
        if (color[neighbor] == 1)
        {
            s = neighbor;
            e = cv;
            return true;
        }
        if (color[neighbor] == 0)
        {
            parent[neighbor] = cv;
 
            if (dfs(neighbor))
            {
                return true;
            }
        }
    }
    color[cv] = 2;
    return false;
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
        if (color[0] == 0 && dfs(i))
        {
            int temp = e;
            vector<int> path;
            path.pb(e);
            while (temp != s)
            {
                path.pb(parent[temp]);
                temp = parent[temp];
            }
            path.pb(e);
            cout << path.size() << "\n";
            for (int i = path.size() - 1; i >= 0; i--)
            {
                cout << path[i] << " ";
            }
            exit(0);
        }
    }
    cout << "IMPOSSIBLE";
}
 
int main()
{
    solve();
    return 0;
}