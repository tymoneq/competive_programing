#include <bits/stdc++.h>

using namespace std;

constexpr int N = 127;

struct Pepe
{
    int x, y, z; // Format is [z][y][x]
};

struct Point
{
    int val, z, y, x;
};

struct elev
{
    int c, d;
    bool used = 0;
};

struct ComparePair
{
    bool operator()(const Point &p1, const Point &p2)
    {
        return p1.val > p2.val;
    }
};

int Grid[N][N][N], Ans[N][N][N];
bool Vis[N][N][N];
elev Elevators[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y, z, m, a, b, c, d;
    Pepe pepe, dunder;
    char C;
    cin >> x >> y >> z;
    for (int i = 1; i <= z; i++)
        for (int j = y; j > 0; j--)
            for (int k = 1; k <= x; k++)
            {
                cin >> C;
                if (C == 'O')
                    Grid[i][j][k] = 1;
            }
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c >> d;
        Elevators[b][a] = {c, d, 0};
    }
    cin >> pepe.x >> pepe.y >> pepe.z;
    cin >> dunder.x >> dunder.y >> dunder.z;

    for (int i = 1; i <= z; i++)
        for (int j = 1; j <= y; j++)
            for (int k = 1; k <= x; k++)
                Ans[i][j][k] = numeric_limits<int>::max();

    priority_queue<Point, vector<Point>, ComparePair> pq;
    Ans[dunder.z][dunder.y][dunder.x] = 0;
    pq.push({0, dunder.z, dunder.y, dunder.x});

    while (!pq.empty())
    {
        auto u = pq.top();
        pq.pop();
        if (!Vis[u.z][u.y][u.x])
        {

            // sprawdzanie wind
            if (Elevators[u.y][u.x].c <= u.z && Elevators[u.y][u.x].d >= u.z && !Elevators[u.y][u.x].used)
            {
                for (int level = Elevators[u.y][u.x].c; level <= Elevators[u.y][u.x].d; level++)
                    if (Ans[level][u.y][u.x] > u.val && Grid[level][u.y][u.x] == 1)
                    {
                        Ans[level][u.y][u.x] = u.val;
                        pq.push({u.val, level, u.y, u.x});
                    }
                Elevators[u.y][u.x].used = 1;
            }

            // sprawdzanie pól obok
            if (Grid[u.z][u.y][u.x - 1] == 1 && Ans[u.z][u.y][u.x - 1] > u.val + 1)
            {
                Ans[u.z][u.y][u.x - 1] = u.val + 1;
                pq.push({u.val + 1, u.z, u.y, u.x - 1});
            }
            if (Grid[u.z][u.y][u.x + 1] == 1 && Ans[u.z][u.y][u.x + 1] > u.val + 1)
            {
                Ans[u.z][u.y][u.x + 1] = u.val + 1;
                pq.push({u.val + 1, u.z, u.y, u.x + 1});
            }

            if (Grid[u.z][u.y - 1][u.x] == 1 && Ans[u.z][u.y - 1][u.x] > u.val + 1)
            {
                Ans[u.z][u.y - 1][u.x] = u.val + 1;
                pq.push({u.val + 1, u.z, u.y - 1, u.x});
            }
            if (Grid[u.z][u.y + 1][u.x] == 1 && Ans[u.z][u.y + 1][u.x] > u.val + 1)
            {
                Ans[u.z][u.y + 1][u.x] = u.val + 1;
                pq.push({u.val + 1, u.z, u.y + 1, u.x});
            }

            Vis[u.z][u.y][u.x] = 1;
        }
    }

    if (Ans[pepe.z][pepe.y][pepe.x] == numeric_limits<int>::max())
        Ans[pepe.z][pepe.y][pepe.x] = -1;

    cout << Ans[pepe.z][pepe.y][pepe.x] << "\n";
    return 0;
}