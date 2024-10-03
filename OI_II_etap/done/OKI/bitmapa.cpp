#include <bits/stdc++.h>

using namespace std;

constexpr int N = 200;
int Grid[N][N], Res[N][N];
bool Vis[N][N];

struct bitmapa
{
    int x, y, val;
};
struct ComparePair
{
    bool operator()(const bitmapa &p1, const bitmapa &p2)
    {
        return p1.val > p2.val;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    char a;
    priority_queue<bitmapa, vector<bitmapa>, ComparePair> pq;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            Res[i][j] = numeric_limits<int>::max();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a;
            Grid[i][j] = (a - '0') + 1;
            if (a == '1')
            {
                pq.push({i, j, 0});
                Res[i][j] = 0;
            }
        }

    while (!pq.empty())
    {
        bitmapa v = pq.top();
        pq.pop();
        if (!Vis[v.x][v.y])
        {
            if (Grid[v.x + 1][v.y] == 1 && Res[v.x + 1][v.y] > Res[v.x][v.y] + 1)
            {
                Res[v.x + 1][v.y] = Res[v.x][v.y] + 1;
                pq.push({v.x + 1, v.y, v.val + 1});
            }
            if (Grid[v.x - 1][v.y] == 1 && Res[v.x - 1][v.y] > Res[v.x][v.y] + 1)
            {
                Res[v.x - 1][v.y] = Res[v.x][v.y] + 1;
                pq.push({v.x - 1, v.y, v.val + 1});
            }
            if (Grid[v.x][v.y + 1] == 1 && Res[v.x][v.y + 1] > Res[v.x][v.y] + 1)
            {
                Res[v.x][v.y + 1] = Res[v.x][v.y] + 1;
                pq.push({v.x, v.y + 1, v.val + 1});
            }
            if (Grid[v.x][v.y - 1] == 1 && Res[v.x][v.y - 1] > Res[v.x][v.y] + 1)
            {
                Res[v.x][v.y - 1] = Res[v.x][v.y] + 1;
                pq.push({v.x, v.y - 1, v.val + 1});
            }

            Vis[v.x][v.y] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << Res[i][j] << " ";

        cout << "\n";
    }
    return 0;
}