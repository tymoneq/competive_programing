#include <bits/stdc++.h>

using namespace std;
const int MAX_VAl = 55;
char Board[MAX_VAl][MAX_VAl];
int RES[MAX_VAl][MAX_VAl];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, code = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> Board[i][j];

    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (RES[i][j] != 0)
                continue;
            q.push(make_pair(i, j));
            RES[i][j] = code;
            while (!q.empty())
            {
                auto v = q.front();
                q.pop();
                if (Board[v.first + 1][v.second] == Board[i][j] && RES[v.first + 1][v.second] == 0)
                {
                    q.push(make_pair(v.first + 1, v.second));
                    RES[v.first + 1][v.second] = code;
                }
                if (Board[v.first - 1][v.second] == Board[i][j] && RES[v.first - 1][v.second] == 0)
                {
                    q.push(make_pair(v.first - 1, v.second));
                    RES[v.first - 1][v.second] = code;
                }
                if (Board[v.first][v.second + 1] == Board[i][j] && RES[v.first][v.second + 1] == 0)
                {
                    q.push(make_pair(v.first, v.second + 1));
                    RES[v.first][v.second + 1] = code;
                }
                if (Board[v.first][v.second - 1] == Board[i][j] && RES[v.first][v.second - 1] == 0)
                {
                    q.push(make_pair(v.first, v.second - 1));
                    RES[v.first][v.second - 1] = code;
                }
            }
            code++;
        }
    }

    return 0;
}