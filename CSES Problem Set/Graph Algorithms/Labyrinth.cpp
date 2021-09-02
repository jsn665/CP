#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define pb push_back
#define mk make_pair
using namespace std;

void solve()
{
    char validDir[4] = {'D', 'U', 'L', 'R'};
    int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int n, m;
    cin >> n >> m;
    vector<vector<int>> previousStep(n, vector<int>(m)); // previousStep[i][j] = the direction taken to get to this cell directions are = {0, 1, 2, 3}
    vector<vector<char>> grid(n);
    pi begin, end;
    for (int i = 0; i < n; i++)
    {
        vector<char> row(m);
        for (int j = 0; j < m; j++)
        {
            cin >> row[j];
            if (row[j] == 'A')
            {
                begin = mk(i, j);
            }
            else if (row[j] == 'B')
            {
                end = mk(i, j);
            }
        }
        grid[i] = row;
    }

    queue<pi> q;
    q.push(begin);
    vector<vector<int>> visited(n, vector<int>(m, 0));
    visited[begin.first][begin.second] = 1;
    while (!q.empty())
    {
        pi current = q.front();

        q.pop();
        if (current.first == end.first && current.second == end.second)
        {
            vector<char> steps;
            while (end != begin)
            {
                int prev = previousStep[end.first][end.second];
                steps.pb(validDir[prev]);
                end = mk(end.first - DIRECTIONS[prev][0], end.second - DIRECTIONS[prev][1]);
            }
            cout << "YES"
                 << "\n"
                 << steps.size() << "\n";
            for (int i = steps.size() - 1; i >= 0; i--)
            {
                cout << steps[i];
            }
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nr = DIRECTIONS[i][0] + current.first;
            int nc = DIRECTIONS[i][1] + current.second;
            if (nr < 0 || nc < 0 || nr >= n || nc >= m || visited[nr][nc] || grid[nr][nc] == '#')
            {
                continue;
            }
            visited[nr][nc] = 1;
            previousStep[nr][nc] = i;
            q.push(mk(nr, nc));
        }
    }
    cout << "NO";
}

int main()
{
    solve();
}