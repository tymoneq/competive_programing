#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 1010;

set<int> adj[N];
bool Vis[N][N];
int EdgesUsed[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    ll res = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(b);
    }
    res = (n * (n - 1) * (n - 2)) / 6;
    for (int i = 1; i <= n; i++)
    {
        int j = n - 2 - EdgesUsed[i];
        for (int e : adj[i])
        {
            if (j > 0)
            {
                res -= j;
                j--;
            }
            EdgesUsed[e]++;
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     queue<pair<int, int>> q;
    //     q.push({i, i});
    //     Vis[i][i] = 1;
    //     vector<int> d(n + 1, 0);
    //     while (!q.empty())
    //     {
    //         auto v = q.front();
    //         q.pop();
    //         for (int w : adj[v.first])
    //             if (w > i)
    //             {
    //                 if (!Vis[i][w])
    //                 {
    //                     Vis[i][w] = 1;
    //                     d[w] = d[i] + 1;
    //                     if (d[w] < 2)
    //                         q.push({w, v.first});
    //                 }
    //                 else if (Vis[i][w] && w != v.second)
    //                     res++;
    //             }
    //     }
    // }

    cout << res << "\n";
    return 0;
}