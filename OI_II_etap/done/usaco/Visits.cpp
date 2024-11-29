#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 1e5 + 10;
bool Vis[N];
int SCC[N], Reward[N], r, MNRewardSCC[N], SCCsize[N];
vector<int> adj[N], adj2[N];
stack<int> S;

inline void setVis()
{
    for (int i = 0; i < N; i++)
        Vis[i] = 0;
}

inline void dfs(int v)
{
    Vis[v] = 1;
    for (int w : adj[v])
        if (!Vis[w])
            dfs(w);

    S.push(v);
}
inline void dfs2(int v)
{
    Vis[v] = 1;
    SCC[v] = r;
    SCCsize[r]++;
    for (int w : adj2[v])
        if (!Vis[w])
            dfs2(w);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll res = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a >> Reward[i];
        adj[i].push_back(a);
        adj2[a].push_back(i);
    }

    for (int i = 1; i <= n; i++)
        if (!Vis[i])
            dfs(i);

    setVis();
    while (!S.empty())
    {
        int v = S.top();
        S.pop();
        if (Vis[v])
            continue;
        r++;
        dfs2(v);
    }

    for (int i = 1; i <= r; i++)
        MNRewardSCC[i] = numeric_limits<int>::max();

    for (int i = 1; i <= n; i++)
    {
        if (SCCsize[SCC[i]] == 1)
            continue;

        MNRewardSCC[SCC[i]] = min(MNRewardSCC[SCC[i]], Reward[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (SCCsize[SCC[i] == 1] && adj[i][0] == i)
            continue;
        res += Reward[i];
    }
    for (int i = 1; i <= r; i++)
        if (MNRewardSCC[i] != numeric_limits<int>::max())
            res -= MNRewardSCC[i];

    cout << res << '\n';

    return 0;
}