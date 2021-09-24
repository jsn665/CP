#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define pi pair<int, ll>
#define MAX 1e15
using namespace std;

map<int, vector<int>> graph;
map<int, int> indegree;
void solve()
{
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < M; i++)
        {
                int src, trg;
                cin >> src >> trg;
                graph[src].pb(trg);
                indegree[trg]++;
        }
        queue<int> q;
        for (int i = 1; i <= N; i++)
        {
                if (indegree[i] == 0)
                {
                        q.emplace(i);
                }
        }
        vector<int> topological_sort;
        while (!q.empty())
        {
                int vertex = q.front();
                q.pop();
                topological_sort.pb(vertex);
                for (auto edge : graph[vertex])
                {
                        M--;
                        indegree[edge]--;
                        if (indegree[edge] == 0)
                        {
                                q.emplace(edge);
                        }
                }
        }
        if (M > 0)
        {
                cout << "IMPOSSIBLE";
        }
        else
        {
                for (auto vertex : topological_sort)
                {
                        cout << vertex << " ";
                }
        }
        cout << endl;
}

int main()
{
        solve();
        return 0;
}