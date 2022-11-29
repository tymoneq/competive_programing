#include <bits/stdc++.h>
using namespace std;

void kalk_dist(vector<vector<int>> &Matrix, vector<vector<int>> &Dist, vector<vector<bool>> &visit, int n, int m, int x, int y)
{
    if (x != 0 && Matrix[x - 1][y] == 0 && !visit[x - 1][y])
    {
        Dist[x - 1][y] = Dist[x][y] + 1;
        visit[x - 1][y] = 1;
        x -= 1;
        kalk_dist(Matrix, Dist, visit, n, m, x, y);
    }
    if (x != n - 1 && Matrix[x + 1][y] == 0 && !visit[x + 1][y])
    {
        Dist[x + 1][y] = Dist[x][y] + 1;
        visit[x + 1][y] = 1;
        x += 1;
        kalk_dist(Matrix, Dist, visit, n, m, x, y);
    }
    if (y != 0 && Matrix[x][y - 1] == 0 && !visit[x][y - 1])
    {
        Dist[x][y - 1] = Dist[x][y] + 1;
        visit[x][y - 1] = 1;
        y -= 1;
        kalk_dist(Matrix, Dist, visit, n, m, x, y);
    }
    if (y != m - 1 && Matrix[x][y + 1] == 0 && !visit[x][y + 1])
    {
        Dist[x][y + 1] = Dist[x][y] + 1;
        visit[x][y + 1] = 1;
        y += 1;
        kalk_dist(Matrix, Dist, visit, n, m, x, y);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Matrix(n, vector<int>(m));
    vector<vector<int>> Dist(n, vector<int>(m)); // # krawędz . droga W start
    vector<vector<bool>> visit(n, vector<bool>(m));
    char tmp;
    pair<int, int> Start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            if (tmp == '#')
                Matrix[i][j] = -1;

            if (tmp == '.')
                Matrix[i][j] == 0;
            if (tmp == 'W')
            {
                Matrix[i][j] == 1;
                Start.first = i;
                Start.second = j;
            }
        }
    }
    kalk_dist(Matrix, Dist, visit, n, m, Start.first, Start.second);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << Dist[i][j] << " ";
        cout << "\n";
    }
    return 0;
}