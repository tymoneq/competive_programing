#include <bits/stdc++.h>
using namespace std;

#warning change N = 210;
constexpr int N = 210, M = 5e4;

int STATE1[4] = {2, 3, 0, 1};
int STATE2[4] = {3, 2, 1, 0};
char Grid[N][N];
vector<pair<int, int>> adj[M][4]; // 0- up -1 down 2- left 3-right
bool Vis[M][4];
int Number[N][N];
set<int> vis;
vector<pair<int, int>> mirrors;
set<pair<char, int>> res;

inline void dfs(int v, int state)
{
    Vis[v][state] = 1;
    vis.insert(v);
    int newState;
    char type = Grid[mirrors[v].first][mirrors[v].second];
    if (type == '\\')
        newState = STATE2[state];

    else
        newState = STATE1[state];

    for (auto w : adj[v][newState])
        if (!Vis[w.first][w.second])
            dfs(w.first, w.second);

    for (auto w : adj[v][state])
        if (!Vis[w.first][w.second])
            dfs(w.first, w.second);

    return;
}
inline void get_res(int v, int state)
{
    Vis[v][state] = 1;
    for (auto w : adj[v][state])
        if (!Vis[w.first][w.second])
            get_res(w.first, w.second);

    int newState;
    char type = Grid[mirrors[v].first][mirrors[v].second];
    if (type == '\\')
        newState = STATE2[state];

    else
        newState = STATE1[state];

    for (auto w : adj[v][newState])
        if (!Vis[w.first][w.second])
            get_res(w.first, w.second);

    if (type == '\\')
    {
        if (state == 0 && adj[v][3].size() == 0)
            res.insert({'E', mirrors[v].first});

        else if (state == 1 && adj[v][2].size() == 0)
            res.insert({'W', mirrors[v].first});

        else if (state == 2 && adj[v][1].size() == 0)
            res.insert({'S', mirrors[v].second});

        else if (state == 3 && adj[v][0].size() == 0)
            res.insert({'N', mirrors[v].second});
    }
    else
    {
        if (state == 0 && adj[v][2].size() == 0)
            res.insert({'W', mirrors[v].first});

        else if (state == 1 && adj[v][3].size() == 0)
            res.insert({'E', mirrors[v].first});

        else if (state == 2 && adj[v][0].size() == 0)
            res.insert({'N', mirrors[v].second});

        else if (state == 3 && adj[v][1].size() == 0)
            res.insert({'S', mirrors[v].second});
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int R, C;
    cin >> R >> C;
    mirrors.push_back({0, 0});

    int cnt = 0;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {

            cin >> Grid[i][j];
            if (Grid[i][j] == '\\' || Grid[i][j] == '/')
            {
                cnt++;
                Number[i][j] = cnt;
                mirrors.push_back({i, j});
            }
        }

    // greating a graph
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {
            if (Grid[i][j] == '.')
                continue;

            for (int k = i - 1; k > 0; k--)
            {
                if (Number[k][j] != 0)
                {
                    adj[Number[k][j]][1].push_back({Number[i][j], 0});
                    adj[Number[i][j]][0].push_back({Number[k][j], 1});
                    break;
                }
            }

            for (int k = i + 1; k <= R; k++)
            {
                if (Number[k][j] != 0)
                {
                    adj[Number[k][j]][0].push_back({Number[i][j], 1});
                    adj[Number[i][j]][1].push_back({Number[k][j], 0});
                    break;
                }
            }

            for (int k = j - 1; k > 0; k--)
            {
                if (Number[i][k] != 0)
                {
                    adj[Number[i][k]][3].push_back({Number[i][j], 2});
                    adj[Number[i][j]][2].push_back({Number[i][k], 3});
                    break;
                }
            }

            for (int k = j + 1; k <= C; k++)
            {
                if (Number[i][k] != 0)
                {
                    adj[Number[i][k]][2].push_back({Number[i][j], 3});
                    adj[Number[i][j]][3].push_back({Number[i][k], 2});
                    break;
                }
            }
        }

    bool T = 0;
    vector<int> state;
    for (int i = 0; i < 4; i++)
    {
        vis.clear();
        dfs(1, i);
        if ((int)vis.size() == cnt)
        {
            T = 1;
            state.push_back(i);
        }

        for (int j = 0; j <= cnt; j++)
            for (int k = 0; k < 4; k++)
                Vis[j][k] = 0;
    }

    if (!T)
    {
        cout << 0 << '\n';
        return 0;
    }

    for (int w : state)
    {
        get_res(1, w);
        for (int j = 0; j <= cnt; j++)
            for (int k = 0; k < 4; k++)
                Vis[j][k] = 0;
    }

    cout << res.size() << '\n';

    for (auto row : res)
        cout << row.first << row.second << ' ';

    cout << '\n';
    return 0;
}