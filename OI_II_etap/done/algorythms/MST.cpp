#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e5 + 10;
// kruskal
struct edge
{
    int start, end, weight;
};
edge E[M];
int R[M];
vector<edge> Tree[M];
inline int fint(int a)
{
    if (R[a] == a)
        return a;
    return R[a] = fint(R[a]);
}
inline void onion(int a, int b, int w)
{
    if (fint(R[a]) == fint(R[b]))
        return;
    R[b] = fint(R[a]);
    Tree[a].push_back({a, b, w});
    Tree[b].push_back({b, a, w});
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        R[i] = i;
    for (int i = 0; i < m; i++)
        cin >> E[i].start >> E[i].end >> E[i].weight;
    sort(E, E + m);
    for (int i = 0; i < m; i++)
        onion(E[i].start, E[i].end, E[i].weight);
    return 0;
}