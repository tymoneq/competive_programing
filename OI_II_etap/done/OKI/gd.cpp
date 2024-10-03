#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1010;

int Grid[N][N];
bool Vis[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, doliny = 0, grzbiety = 0;
    cin >> n;

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            Grid[i][j] = -1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> Grid[i][j];

    queue<pair<int, int>> q;
    bool T = 1;
    // sprawdzanie dolin
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!Vis[i][j])
            {
                T = 1;
                q.push({i, j});
                Vis[i][j] = 1;
                while (!q.empty())
                {
                    auto v = q.front();
                    q.pop();
                    if (Grid[v.first + 1][v.second] < Grid[v.first][v.second] && Grid[v.first + 1][v.second] != -1)
                        T = 0;
                    if (Grid[v.first - 1][v.second] < Grid[v.first][v.second] && Grid[v.first - 1][v.second] != -1)
                        T = 0;
                    if (Grid[v.first + 1][v.second + 1] < Grid[v.first][v.second] && Grid[v.first + 1][v.second + 1] != -1)
                        T = 0;
                    if (Grid[v.first + 1][v.second - 1] < Grid[v.first][v.second] && Grid[v.first + 1][v.second - 1] != -1)
                        T = 0;

                    if (Grid[v.first][v.second + 1] < Grid[v.first][v.second] && Grid[v.first][v.second + 1] != -1)
                        T = 0;
                    if (Grid[v.first][v.second - 1] < Grid[v.first][v.second] && Grid[v.first][v.second - 1] != -1)
                        T = 0;
                    if (Grid[v.first - 1][v.second + 1] < Grid[v.first][v.second] && Grid[v.first - 1][v.second + 1] != -1)
                        T = 0;
                    if (Grid[v.first - 1][v.second - 1] < Grid[v.first][v.second] && Grid[v.first - 1][v.second - 1] != -1)
                        T = 0;
                    // ##################################################################
                    if (Grid[v.first + 1][v.second] == Grid[v.first][v.second] && !Vis[v.first + 1][v.second])
                    {
                        q.push({v.first + 1, v.second});
                        Vis[v.first + 1][v.second] = 1;
                    }
                    if (Grid[v.first - 1][v.second] == Grid[v.first][v.second] && !Vis[v.first - 1][v.second])
                    {
                        q.push({v.first - 1, v.second});
                        Vis[v.first + 1][v.second] = 1;
                    }
                    if (Grid[v.first + 1][v.second + 1] == Grid[v.first][v.second] && !Vis[v.first + 1][v.second + 1])
                    {
                        q.push({v.first + 1, v.second + 1});
                        Vis[v.first + 1][v.second + 1] = 1;
                    }
                    if (Grid[v.first + 1][v.second - 1] == Grid[v.first][v.second] && !Vis[v.first + 1][v.second - 1])
                    {
                        q.push({v.first + 1, v.second - 1});
                        Vis[v.first + 1][v.second - 1] = 1;
                    }

                    if (Grid[v.first][v.second + 1] == Grid[v.first][v.second] && !Vis[v.first][v.second + 1])
                    {
                        q.push({v.first, v.second + 1});
                        Vis[v.first][v.second + 1] = 1;
                    }
                    if (Grid[v.first][v.second - 1] == Grid[v.first][v.second] && !Vis[v.first][v.second - 1])
                    {
                        q.push({v.first, v.second - 1});
                        Vis[v.first][v.second - 1] = 1;
                    }
                    if (Grid[v.first - 1][v.second + 1] == Grid[v.first][v.second] && !Vis[v.first - 1][v.second + 1])
                    {
                        q.push({v.first - 1, v.second + 1});
                        Vis[v.first - 1][v.second + 1] = 1;
                    }
                    if (Grid[v.first - 1][v.second - 1] == Grid[v.first][v.second] && !Vis[v.first - 1][v.second - 1])
                    {
                        q.push({v.first - 1, v.second - 1});
                        Vis[v.first - 1][v.second - 1] = 1;
                    }
                }
                doliny += (T ? 1 : 0);
            }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            Vis[i][j] = 0;

    // Sprawdzanie grzbietow

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!Vis[i][j])
            {
                T = 1;
                q.push({i, j});
                Vis[i][j] = 1;
                while (!q.empty())
                {
                    auto v = q.front();
                    q.pop();
                    if (Grid[v.first + 1][v.second] > Grid[v.first][v.second] && Grid[v.first + 1][v.second] != -1)
                        T = 0;
                    if (Grid[v.first - 1][v.second] > Grid[v.first][v.second] && Grid[v.first - 1][v.second] != -1)
                        T = 0;
                    if (Grid[v.first + 1][v.second + 1] > Grid[v.first][v.second] && Grid[v.first + 1][v.second + 1] != -1)
                        T = 0;
                    if (Grid[v.first + 1][v.second - 1] > Grid[v.first][v.second] && Grid[v.first + 1][v.second - 1] != -1)
                        T = 0;

                    if (Grid[v.first][v.second + 1] > Grid[v.first][v.second] && Grid[v.first][v.second + 1] != -1)
                        T = 0;
                    if (Grid[v.first][v.second - 1] > Grid[v.first][v.second] && Grid[v.first][v.second - 1] != -1)
                        T = 0;
                    if (Grid[v.first - 1][v.second + 1] > Grid[v.first][v.second] && Grid[v.first - 1][v.second + 1] != -1)
                        T = 0;
                    if (Grid[v.first - 1][v.second - 1] > Grid[v.first][v.second] && Grid[v.first - 1][v.second - 1] != -1)
                        T = 0;
                    // ##################################################################
                    if (Grid[v.first + 1][v.second] == Grid[v.first][v.second] && !Vis[v.first + 1][v.second])
                    {
                        q.push({v.first + 1, v.second});
                        Vis[v.first + 1][v.second] = 1;
                    }
                    if (Grid[v.first - 1][v.second] == Grid[v.first][v.second] && !Vis[v.first - 1][v.second])
                    {
                        q.push({v.first - 1, v.second});
                        Vis[v.first + 1][v.second] = 1;
                    }
                    if (Grid[v.first + 1][v.second + 1] == Grid[v.first][v.second] && !Vis[v.first + 1][v.second + 1])
                    {
                        q.push({v.first + 1, v.second + 1});
                        Vis[v.first + 1][v.second + 1] = 1;
                    }
                    if (Grid[v.first + 1][v.second - 1] == Grid[v.first][v.second] && !Vis[v.first + 1][v.second - 1])
                    {
                        q.push({v.first + 1, v.second - 1});
                        Vis[v.first + 1][v.second - 1] = 1;
                    }

                    if (Grid[v.first][v.second + 1] == Grid[v.first][v.second] && !Vis[v.first][v.second + 1])
                    {
                        q.push({v.first, v.second + 1});
                        Vis[v.first][v.second + 1] = 1;
                    }
                    if (Grid[v.first][v.second - 1] == Grid[v.first][v.second] && !Vis[v.first][v.second - 1])
                    {
                        q.push({v.first, v.second - 1});
                        Vis[v.first][v.second - 1] = 1;
                    }
                    if (Grid[v.first - 1][v.second + 1] == Grid[v.first][v.second] && !Vis[v.first - 1][v.second + 1])
                    {
                        q.push({v.first - 1, v.second + 1});
                        Vis[v.first - 1][v.second + 1] = 1;
                    }
                    if (Grid[v.first - 1][v.second - 1] == Grid[v.first][v.second] && !Vis[v.first - 1][v.second - 1])
                    {
                        q.push({v.first - 1, v.second - 1});
                        Vis[v.first - 1][v.second - 1] = 1;
                    }
                }
                grzbiety += (T ? 1 : 0);
            }

    cout << max(1, grzbiety) << " " << max(1, doliny)
         << "\n";
    return 0;
}