#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

typedef long long ll;

struct d
{
    ll x, y, k;
};

void dfs(int x, int y, int k, ll &res, vector<vector<bool>> &Vis, vector<vector<bool>> &Grid, int K)
{
    Vis[x][y] = 1;

    for (int r = 0; r < 4; r++)
        if (Grid[x + dx[r]][y + dy[r]] && !Vis[x + dx[r]][y + dy[r]])
        {

            if (k + 1 == K)
                res++;
            else
            {
                Vis[x + dx[r]][y + dy[r]] = 1;
                dfs(x + dx[r], y + dy[r], k + 1, res, Vis, Grid, K);
            }
        }

    Vis[x][y] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int H, W, K;
    cin >> H >> W >> K;

    vector<vector<bool>> Grid(H + 2, vector<bool>(W + 2, 0));

    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
        {
            char a;
            cin >> a;

            if (a == '.')
                Grid[i][j] = 1;
        }

    ll res = 0;
    vector<vector<bool>> Vis(H + 2, vector<bool>(W + 2, 0));
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
        {
            if (!Grid[i][j])
                continue;

            dfs(i, j, 0, res, Vis, Grid, K);
        }

    cout << res << "\n";

    return 0;
}