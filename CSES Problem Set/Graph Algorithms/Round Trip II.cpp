#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define pi pair<int, ll>
#define MAX 1e15
using namespace std;
 
const int WHITE = 0;
const int GREY = 1;
const int BLACK = 2;
const int MX = 1e5 + 5;
int parent[MX];
int colors[MX];
map<int, vector<int>> graph;
// WHITE = unvisited, GREY = visiting, BLACK = visited
int find_cycle(int vertex)
{
        colors[vertex] = GREY;
        for (auto edge : graph[vertex])
        {
 
                int trg = edge;
                parent[trg] = vertex;
                if (colors[trg] == GREY)
                {
                        return vertex;
                }
                else if (colors[trg] == WHITE)
                {
 
                        int ans = find_cycle(trg);
                        if (ans != -1)
                        {
                                return ans;
                        }
                }
        }
        colors[vertex] = BLACK;
        return -1;
}
 
void solve()
{
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < M; i++)
        {
                int src, trg;
                cin >> src >> trg;
                graph[src].pb(trg);
        }
        for (int i = 1; i <= N; i++)
        {
                if (colors[i] == WHITE)
                {
                        int ans = find_cycle(i);
                        if (ans != -1)
                        {
                                for (int i = 0; i < N; i++)
                                {
                                        ans = parent[ans];
                                }
                                vector<int> path;
                                int temp = ans;
                                while (temp != ans || path.size() < 1)
                                {
                                        path.pb(temp);
                                        temp = parent[temp];
                                }
                                path.pb(ans);
                                cout << path.size() << endl;
 
                                for (int i = path.size() - 1; i >= 0; i--)
                                {
                                        cout << path[i] << " ";
                                }
                                return;
                        }
                }
        }
        cout << "IMPOSSIBLE" << endl;
}
 
int main()
{
        solve();
        return 0;
}