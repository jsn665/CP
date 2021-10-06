#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
using namespace std;
const int mX = 1e4;
int n, m;
int parent[mX][mX];
int grid[mX][mX];
pi start, endp;
vector<pi> monsters;
 
bool isValid(int i, int j, int time)
{
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] <= time)
    {
        return false;
    }
    return true;
}
 
bool isEscape(int i, int j, int time)
{
    if (!isValid(i, j, time))
    {
        return false;
    }
    if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
    {
        return true;
    }
    return false;
}
 
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'A')
            {
                grid[i][j] = 0;
                start = mp(i, j);
            }
            else if (c == 'M')
            {
                grid[i][j] = 0;
                monsters.pb(mp(i, j));
            }
            else if (c == '#')
            {
                grid[i][j] = 0;
            }
            else
            {
                grid[i][j] = INT_MAX;
            }
        }
    }
    string moves = "DURL";
    int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<pi, int>> q;
    for (auto m : monsters)
    {
        q.push(mp(m, 0));
    }
    while (!q.empty())
    {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int time = q.front().second;
        time++;
        q.pop();
        for (int *dir : DIRECTIONS)
        {
            int nr = dir[0] + cr;
            int nc = dir[1] + cc;
            if (isValid(nr, nc, time))
            {
                grid[nr][nc] = time;
                q.push(mp(mp(nr, nc), time));
            }
        }
    }
    if (start.first == 0 || start.first == n - 1 || start.second == 0 || start.second == m - 1)
    {
        cout << "YES"
             << "\n";
        cout << 0 << "\n";
        exit(0);
    }
    q.push(mp(start, 0));
    while (!q.empty())
    {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int time = q.front().second;
        time++;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = DIRECTIONS[i][0] + cr;
            int nc = DIRECTIONS[i][1] + cc;
 
            if (isEscape(nr, nc, time))
            {
                parent[nr][nc] = i;
                endp = mp(nr, nc);
                vector<char> steps;
                pi temp = endp;
                while (temp != start)
                {
                    int lastMove = parent[temp.first][temp.second];
                    steps.pb(moves[lastMove]);
                    temp = mp(temp.first - DIRECTIONS[lastMove][0], temp.second - DIRECTIONS[lastMove][1]);
                }
                cout << "YES"
                     << "\n";
                cout << steps.size() << "\n";
                for (int i = steps.size() - 1; i >= 0; i--)
                {
                    cout << steps[i] << "";
                }
                exit(0);
            }
 
            if (isValid(nr, nc, time))
            {
                grid[nr][nc] = time;
                parent[nr][nc] = i;
                q.push(mp(mp(nr, nc), time));
            }
        }
    }
    cout << "NO"
         << "\n";
}
 
int main()
{
    solve();
    return 0;
}