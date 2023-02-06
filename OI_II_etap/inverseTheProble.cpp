#include <bits/stdc++.h>

using namespace std;
constexpr long long INF = 1e15;
constexpr int M = 2010;
struct edge
{
    int weight, start, end;
};

int Matrix[M][M], R[M], Pre[M], Post[M], timer;
long long Dist[M][M];
bool Vis[M];
vector<edge> E;
vector<pair<int, int>> adj[M];
inline bool sorto(edge &lhs, edge &rhs) { return lhs.weight < rhs.weight; }
inline void dfs(int v, int p)
{
    timer++;
    Pre[v] = timer;
    for (auto w : adj[v])
        if (w.first != p)
            dfs(w.first, v);
    timer++;
    Post[v] = timer;
}
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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                Dist[i][j] = 0;
            else
                Dist[i][j] = INF;
        }
    for (auto w : E)
        onion(w.start, w.end, w.weight);

    dfs(0, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto w = pq.top();
        pq.pop();
        if (!Vis[w.second])
            for (auto v : adj[w.second])
                if (Dist[0][v.first] > Dist[0][w.second] + v.second)
                {
                    Dist[0][v.first] = Dist[0][w.second] + v.second;
                    pq.push({Dist[0][v.first], v.first});
                }

        Vis[w.second] = 1;
    }
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                Dist[i][j] = 0;
            else
            {
                if ((Pre[i] < Pre[j] && Post[i] > Post[j]) || (Pre[i] > Pre[j] && Post[i] < Post[j]))
                    Dist[i][j] = abs(Dist[0][i] - Dist[0][j]);
                else
                    Dist[i][j] = Dist[0][i] + Dist[0][j];
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