#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define pl pair<ll, ll>
#define MAX 1e15
 
void solve()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<ll>> a(N + 1, vector<ll>(N + 1, MAX));
    vector<pi> queries(Q);
    for (int i = 0; i < M; i++)
    {
        ll src, trg, weight;
        cin >> src >> trg >> weight;
        a[src][trg] = a[trg][src] = min(a[src][trg], weight);
    }
    for (int i = 0; i < Q; i++)
    {
        int src, trg;
        cin >> src >> trg;
        queries[i].first = src;
        queries[i].second = trg;
    }
    for (int i = 1; i <= N; i++)
    {
        a[i][i] = 0;
    }
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    for (auto query : queries)
    {
        int x = query.first, y = query.second;
        if (a[x][y] == MAX)
        {
            a[x][y] = -1;
        }
        cout << a[x][y] << endl;
    }
}
 
int main()
{
 
    solve();
 
    return 0;
}