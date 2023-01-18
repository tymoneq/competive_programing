#include <bits/stdc++.h>

using namespace std;
const int M = 110;
int Grid[M][M];
bool Vis[M][M];
bool Roads[M][M];
int res, n;
inline void dfs(int row, int col, bool road)
{
    Vis[row][col] = 1;
    if (!Roads[row][col])
    {
        if (row > 1 && !Vis[row - 1][col])
        {
            if (Grid[row - 1][col] == 1 && road)
                res++;
            dfs(row - 1, col, road);
        }
        if (row < n && !Vis[row + 1][col])
        {
            if (Grid[row + 1][col] == 1 && road)
                res++;
            dfs(row + 1, col, road);
        }
        if (col > 1 && !Vis[row][col - 1])
        {
            if (Grid[row][col - 1] == 1 && road)
                res++;
            dfs(row, col - 1, road);
        }
        if (col < n && !Vis[row][col + 1])
        {
            if (Grid[row][col + 1] == 1 && road)
                res++;
            dfs(row, col + 1, road);
        }
    }
    else
    {
        if (row > 1 && !Roads[row - 1][col] && !Vis[row - 1][col])
        {
            if (Grid[row - 1][col] == 1 && road)
                res++;
            dfs(row - 1, col, road);
        }
        if (row < n && !Roads[row + 1][col] && !Vis[row + 1][col])
        {
            if (Grid[row + 1][col] == 1 && road)
                res++;
            dfs(row + 1, col, road);
        }
        if (col > 1 && !Roads[row][col - 1] && !Vis[row][col - 1])
        {
            if (Grid[row][col - 1] == 1 && road)
                res++;
            dfs(row, col - 1, road);
        }
        if (col < n && !Roads[row][col + 1] && !Vis[row][col + 1])
        {
            if (Grid[row][col + 1] == 1 && road)
                res++;
            dfs(row, col + 1, road);
        }
        // ##########################################
        if (row > 1 && Roads[row - 1][col] && !Vis[row - 1][col])
        {
            if (Grid[row - 1][col] == 1)
                res++;
            dfs(row - 1, col, road = 1);
        }
        if (row < n && Roads[row + 1][col] && !Vis[row + 1][col])
        {
            if (Grid[row + 1][col] == 1)
                res++;
            dfs(row + 1, col, road = 1);
        }
        if (col > 1 && Roads[row][col - 1] && !Vis[row][col - 1])
        {
            if (Grid[row][col - 1] == 1)
                res++;
            dfs(row, col - 1, road = 1);
        }
        if (col < n && Roads[row][col + 1] && !Vis[row][col + 1])
        {
            if (Grid[row][col + 1] == 1)
                res++;
            dfs(row, col + 1, road = 1);
        }
    }
}
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("countcross.in"), fout.open("countcross.out");
    int k, r, a, b, c, d;
    fin >> n >> k >> r;
    for (int i = 0; i < r; i++)
    {
        fin >> a >> b >> c >> d;
        Roads[a][b] = 1, Roads[c][d] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        fin >> a >> b;
        Grid[a][b] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (Grid[i][j] == 1)
            {
                for (int k = 1; k <= n; k++)
                    for (int h = 1; h <= n; h++)
                        Vis[k][h] = 0;

                dfs(i, j, 0);
            }

    fout << res / 2;
    fin.close(), fout.close();
    return 0;
}