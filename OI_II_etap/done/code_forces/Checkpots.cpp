#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MOD = 1e9 + 7, N = 1e5 + 10;
vector<int> adj[N], ReverseAdj[N];
bool Visisted[N];
int Spojna[N], r = 0;
stack<int> S;

inline void dfs1(int v)
{
    Visisted[v] = 1;
    for (int w : adj[v])
        if (!Visisted[w])
            dfs1(w);

    S.push(v);
}

inline void dfs2(int v)
{
    Spojna[v] = r;
    Visisted[v] = 1;
    for (int w : ReverseAdj[v])
        if (!Visisted[w])
            dfs2(w);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    vector<int> Cost(n + 1), MinCostSpojna(n + 1, numeric_limits<int>::max()), spojnaSize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> Cost[i];

    cin >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ReverseAdj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!Visisted[i])
            dfs1(i);

    for (int i = 0; i <= n; i++)
        Visisted[i] = 0;

    while (!S.empty())
    {
        int v = S.top();
        S.pop();
        if (!Visisted[v])
        {
            r++;
            dfs2(v);
        }
    }
    for (int i = 1; i <= n; i++)
        MinCostSpojna[Spojna[i]] = min(MinCostSpojna[Spojna[i]], Cost[i]);

    ll minCost = 0, combinations = 1;
    for (int i = 1; i <= n; i++)
    {
        if (MinCostSpojna[i] == numeric_limits<int>::max())
            continue;
        minCost += MinCostSpojna[i];
    }
    for (int i = 1; i <= n; i++)
        if (Cost[i] == MinCostSpojna[Spojna[i]])
            spojnaSize[Spojna[i]]++;
    for (int i = 1; i <= n; i++)
        if (spojnaSize[i] > 0)
        {
            combinations *= spojnaSize[i];
            combinations %= MOD;
        }

    cout << minCost << " " << combinations << '\n';

    return 0;
}