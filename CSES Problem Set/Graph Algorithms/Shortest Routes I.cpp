#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define pl pair<ll, ll>
 
map<int, vector<pi>> graph;
 
vector<ll> shortest_path(int N, map<int, vector<pi>> graph, int start)
{
    vector<ll> dist(N + 1, LLONG_MAX);
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    dist[start] = 0;
    pq.push(mp(0, start));
    while (!pq.empty())
    {
        pl current = pq.top();
        ll cost = current.first;
        int node = current.second;
        pq.pop();
        if (dist[node] < cost)
            continue;
        for (pi edge : graph[node])
        {
            int trg = edge.first;
            int weight = edge.second;
 
            ll distance_to_trg = cost + weight;
            if (distance_to_trg < dist[trg])
            {
                dist[trg] = distance_to_trg;
                pq.push(mp(distance_to_trg, trg));
            }
        }
    }
    return dist;
}
 
void solve()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int src, trg, weight;
        cin >> src >> trg >> weight;
        graph[src].pb(mp(trg, weight));
    }
 
    vector<ll> dist = shortest_path(N, graph, 1);
    for (int i = 1; i <= N; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}
 
int main()
{
 
    solve();
 
    return 0;
}