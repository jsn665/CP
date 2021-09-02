#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define pb push_back
#define mk make_pair
using namespace std;

const int mX = 1e5;
int visited[mX];
map<int, vector<int>> graph;

void dfs(int n)
{
    stack<int> s;
    s.push(n);
    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        visited[current] = 1;
        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                s.push(neighbor);
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int src, trg;
        cin >> src >> trg;
        graph[src].pb(trg);
        graph[trg].pb(src);
    }
    vector<int> fn;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            fn.pb(i);
        }
    }
    cout << fn.size() - 1 << "\n";
    for (int i = 1; i < fn.size(); i++)
    {
        cout << fn[0] << " " << fn[i] << "\n";
    }
}

int main()
{
    solve();
}