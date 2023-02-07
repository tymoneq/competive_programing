#include <bits/stdc++.h>

using namespace std;
constexpr long long INF = 1e15;
constexpr int M = 2010;
struct edge
{
    int weight, start, end;
};

int Matrix[M][M], R[M];
vector<edge> E;
long long Dist[M][M];
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
    Dist[a][b] = Dist[b][a] = w;
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

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (Dist[i][j] != Matrix[i][j])
            {
                corect = 0;
                break;
            }
    cout << (corect ? "YES" : "NO");
    return 0;
}