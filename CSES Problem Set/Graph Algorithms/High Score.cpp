#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pi pair<int, int>
#define ll long long
#define MAX 1e15
#define NEGATIVE_CYCLE (ll) - 1e15
using namespace std;
int N, M;
 
struct Edge
{
        ll src, trg, weight;
};
 
void solve()
{
        // Bellman Ford, longest path with negative cycle detection
        cin >> N >> M;
        vector<Edge> graph(M);
        for (int i = 0; i < M; i++)
        {
                Edge e = {};
                cin >> e.src >> e.trg >> e.weight;
                e.weight *= -1;
                graph[i] = e;
        }
        vector<ll> dist(N + 1, MAX);
        dist[1] = 0;
        for (int i = 1; i <= N - 1; i++)
        {
                for (int j = 0; j < M; j++)
                {
                        ll src = graph[j].src, trg = graph[j].trg, weight = graph[j].weight;
                        if (dist[src] == MAX)
                                continue;
                        dist[trg] = min(dist[trg], dist[src] + weight);
                        dist[trg] = max(dist[trg], NEGATIVE_CYCLE);
                }
        }
 
        for (int i = 1; i <= N - 1; i++)
        {
                for (int j = 0; j < M; j++)
                {
                        ll src = graph[j].src, trg = graph[j].trg, weight = graph[j].weight;
                        if (dist[trg] == MAX)
                                continue;
                        dist[trg] = max(dist[trg], NEGATIVE_CYCLE);
                        if (dist[src] + weight < dist[trg])
                        {
                                dist[trg] = NEGATIVE_CYCLE;
                        }
                }
        }
        if (dist[N] == NEGATIVE_CYCLE)
        {
                cout << -1;
        }
        else
        {
                cout << dist[N] * -1;
        }
 
        cout << endl;
}
 
int main()
{
        solve();
        return 0;
}