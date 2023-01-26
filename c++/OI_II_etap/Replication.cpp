#include <bits/stdc++.h>

using namespace std;
const int M = 1010;
int Grid[M][M];
bool Vis[M][M];
bool Res[M][M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d, res = 0;
    cin >> n >> d;
    char c;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            if (c == '#')
                Grid[i][j] = -1;
            else if (c == '.')
                Grid[i][j] = 0;
            else if (c == 'S')
            {
                Grid[i][j] = 0;
                Q.push({i, j});
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (Res[i][j])
                res++;

    cout << res;
    return 0;
}