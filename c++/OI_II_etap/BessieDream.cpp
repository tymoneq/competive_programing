#include <bits/stdc++.h>

using namespace std;
int Grid[1010][1010];
int Dist[1010][1010];
bool Vis[1010][1010];
struct Move
{
    int x, y;
    bool orange;
};
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    int n, m;
    char z;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> z;
            Grid[i][j] = z - '0';
        }
    queue<Move> q;
    Vis[0][0] = 1;
    q.push({0, 0, 0});
    Dist[n - 1][m - 1] = numeric_limits<int>::max();
    Dist[0][0] = 0;
    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        if (v.x > 0 && !Vis[v.x - 1][v.y] && (Grid[v.x - 1][v.y] == 1 || Grid[v.x - 1][v.y] == 2 || (Grid[v.x - 1][v.y] == 3 && v.orange)))
        {
            Vis[v.x - 1][v.y] = 1;
        }
    }

    fin.close(), fout.close();
    return 0;
}