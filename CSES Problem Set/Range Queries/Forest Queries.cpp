#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
#define pi pair<int, int>
 
int prefix_sum[1005][1005];
int main()
{
 
        int N, Q;
        cin >> N >> Q;
        for (int i = 1; i <= N; i++)
        {
                for (int j = 1; j <= N; j++)
                {
                        char c;
                        cin >> c;
                        prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + (c == '*');
                }
        }
        vector<pair<pi, pi>> queries(Q);
        for (int i = 0; i < Q; i++)
        {
                cin >> queries[i].first.first >> queries[i].first.second >> queries[i].second.first >> queries[i].second.second;
        }
        for (pair<pi, pi> q : queries)
        {
                int X1 = q.first.first, Y1 = q.first.second, X2 = q.second.first, Y2 = q.second.second;
                cout << prefix_sum[X2][Y2] - prefix_sum[X1 - 1][Y2] - prefix_sum[X2][Y1 - 1] + prefix_sum[X1 - 1][Y1 - 1] << "\n";
        }
 
        return 0;
}