#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Flood fill
int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int r, int c, vector<string> &grid)
{
    if (r < 0 || c < 0 || r == grid.size() || c == grid[0].size() || grid[r][c] == '#')
    {
        return;
    }
    grid[r][c] = '#';
    for (int i = 0; i < 4; i++)
    {
        int dx = DIRECTIONS[i][0];
        int dy = DIRECTIONS[i][1];
        dfs(r + dx, c + dy, grid);
    }
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
            {
                dfs(i, j, a);
                res++;
            }
        }
    }
    cout << res << "\n";
}
 
int main()
{
    solve();
}