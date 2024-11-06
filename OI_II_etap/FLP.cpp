#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

vector<vector<int>> adj;
vector<bool> IsOff;
vector<int> Sajz, Parent;
map<int, int> M;
int k;
ull res = 0;

inline void dfs1(int v, int p)
{
    Parent[v] = p;
    Sajz[v] = 1;

    for (int w : adj[v])
        if (w != p && !IsOff[w])
        {
            dfs1(w, v);
            Sajz[v] += Sajz[w];
        }
}

inline int fintCentroid(int v, int treeSajz)
{
    for (int w : adj[v])
    {
        if (IsOff[w])
            continue;
        if (w == Parent[v] && (Sajz[w] - Sajz[v] > (treeSajz + 1) / 2))
            return fintCentroid(w, treeSajz);

        else if (w != Parent[v] && (Sajz[w] > (treeSajz + 1) / 2))
            return fintCentroid(w, treeSajz);
    }

    return v;
}

inline void calcdfs(int v, int p, int d)
{
    if (M.find(k - d) != M.end())
        res += M[k - d];

    for (int w : adj[v])
        if (w != p && !IsOff[w] && d <= k)
            calcdfs(w, v, d + 1);
}

inline void uptdfs(int v, int p, int d)
{
    M[d]++;

    for (int w : adj[v])
        if (w != p && !IsOff[w] && d <= k)
            uptdfs(w, v, d + 1);
}

inline void CentroidDecomposition(int n, int treeSajz)
{
    if (treeSajz == 1)
        return;
    dfs1(n, n);

    int centroid = fintCentroid(n, treeSajz);
    M.clear();
    M[0]++;

    for (int w : adj[centroid])
    {
        if (IsOff[w])
            continue;

        calcdfs(centroid, centroid, 1);
        uptdfs(centroid, centroid, 1);
    }
    IsOff[centroid] = 1;

    for (int w : adj[n])
    {
        if (IsOff[w])
            continue;

        int new_size = (Parent[n] == w ? Sajz[w] - Sajz[n] : Sajz[w]);
        CentroidDecomposition(w, new_size);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n >> k;

    adj.resize(n + 1);
    IsOff.resize(n + 1);
    Sajz.resize(n + 1);
    Parent.resize(n + 1);

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    CentroidDecomposition(1, n);
    cout << res - 1 << "\n";
    return 0;
}