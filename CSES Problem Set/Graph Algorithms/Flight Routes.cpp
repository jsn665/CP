#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define pi pair<int, ll>
#define MAX 1e15
using namespace std;
 
map<int, vector<pi>> graph;
void solve()
{
        int N, M, K;
        cin >> N >> M >> K;
 
        for (int i = 0; i < M; i++)
        {
                ll src, trg, weight;
                cin >> src >> trg >> weight;
                graph[src].pb(mp(trg, weight));
        }
        vector<vector<ll>> k_shortest(N + 1, vector<ll>(K, MAX));
        k_shortest[1][0] = 0;
 
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.emplace(mp(0, 1));
        while (!pq.empty())
        {
                ll minCost = pq.top().first;
                int vertex = pq.top().second;
                pq.pop();
                if (k_shortest[vertex][K - 1] < minCost)
                {
                        continue;
                }
                for (auto edge : graph[vertex])
                {
                        ll weight = edge.second;
                        int trg = edge.first;
                        ll new_dist = minCost + weight;
                        if (new_dist < k_shortest[trg][K - 1])
                        {
                                k_shortest[trg][K - 1] = new_dist;
                                pq.emplace(mp(new_dist, trg));
                                sort(k_shortest[trg].begin(), k_shortest[trg].end());
                        }
                                }
        }
        for (int i = 0; i < K; i++)
        {
                cout << k_shortest[N][i] << " ";
        }
        cout << "\n";
}
 
int main()
{
        solve();
        return 0;
}