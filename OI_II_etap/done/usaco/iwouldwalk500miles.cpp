#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct edge
{
    ll weight;
    int start, end;
};

constexpr ll Mod = 2019201997, x = 2019201913, y = 2019201949, INF = 1e18;
inline bool sortEdge(edge &lhs, edge &rhs) { return lhs.weight < rhs.weight; }
constexpr int M = 7510;
int R[M], parts, Sajz[M];
ll MAP[M];
inline int fint(int a)
{
    if (R[a] == a)
        return a;
    return R[a] = fint(R[a]);
}
inline void onion(int a, int b)
{
    int fa = fint(a), fb = fint(b);
    if (fa == fb)
        return;
    Sajz[fb] += Sajz[fa];
    Sajz[fa] = 0;
    R[fa] = fb;
    parts--;
}
int main()
{
    // freopen("walk.in", "r", stdin);
    // freopen("walk.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<edge> E;
    parts = n;
    ll tmp;
    for (int i = 1; i <= n; i++)
    {
        R[i] = i;
        Sajz[i] = 1;
        for (int j = i + 1; j <= n; j++)
        {
            tmp = (x * i + y * j) % Mod;
            E.push_back({tmp, i, j});
        }
    }
    sort(E.begin(), E.end(), sortEdge);
    int ind = 0;
    while (parts > k)
    {
        onion(E[ind].start, E[ind].end);
        ind++;
    }
    for (int i = 1; i <= n; i++)
        MAP[i] = INF;
    ll mx = INF;
    for (int i = ind; i < E.size(); i++)
    {
        if (Sajz[E[i].start] != 1 && Sajz[E[i].end] != 1)
            continue;
        if (Sajz[E[i].start] != 1 && Sajz[E[i].end] == 1)
            MAP[E[i].end] = min(MAP[E[i].end], E[i].weight);

        if (Sajz[E[i].start] == 1 && Sajz[E[i].end] != 1)
            MAP[E[i].start] = min(MAP[E[i].start], E[i].weight);
        else
            mx = min(mx, E[i].weight);
    }
    for (int i = 1; i <= n; i++)
        if (MAP[i] != INF && Sajz[i] == 1)
            mx = min(mx, MAP[i]);
    cout << mx;
    return 0;
}