#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1010;

int Grid[N][N], d[N][N];
bool Vis[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    pair<int, int> start, end;
    char a;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a;
            if (a == '.')
                Grid[i][j] = 1;
            else if (a == 'x')
                Grid[i][j] == 0;
            else if (a == 'z')
            {
                start = {i, j};
                Grid[i][j] = 1;
            }
            else if (a == 'n')
            {
                end = {i, j};
                Grid[i][j] = 1;
            }
        }

    queue<pair<int, int>> q;
    Vis[start.first][start.second] = 1;
    d[start.first][start.second] = 0;
    q.push(start);

    while (!q.empty())
    {
        auto v = q.front();
        q.pop();

        if (Grid[v.first - 1][v.second - 2] == 1 && !Vis[v.first - 1][v.second - 2])
        {
            Vis[v.first - 1][v.second - 2] = 1;
            q.push({v.first - 1, v.second - 2});
            d[v.first - 1][v.second - 2] = d[v.first][v.second] + 1;
        }
        if (Grid[v.first - 1][v.second + 2] == 1 && !Vis[v.first - 1][v.second + 2])
        {
            Vis[v.first - 1][v.second + 2] = 1;
            q.push({v.first - 1, v.second + 2});
            d[v.first - 1][v.second + 2] = d[v.first][v.second] + 1;
        }
        if (Grid[v.first + 1][v.second - 2] == 1 && !Vis[v.first + 1][v.second - 2])
        {
            Vis[v.first + 1][v.second - 2] = 1;
            q.push({v.first + 1, v.second - 2});
            d[v.first + 1][v.second - 2] = d[v.first][v.second] + 1;
        }
        if (Grid[v.first + 1][v.second + 2] == 1 && !Vis[v.first + 1][v.second + 2])
        {
            Vis[v.first + 1][v.second + 2] = 1;
            q.push({v.first + 1, v.second + 2});
            d[v.first + 1][v.second + 2] = d[v.first][v.second] + 1;
        }

        if (Grid[v.first - 2][v.second - 1] == 1 && !Vis[v.first - 2][v.second - 1])
        {
            Vis[v.first - 2][v.second - 1] = 1;
            q.push({v.first - 2, v.second - 1});
            d[v.first - 2][v.second - 1] = d[v.first][v.second] + 1;
        }
        if (Grid[v.first - 2][v.second + 1] == 1 && !Vis[v.first - 2][v.second + 1])
        {
            Vis[v.first - 2][v.second + 1] = 1;
            q.push({v.first - 2, v.second + 1});
            d[v.first - 2][v.second + 1] = d[v.first][v.second] + 1;
        }
        if (Grid[v.first + 2][v.second - 1] == 1 && !Vis[v.first + 2][v.second - 1])
        {
            Vis[v.first + 2][v.second - 1] = 1;
            q.push({v.first + 2, v.second - 1});
            d[v.first + 2][v.second - 1] = d[v.first][v.second] + 1;
        }
        if (Grid[v.first + 2][v.second + 1] == 1 && !Vis[v.first + 2][v.second + 1])
        {
            Vis[v.first + 2][v.second + 1] = 1;
            q.push({v.first + 2, v.second + 1});
            d[v.first + 2][v.second + 1] = d[v.first][v.second] + 1;
        }
    }

    if (!Vis[end.first][end.second])
        cout << "NIE\n";
    else
        cout << d[end.first][end.second] << "\n";

    return 0;
}
