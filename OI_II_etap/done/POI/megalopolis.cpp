#include <bits/stdc++.h>

using namespace std;

constexpr int BASE = 1 << 19, N = 2.5e5 + 10;

int Tree[BASE << 1], depth[N], timer = 1;
vector<int> adj[N];
map<int, pair<int, int>> M;

inline void dfs(int v, int p)
{

    M[v].first = timer;
    ++timer;
    depth[v] = depth[p] + 1;

    for (int w : adj[v])
        if (w != p)
            dfs(w, v);

    M[v].second = timer;
    ++timer;
}

inline int calc(int city)
{
    int res = depth[city];
    int l = 0 + BASE, r = M[city].first + BASE + 1;
    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            res -= Tree[l + 1];
        if (r % 2 == 1)
            res -= Tree[r - 1];

        l /= 2, r /= 2;
    }
    return res;
}

inline void path_upt(int v)
{
    v /= 2;
    while (v > 0)
    {
        Tree[v] = Tree[v * 2] + Tree[2 * v + 1];
        v /= 2;
    }
}

inline void upt(int cityA, int cityB)
{
    if (depth[cityA] < depth[cityB])
        swap(cityA, cityB);
    Tree[M[cityA].first + BASE] += 1;
    Tree[M[cityA].second + BASE] -= 1;
    path_upt(M[cityA].first + BASE);
    path_upt(M[cityA].second + BASE);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;
    char c;
    cin >> n;
    depth[0] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> m;
    dfs(1, 0);

    for (int i = 0; i < m + n - 1; i++)
    {
        cin >> c;
        if (c == 'A')
        {
            cin >> a >> b;
            upt(a, b);
        }

        else
        {
            cin >> a;
            if (a == 1)
                cout << 0 << "\n";
            else
                cout << calc(a) << "\n";
        }
    }

    return 0;
}