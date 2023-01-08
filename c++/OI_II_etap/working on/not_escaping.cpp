#include <bits/stdc++.h>

using namespace std;
struct ladders
{
    int c, d, health;
};
const int M = 1e4 + 7;
int Tower[M][M];
ladders L[M];
int Cost[M];
bool Vist[M][M];
int Dist[M][M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, t, x, a, b, c, d, h;
    cin >> t;
    pair<int, int> v;
    queue<pair<int, int>> Q;
    for (int j = 1; j <= n; j++)
        for (int h = 1; h <= m; h++)
        {
            Vist[j][h] = 0;
            Dist[j][h] = numeric_limits<int>::max() - 1001111;
        }
    for (int i = 0; i < t; i++)
    {

        cin >> n >> m >> k;
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            Cost[j] = x;
        }
        for (int j = 1; j <= k; j++)
        {
            cin >> a >> b >> c >> d >> h;
            Tower[a][b] = j;
            L[j] = {c, d, h};
        }
        Dist[1][1] = 0;
        for (int j = 2; j <= m; j++)
        {
            Dist[1][j] = Dist[1][j - 1] + Cost[1];
            Vist[1][j] = 1;
            if (Tower[1][j] != 0)
            {
                Q.push({L[Tower[1][j]].c, L[Tower[1][j]].d});
                Dist[L[Tower[1][j]].c][L[Tower[1][j]].d] = Dist[1][j] - L[Tower[1][j]].health;
                Vist[L[Tower[1][j]].c][L[Tower[1][j]].d] = 1;
            }
        }

        while (!Q.empty())
        {
            v = Q.front();
            Q.pop();
            if (v.second > 1 && !Vist[v.first][v.second - 1])
            {
                Dist[v.first][v.second - 1] = min(Dist[v.first][v.second] + Cost[v.first], Dist[v.first][v.second - 1]);
                Q.push({v.first, v.second - 1});
                Vist[v.first][v.second - 1] = 1;
            }
            if (v.second < m && !Vist[v.first][v.second + 1])
            {
                Dist[v.first][v.second + 1] = min(Dist[v.first][v.second] + Cost[v.first], Dist[v.first][v.second + 1]);
                Q.push({v.first, v.second + 1});
                Vist[v.first][v.second + 1] = 1;
            }
            if (Tower[v.first][v.second] != 0)
            {
                Q.push({L[Tower[v.first][v.second]].c, L[Tower[v.first][v.second]].d});
                Dist[L[Tower[v.first][v.second]].c][L[Tower[v.first][v.second]].d] = min(Dist[v.first][v.second] - L[Tower[v.first][v.second]].health, Dist[L[Tower[v.first][v.second]].c][L[Tower[v.first][v.second]].d]);
                Vist[L[Tower[v.first][v.second]].c][L[Tower[v.first][v.second]].d] = 1;
            }
        }
        if (!Vist[n][m])
            cout << "NO ESCAPE\n";
        else
            cout << Dist[n][m] << "\n";
        for (int j = 1; j <= n; j++)
            for (int h = 1; h <= m; h++)
            {
                Vist[j][h] = 0;
                Dist[j][h] = numeric_limits<int>::max() - 1001111;
            }
    }
    return 0;
}