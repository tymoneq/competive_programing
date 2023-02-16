#include <bits/stdc++.h>

using namespace std;
int Grid[3][1010];
bool Vis[3][1010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, a, b;
    char z;
    cin >> n;
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> z;
            Grid[i][j] = z - '0';
        }
    cin >> q;
    queue<pair<int, int>> que;
    for (int Q = 0; Q < q; Q++)
    {
        cin >> a >> b;
        int res = 0;
        for (int i = 0; i < 3; i++)
            for (int j = a; j <= b; j++)
                if (!Vis[i][j] && Grid[i][j] == 1)
                {
                    res++;
                    que.push({i, j});
                    Vis[i][j] = 1;
                    while (!que.empty())
                    {
                        auto v = que.front();
                        que.pop();
                        if (v.first > 0 && !Vis[v.first - 1][v.second] && Grid[v.first - 1][v.second] == 1)
                        {
                            que.push({v.first - 1, v.second});
                            Vis[v.first - 1][v.second] = 1;
                        }
                        if (v.first < 2 && !Vis[v.first + 1][v.second] && Grid[v.first + 1][v.second] == 1)
                        {
                            que.push({v.first + 1, v.second});
                            Vis[v.first + 1][v.second] = 1;
                        }
                        if (v.second - 1 >= a && !Vis[v.first][v.second - 1] && Grid[v.first][v.second - 1] == 1)
                        {
                            que.push({v.first, v.second - 1});
                            Vis[v.first][v.second - 1] = 1;
                        }
                        if (v.second + 1 <= b && !Vis[v.first][v.second + 1] && Grid[v.first][v.second + 1] == 1)
                        {
                            que.push({v.first, v.second + 1});
                            Vis[v.first][v.second + 1] = 1;
                        }
                    }
                }
        cout << res << "\n";
        for (int i = 0; i < 3; i++)
            for (int j = 1; j <= n; j++)
                Vis[i][j] = 0;
    }
    return 0;
}