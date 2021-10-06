#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define pi pair<int, ll>
#define MAX 1e15
using namespace std;
 
const int MX = 2505;
int parent[MX];
void solve()
{
        int N, M;
        cin >> N >> M;
        vector<vector<ll>> graph(M, vector<ll>(3));
        for (int i = 0; i < M; i++)
        {
                ll src, trg, length;
                cin >> src >> trg >> length;
                graph[i][0] = src;
                graph[i][1] = trg;
                graph[i][2] = length;
        }
        vector<ll> dist(N + 1);
        for (int i = 1; i <= N - 1; i++)
        {
                for (int j = 0; j < M; j++)
                {
                        ll src = graph[j][0], trg = graph[j][1], length = graph[j][2];
                        if (dist[trg] > dist[src] + length)
                        {
                                dist[trg] = dist[src] + length;
                                parent[trg] = src;
                        }
                }
        }
        int last = -1;
        for (int j = 0; j < M; j++)
        {
                ll src = graph[j][0], trg = graph[j][1], length = graph[j][2];
                if (dist[trg] > dist[src] + length)
                {
                        last = trg;
                        break;
                }
        }
        if (last != -1)
        {
                cout << "YES" << endl;
                for (int i = 1; i <= N - 1; i++)
                {
                        last = parent[last];
                }
                int temp = last;
                vector<int> cycle_path;
                while (temp != last || cycle_path.size() < 1)
                {
                        cycle_path.pb(temp);
                        temp = parent[temp];
                }
 
                cycle_path.pb(temp);
                for (int i = cycle_path.size() - 1; i >= 0; i--)
                {
                        cout << cycle_path[i] << " ";
                }
        }
        else
        {
                cout << "NO";
        }
        cout << endl;
}
 
int main()
{
        solve();
        return 0;
}