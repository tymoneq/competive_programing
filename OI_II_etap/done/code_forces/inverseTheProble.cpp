#include <bits/stdc++.h>

using namespace std;
constexpr long long INF = 1e15;
constexpr int M = 2010;
struct edge
{
    long long weight, start, end;
};

long long Matrix[M][M], R[M], Pre[M], Post[M], timer;
long long Dist[M][M];
bool Vis[M];
vector<edge> E;
vector<pair<int, int>> adj[M];
inline bool sorto(edge &lhs, edge &rhs) { return lhs.weight < rhs.weight; }
inline int fint(int a)
{
    if (R[a] == a)
        return a;
    return R[a] = fint(R[a]);
}
void onion(int a, int b, int w)
{
    if (fint(R[a]) == fint(R[b]))
        return;
    R[fint(R[b])] = fint(R[a]);
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    bool corect = 1;
    for (int i = 0; i < n; i++)
    {
        R[i] = i;
        for (int j = 0; j < n; j++)
        {
            cin >> Matrix[i][j];
            if ((i == j && Matrix[i][j] != 0) || (i != j && Matrix[i][j] == 0))
                corect = 0;
            if (i != j)
                E.push_back({Matrix[i][j], i, j});
        }
    }

    sort(E.begin(), E.end(), sorto);
    for (auto w : E)
        onion(w.start, w.end, w.weight);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        Dist[i][i] = 0;
        q.push({i, i});
        while (!q.empty())
        {
            auto w = q.front();
            q.pop();
            for (auto v : adj[w.first])
                if (v.first != w.second)
                {
                    Dist[i][v.first] = Dist[i][w.first] + v.second;
                    q.push({v.first, w.first});
                }
        }
    }
    for (int i = 0; i < n; i++)
        if (corect)
            for (int j = 0; j < n; j++)
                if (Dist[i][j] != Matrix[i][j])
                {
                    corect = 0;
                    break;
                }
    cout << (corect ? "YES" : "NO");
    return 0;
}