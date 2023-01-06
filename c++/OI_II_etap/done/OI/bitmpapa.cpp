#include <bits/stdc++.h>
using namespace std;
const int M = 200;
int Bitmap[M][M], RES[M][M];
bool Vis[M][M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    string row;
    cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> row;
        for (int j = 1; j <= m; j++)
        {
            Bitmap[i][j] = row[j - 1] - 48;
            if (Bitmap[i][j] == 1)
            {
                Vis[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        if (v.first > 0 && !Vis[v.first - 1][v.second])
        {
            RES[v.first - 1][v.second] = RES[v.first][v.second] + 1;
            Vis[v.first - 1][v.second] = 1;
            q.push({v.first - 1, v.second});
        }
        if (v.first <= n && !Vis[v.first + 1][v.second])
        {
            RES[v.first + 1][v.second] = RES[v.first][v.second] + 1;
            Vis[v.first + 1][v.second] = 1;
            q.push({v.first + 1, v.second});
        }
        if (v.second <= m && !Vis[v.first][v.second + 1])
        {
            RES[v.first][v.second + 1] = RES[v.first][v.second] + 1;
            Vis[v.first][v.second + 1] = 1;
            q.push({v.first, v.second + 1});
        }
        if (v.second > 0 && !Vis[v.first][v.second - 1])
        {
            RES[v.first][v.second - 1] = RES[v.first][v.second] + 1;
            Vis[v.first][v.second - 1] = 1;
            q.push({v.first, v.second - 1});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << RES[i][j] << " ";
        cout << "\n";
    }
    return 0;
}