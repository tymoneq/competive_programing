#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

constexpr int N = 1010;

struct query
{
    int x, y;
    char type;
};

char Grid[N][N];
bool Vis[N][N];
int InCorect[N][N];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<query> Q(q);
    vector<int> Ans(q);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            Grid[i][j] = '?';
            InCorect[i][j] = -10;
        }

    for (auto &w : Q)
    {
        cin >> w.x >> w.y >> w.type;
        Grid[w.x][w.y] = w.type;
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!Vis[i][j] && Grid[i][j] != '?')
            {
                vector<pair<int, int>> v;
                set<pair<int, int>> vis;
                Vis[i][j] = 1;
                vis.insert({i, j});
                v.push_back({i, j});
                while (1)
                {
                    pair<int, int> w = v[v.size() - 1];
                    InCorect[w.first][w.second] = 0;
                    char type = Grid[w.first][w.second];
                    if (type == 'U')
                    {
                        if (w.first == 1 || InCorect[w.first - 1][w.second] == -1)
                        {
                            for (auto a : v)
                                InCorect[a.first][a.second] = -1;
                            break;
                        }

                        if (vis.count({w.first - 1, w.second}) || InCorect[w.first - 1][w.second] == 1)
                        {
                            for (auto a : v)
                                InCorect[a.first][a.second] = 1;

                            break;
                        }
                        else
                        {
                            vis.insert({w.first - 1, w.second});
                            Vis[w.first - 1][w.second] = 1;
                            v.push_back({w.first - 1, w.second});
                        }
                    }
                    else if (type == 'D')
                    {
                        if (w.first == n || InCorect[w.first + 1][w.second] == -1)
                        {
                            for (auto a : v)
                                InCorect[a.first][a.second] = -1;
                            break;
                        }

                        if (vis.count({w.first + 1, w.second}) || InCorect[w.first + 1][w.second] == 1)
                        {
                            for (auto a : v)
                                InCorect[a.first][a.second] = 1;

                            break;
                        }
                        else
                        {
                            vis.insert({w.first + 1, w.second});
                            Vis[w.first + 1][w.second] = 1;
                            v.push_back({w.first + 1, w.second});
                        }
                    }
                    else if (type == 'L')
                    {
                        if (w.second == 1 || InCorect[w.first][w.second - 1] == -1)
                        {
                            for (auto a : v)
                                InCorect[a.first][a.second] = -1;
                            break;
                        }

                        if (vis.count({w.first, w.second - 1}) || InCorect[w.first][w.second - 1] == 1)
                        {
                            for (auto a : v)
                                InCorect[a.first][a.second] = 1;

                            break;
                        }
                        else
                        {
                            vis.insert({w.first, w.second - 1});
                            Vis[w.first][w.second - 1] = 1;
                            v.push_back({w.first, w.second - 1});
                        }
                    }
                    else if (type == 'R')
                    {
                        if (w.second == n || InCorect[w.first][w.second + 1] == -1)
                        {
                            for (auto a : v)
                                InCorect[a.first][a.second] = -1;
                            break;
                        }
                        if (vis.count({w.first, w.second + 1}) || InCorect[w.first][w.second + 1] == 1)
                        {
                            for (auto a : v)
                                InCorect[a.first][a.second] = 1;

                            break;
                        }
                        else
                        {
                            vis.insert({w.first, w.second + 1});
                            Vis[w.first][w.second + 1] = 1;
                            v.push_back({w.first, w.second + 1});
                        }
                    }
                    else
                        break;
                }
            }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (Grid[i][j] == '?' && !Vis[i][j])
            {
                vector<pair<int, int>> v;
                Vis[i][j] = 1;
                queue<pair<int, int>> changeOrginal;
                queue<pair<int, int>> que;
                que.push({i, j});
                bool c = 0;

                while (!que.empty())
                {
                    auto w = que.front();
                    que.pop();
                    v.push_back(w);

                    if (w.first == 1 || w.first == n || w.second == 1 || w.second == n)
                        c = 1;
                    for (int k = 0; k < 4; k++)
                    {
                        if (w.first + dx[k] == 0 || w.first + dx[k] == n + 1 || w.second + dy[k] == 0 || w.second + dy[k] == n + 1)
                            continue;

                        if (InCorect[w.first + dx[k]][w.second + dy[k]] == 1)
                            continue;
                        if (InCorect[w.first + dx[k]][w.second + dy[k]] == 0)
                        {
                            changeOrginal.push({w.first + dx[k], w.second + dy[k]});
                            continue;
                        }
                        if (Vis[w.first + dx[k]][w.second + dy[k]] && Grid[w.first + dx[k]][w.second + dy[k]] != '?')
                        {
                            c = 1;
                            continue;
                        }
                        if (Vis[w.first + dx[k]][w.second + dy[k]])
                            continue;
                        Vis[w.first + dx[k]][w.second + dy[k]] = 1;
                        que.push({w.first + dx[k], w.second + dy[k]});
                    }
                }

                if (c)
                    continue;

                else
                {
                    for (auto w : v)
                        InCorect[w.first][w.second] = 1;

                    while (!changeOrginal.empty())
                    {
                        auto w = changeOrginal.front();
                        InCorect[w.first][w.second] = 1;
                        changeOrginal.pop();
                        for (int k = 0; k < 4; k++)
                            if (InCorect[w.first + dx[k]][w.second + dy[k]] == 0)
                            {
                                changeOrginal.push({w.first + dx[k], w.second + dy[k]});
                                InCorect[w.first + dx[k]][w.second + dy[k]] = 1;
                            }
                    }
                }
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (InCorect[i][j] == 0)
                InCorect[i][j] = 1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (InCorect[i][j] == 1)
                res++;

    for (int i = q - 1; i >= 0; i--)
    {
        Ans[i] = res;
        int cnt = 0;
        Grid[Q[i].x][Q[i].y] = '?';
        int sons = 0;
        for (int x = 0; x < 4; x++)
            if (InCorect[Q[i].x + dx[x]][Q[i].y + dy[x]] == 1)
                sons++;

        if (sons != 4 && InCorect[Q[i].x][Q[i].y] == 1)
        {
            queue<pair<int, int>> que;
            set<pair<int, int>> vis;
            vis.insert({Q[i].x, Q[i].y});
            que.push({Q[i].x, Q[i].y});

            while (!que.empty())
            {
                cnt++;
                auto w = que.front();
                InCorect[w.first][w.second] = -1;
                que.pop();
                for (int k = 0; k < 4; k++)
                {
                    if (w.first + dx[k] == 0 || w.first + dx[k] == n + 1 || w.second + dy[k] == 0 || w.second + dy[k] == n + 1)
                        continue;

                    if (vis.count({w.first + dx[k], w.second + dy[k]}) || InCorect[w.first + dx[k]][w.second + dy[k]] != 1)
                        continue;

                    if (Grid[w.first + dx[k]][w.second + dy[k]] == '?' && InCorect[w.first + dx[k]][w.second + dy[k]] == 1)
                    {
                        que.push({w.first + dx[k], w.second + dy[k]});
                        vis.insert({w.first + dx[k], w.second + dy[k]});
                    }
                }

                if (Grid[w.first][w.second - 1] == 'R' && InCorect[w.first][w.second - 1] == 1 && !vis.count({w.first, w.second - 1}))
                {
                    que.push({w.first, w.second - 1});
                    vis.insert({w.first, w.second - 1});
                }
                if (Grid[w.first][w.second + 1] == 'L' && InCorect[w.first][w.second + 1] == 1 && !vis.count({w.first, w.second + 1}))
                {
                    que.push({w.first, w.second + 1});
                    vis.insert({w.first, w.second + 1});
                }

                if (Grid[w.first - 1][w.second] == 'D' && InCorect[w.first - 1][w.second] == 1 && !vis.count({w.first - 1, w.second}))
                {
                    que.push({w.first - 1, w.second});
                    vis.insert({w.first - 1, w.second});
                }
                if (Grid[w.first + 1][w.second] == 'U' && InCorect[w.first + 1][w.second] == 1 && !vis.count({w.first + 1, w.second}))
                {
                    que.push({w.first + 1, w.second});
                    vis.insert({w.first + 1, w.second});
                }
            }
        }

        res -= cnt;
    }

    for (int i = 0; i < q; i++)
        cout << max(Ans[i], 0) << '\n';

    return 0;
}
