#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pi pair<int, long long>
#define ll long long
#define MX 1e17
using namespace std;

int N, M;
map<int, vector<pi>> graph;

void solve()
{
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < M; i++)
        {
                ll src, trg, weight;
                cin >> src >> trg >> weight;
                graph[src].pb(mp(trg, weight));
        }
        vector<ll> full_price(N + 1, MX), discount_price(N + 1, MX);
        priority_queue<pair<pair<ll, int>, bool>, vector<pair<pair<ll, int>, bool>>, greater<pair<pair<ll, int>, bool>>> pq;
        full_price[1] = discount_price[1] = 0;
        pq.push(mp(mp(0, 1), 0));
        pq.push(mp(mp(0, 1), 1));
        while (!pq.empty())
        {
                ll minCost = pq.top().first.first;
                int currentVertex = pq.top().first.second;
                bool couponUsed = pq.top().second;
                pq.pop();
                if (couponUsed)
                {
                        if (minCost > discount_price[currentVertex])
                        {
                                continue;
                        }
                }
                else
                {
                        if (minCost > full_price[currentVertex])
                        {
                                continue;
                        }
                }
                for (auto edge : graph[currentVertex])
                {
                        ll trg = edge.first, cost = edge.second;
                        if (couponUsed)
                        {
                                if (minCost + cost < discount_price[trg])
                                {
                                        discount_price[trg] = minCost + cost;
                                        pq.push(mp(mp(discount_price[trg], trg), 1));
                                }
                        }
                        else
                        {
                                if (minCost + cost < full_price[trg])
                                {
                                        full_price[trg] = minCost + cost;
                                        pq.push(mp(mp(full_price[trg], trg), 0));
                                }
                                if (minCost + (cost / 2) < discount_price[trg])
                                {
                                        discount_price[trg] = minCost + (cost / 2);
                                        pq.push(mp(mp(discount_price[trg], trg), 1));
                                }
                        }
                }
        }
        cout << discount_price[N] << endl;
}

int main()
{
        solve();
        return 0;
}