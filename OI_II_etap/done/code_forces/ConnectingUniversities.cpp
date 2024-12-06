#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

constexpr int N = 2e5 + 10;
ll CNT[N], dp[N];
bool Uni[N];
vector<int> adj[N];

inline void dfs(int v, int p)
{
    if (Uni[v])
        CNT[v]++;

    for (int w : adj[v])
        if (w != p)
        {
            dfs(w, v);
            CNT[v] += CNT[w];
        }

    return;
}

inline int fintCentroid(int v, int p, int treeSajz)
{

    for (auto w : adj[v])
    {
        if (w == p && CNT[w] - CNT[v] > treeSajz / 2)
            return fintCentroid(w, v, treeSajz);
        else if (w != p && CNT[w] > treeSajz / 2)
            return fintCentroid(w, v, treeSajz);
    }
    return v;
}

inline void dfs2(int v, int p)
{
    CNT[v] = 0;
    if (Uni[v])
        CNT[v]++;

    for (int w : adj[v])
        if (w != p)
        {
            dfs2(w, v);
            CNT[v] += CNT[w];
            dp[v] += CNT[w] + dp[w];
        }

    return;
}
inline ll calc(int v, int p, int n)
{
    dfs(v, p);
    int centr = fintCentroid(v, 0, n);

    dfs2(centr, centr);

    return dp[centr];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k * 2; i++)
    {
        int a;
        cin >> a;
        Uni[a] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << calc(1, 1, 2 * k) << '\n';

    return 0;
}