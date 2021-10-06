#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define pb push_back
#define mk make_pair
using namespace std;
 
const int mX = 1e5;
int path[mX];
int visited[mX];
map<int, vector<int>> graph;
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
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
 
        if (current == n)
        {
            vector<int> moves;
            moves.pb(current);
            while (current != 1)
            {
                moves.pb(path[current]);
                current = path[current];
            }
            cout << moves.size() << "\n";
            for (int i = moves.size() - 1; i >= 0; i--)
            {
                cout << moves[i] << " ";
            }
            return;
        }
        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = 1;
                q.push(neighbor);
                path[neighbor] = current;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
 
int main()
{
    solve();
}