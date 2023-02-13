#include <bits/stdc++.h>
using namespace std;
constexpr int M = 1010;
struct bessieDream
{
    int x, y, mask;
};

int Dist[M][M][2];
int Grid[M][M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> Grid[i][j];
    queue<bessieDream> q;
    Dist[1][1][0] = Dist[1][1][1] = 1;
    q.push({1, 1, 0});
    constexpr int newmask = 1;
    int x, y;
    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        // 1 can access normally
        if (v.x - 1 > 0 && Dist[v.x - 1][v.y][v.mask] == 0 && Grid[v.x - 1][v.y] == 1)
        {
            Dist[v.x - 1][v.y][v.mask] = Dist[v.x][v.y][v.mask] + 1;
            q.push({v.x - 1, v.y, v.mask});
        }
        if (v.x + 1 <= n && Dist[v.x + 1][v.y][v.mask] == 0 && Grid[v.x + 1][v.y] == 1)
        {
            Dist[v.x + 1][v.y][v.mask] = Dist[v.x][v.y][v.mask] + 1;
            q.push({v.x + 1, v.y, v.mask});
        }
        if (v.y - 1 > 0 && Dist[v.x][v.y - 1][v.mask] == 0 && Grid[v.x][v.y - 1] == 1)
        {
            Dist[v.x][v.y - 1][v.mask] = Dist[v.x][v.y][v.mask] + 1;
            q.push({v.x, v.y - 1, v.mask});
        }
        if (v.y + 1 <= m && Dist[v.x][v.y + 1][v.mask] == 0 && Grid[v.x][v.y + 1] == 1)
        {
            Dist[v.x][v.y + 1][v.mask] = Dist[v.x][v.y][v.mask] + 1;
            q.push({v.x, v.y + 1, v.mask});
        }
        // 2 change mask
        if (v.x - 1 > 0 && Dist[v.x - 1][v.y][v.mask] == 0 && Grid[v.x - 1][v.y] == 2)
        {
            Dist[v.x - 1][v.y][v.mask | newmask] = Dist[v.x][v.y][v.mask] + 1;
            q.push({v.x - 1, v.y, v.mask | newmask});
        }
        if (v.x + 1 <= n && Dist[v.x + 1][v.y][v.mask] == 0 && Grid[v.x + 1][v.y] == 2)
        {
            Dist[v.x + 1][v.y][v.mask | newmask] = Dist[v.x][v.y][v.mask] + 1;
            q.push({v.x + 1, v.y, v.mask | newmask});
        }
        if (v.y - 1 > 0 && Dist[v.x][v.y - 1][v.mask] == 0 && Grid[v.x][v.y - 1] == 2)
        {
            Dist[v.x][v.y - 1][v.mask | newmask] = Dist[v.x][v.y][v.mask] + 1;
            q.push({v.x, v.y - 1, v.mask | newmask});
        }
        if (v.y + 1 <= m && Dist[v.x][v.y + 1][v.mask] == 0 && Grid[v.x][v.y + 1] == 2)
        {
            Dist[v.x][v.y + 1][v.mask | newmask] = Dist[v.x][v.y][v.mask] + 1;
            q.push({v.x, v.y + 1, v.mask | newmask});
        }
        // 3 pirats
        if (v.x - 1 > 0 && Dist[v.x - 1][v.y][v.mask] == 0 && v.mask == 1 && Grid[v.x - 1][v.y] == 3)
        {
            Dist[v.x - 1][v.y][0] = Dist[v.x][v.y][v.mask] + 1;
            q.push({v.x - 1, v.y, 0});
        }
        if (v.x + 1 <= n && Dist[v.x + 1][v.y][v.mask] == 0 && v.mask == 1 && Grid[v.x + 1][v.y] == 3)
        {
            Dist[v.x + 1][v.y][0] = Dist[v.x][v.y][v.mask] + 1;
            q.push({v.x + 1, v.y, 0});
        }
        if (v.y - 1 > 0 && Dist[v.x][v.y - 1][v.mask] == 0 && v.mask == 1 && Grid[v.x][v.y - 1] == 3)
        {
            Dist[v.x][v.y - 1][0] = Dist[v.x][v.y][v.mask] + 1;
            q.push({v.x, v.y - 1, 0});
        }
        if (v.y + 1 <= m && Dist[v.x][v.y + 1][v.mask] == 0 && v.mask == 1 && Grid[v.x][v.y + 1] == 3)
        {
            Dist[v.x][v.y + 1][0] = Dist[v.x][v.y][v.mask] + 1;
            q.push({v.x, v.y + 1, 0});
        }
        // 4 slide :)))
        if (v.x - 1 > 0 && Dist[v.x][v.y + 1][v.mask] == 0 && Grid[v.x - 1][v.y] == 4)
        {
            x = v.x - 1;
            Dist[x][v.y][v.mask] = Dist[v.x][v.y][v.mask] + 1;
            while (x - 1 > 0 && Dist[x - 1][v.y][v.mask] == 0 && Grid[x - 1][v.y] == 4)
            {
                x--;
                Dist[x][v.y][v.mask] = Dist[x + 1][v.y][v.mask] + 1;
            }
            Dist[x - 1][v.y][v.mask] = Dist[x][v.y][v.mask] + 1;
            q.push({x - 1, v.y, v.mask});
        }
        if (v.x + 1 <= n && Dist[x + 1][v.y][v.mask] == 0 && Grid[v.x + 1][v.y] == 4)
        {
            x = v.x + 1;
            Dist[x][v.y][v.mask] = Dist[v.x][v.y][v.mask] + 1;
            while (x + 1 <= n && Dist[x + 1][v.y][v.mask] == 0 && Grid[x + 1][v.y] == 4)
            {
                x++;
                Dist[x][v.y][v.mask] = Dist[x - 1][v.y][v.mask] + 1;
            }
            Dist[x + 1][v.y][v.mask] = Dist[x][v.y][v.mask] + 1;
            q.push({x + 1, v.y, v.mask});
        }
        if (v.y - 1 > 0 && Dist[v.x][v.y - 1][v.mask] == 0 && Grid[v.x][v.y - 1] == 4)
        {
            y = v.y - 1;
            Dist[v.x][y][v.mask] = Dist[v.x][v.y][v.mask] + 1;
            while (y - 1 > 0 && Dist[v.x][y - 1][v.mask] == 0 && Grid[v.x][y - 1] == 4)
            {
                y--;
                Dist[v.x][y][v.mask] = Dist[v.x][y + 1][v.mask] + 1;
            }

            Dist[v.x][y - 1][v.mask] = Dist[v.x][y][v.mask] + 1;
            q.push({v.x, y - 1, v.mask});
        }
        if (v.y + 1 <= m && Dist[v.x][v.y + 1][v.mask] == 0 && Grid[v.x][v.y + 1] == 4)
        {
            y = v.y + 1;
            Dist[v.x][y][v.mask] = Dist[v.x][v.y][v.mask] + 1;
            while (y + 1 <= m && Dist[v.x][y + 1][v.mask] == 0 && Grid[v.x][y + 1] == 4)
            {
                y++;
                Dist[v.x][y][v.mask] = Dist[v.x][y - 1][v.mask] + 1;
            }

            Dist[v.x][y + 1][v.mask] = Dist[v.x][y][v.mask] + 1;
            q.push({v.x, y + 1, v.mask});
        }
    }
    if (Dist[n][m][0] == 0)
        Dist[n][m][0] = numeric_limits<int>::max();
    if (Dist[n][m][1] == 0)
        Dist[n][m][0] = numeric_limits<int>::max();
    cout << (min(Dist[n][m][0], Dist[n][m][1]) != numeric_limits<int>::max() ? min(Dist[n][m][0], Dist[n][m][1]) - 1 : -1);
    return 0;
}