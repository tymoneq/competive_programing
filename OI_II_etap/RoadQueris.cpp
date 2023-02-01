#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e5+10;
struct edge
{
    int start, end, val;
};

int R[M], Dist[M];
bool Vis[M];
edge E[M];
vector<pair<int, int>> Mst[M];
inline int fint(int a)
{
    if (R[a] == a)
        return a;
    return R[a] = fint(R[a]);
}
inline void onion(int a, int b, int val)
{
    if (fint(a) == fint(b))
        return;
    R[fint(b)] = fint(a);
    Mst[b].push_back({a, val});
    Mst[a].push_back({b, val});
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q, a, b;
    cin >> n >> m >> q;
    for (int i = 0; i <= n; i++)
        R[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> E[i].start >> E[i].end;
        E[i].val = i + 1;
    }
    for (int i = 0; i < m; i++)
        onion(E[i].start, E[i].end, E[i].val);
    queue<int> Q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        if (fint(R[a]) != fint(R[b]))
            cout << -1 << "\n";
        else
        {
            Q.push(a);
            for (int j = 0; j <= n; j++)
                Dist[j] = -1000, Vis[j] = 0;
            while (!Q.empty())
            {
                auto v = Q.front();
                Q.pop();
                for (auto w : Mst[v])
                    if (!Vis[w.first])
                    {
                        Dist[w.first] = max(Dist[v], w.second);
                        Q.push(w.first);
                        Vis[w.first] = 1;
                    }
            }
            cout << Dist[b] << "\n";
        }
    }
    return 0;
}