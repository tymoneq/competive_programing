#include <bits/stdc++.h>

using namespace std;
// bitset
constexpr int M = 20;
char Grid[M][M];
set<char> G[M][M];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, n, c, q;
    cin >> T;
    char z;
    int x1 = 0, y1 = 0, x2 = 2000, y2 = 2000;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> c >> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                Grid[i][j] = '/';
        vector<pair<int, int>> Poz(q);
        for (int i = 0; i < q; i++)
        {
            cin >> Poz[i].first >> Poz[i].second >> z;
            Grid[Poz[i].first][Poz[i].second] = z;
        }
        for (auto w : Poz)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    G[i][j].clear();
            int X1, X2 = 2000, Y1, Y2 = 2000;
            X1 = w.first;
            Y1 = w.second;
            G[X1][Y1].insert(Grid[X1][Y1]);
            for (int i = X1 + 1; i < n; i++)
            {
                G[i][Y1] = G[i - 1][Y1];
                if (Grid[i][Y1] != '/')
                    G[i][Y1].insert(Grid[i][Y1]);
                if (G[i][Y1].size() == c)
                {
                    X2 = min(i, X2);
                    Y2 = Y1;
                }
            }
            for (int i = Y1 + 1; i < n; i++)
            {
                G[X1][i] = G[X1][i - 1];
                if (Grid[X1][i] != '/')
                    G[X1][i].insert(Grid[X1][i]);
                if (G[i][Y1].size() == c && (abs(Y1 - Y2) < abs(X1 - X2)))
                {
                    X2 = X1;
                    Y2 = min(i, Y2);
                }
            }
            for (int i = X1 + 1; i < n; i++)
                for (int j = Y1 + 1; j < n; j++)
                {
                    G[i][j] = G[i][j - 1];
                    for (char h : G[i - 1][j])
                        G[i][j].insert(h);
                    if (Grid[i][j] != '/')
                        G[i][j].insert(Grid[i][j]);
                    if (G[i][j].size() == c && (abs(X1 - X2) * abs(Y1 - Y2)) > (abs(X1 - i) * abs(Y1 - j)))
                    {
                        X2 = min(i, X2);
                        Y2 = min(j, Y2);
                    }
                }
            if (abs(x1 - x2) * abs(y1 - y2) > abs(X1 - X2) * abs(Y1 - Y2))
                x1 = X1, y1 = Y1, x2 = X2, y2 = Y2;
        }
        cout << "Case #" << t << ":  " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << (abs(x1 - x2) * abs(y1 - y2)) << "\n";
    }
    return 0;
}