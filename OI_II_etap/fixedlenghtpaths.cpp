#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int M = 2e5 + 10, INF = 2e5;
vector<int> Tree[M];
int Sajz[M], n;
bool Off[M];
void dfs(int v, int p)
{
    Sajz[v] = 1;
    for (int w : Tree[v])
        if (w != p && !Off[w])
        {
            dfs(w, v);
            Sajz[v] += Sajz[w];
        }
}
ll findingCentroid(int v)
{
    bool fint = 0;
    dfs(v, v);
    ll centroid = v;
    while (!fint)
    {
        fint = 1;
        for (int w : Tree[centroid])
        {
            if (Sajz[w] > n / 2)
            {
                fint = 0;
                Sajz[centroid] -= Sajz[w];
                centroid = w;
                break;
            }
            if (Sajz[w] == n / 2)
            {
                centroid += w * INF;
                break;
            }
        }
    }
    return centroid;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, a, b;
    // (n-1) / 2*n
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    ll tmp = findingCentroid(1);
    return 0;
}