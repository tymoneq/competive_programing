#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 10;
bool Vis[N];
vector<int> adj[N], adj2[N];
int RES[N], r;

stack<int> S;

inline void SetVis()
{
    for (int i = 1; i < N; i++)
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
inline void dfs2(int v, vector<int> &V)
{
    Vis[v] = 1;
    V.push_back(v);
    for (int w : adj2[v])
        if (!Vis[w])
            dfs2(w, V);
}
inline void calc(int v)
{
    Vis[v] = 1;
    r++;
    for (int w : adj[v])
        if (!Vis[w])
            calc(w);

    RES[v] = r;
}
inline void calc1(int v, int cost)
{
    Vis[v] = 1;
    r++;
    for (int w : adj[v])
    {
        if (!Vis[w])
            calc1(w, cost + 1);
        else if (Vis[w])
        {
            r += RES[w];
            break;
        }
    }
    RES[v] = r - cost;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        adj[i].push_back(a);
        adj2[a].push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (Vis[i])
            continue;
        dfs(i);
    }

    SetVis();
    vector<vector<int>> Spojne;

    while (!S.empty())
    {
        int v = S.top();
        S.pop();
        if (Vis[v])
            continue;

        vector<int> A;
        dfs2(v, A);
        Spojne.push_back(A);
    }

    SetVis();
    for (auto el : Spojne)
    {
        if (el.size() == 1)
            continue;
        r = 0;
        calc(el[0]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (Vis[i])
            continue;
        r = 0;
        calc1(i, 0);
    }

    for (int i = 1; i <= n; i++)
        cout << RES[i] << " ";
    cout << '\n';
    return 0;
}