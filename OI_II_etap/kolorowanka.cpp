#include <bits/stdc++.h>

using namespace std;

constexpr int N = 10;

vector<int> adj[N];
int Parent[N], Sajz[N];
bool Vis[N];

inline void dfs2(int v)
{
    stack<int> s;
    Vis[v] = 1;
    Sajz[v] = 0;
    s.push(v);
    while (!s.empty())
    {
        int w = s.top();
        s.pop();
        for (int k : adj[w])
            if (!Vis[k])
            {
                s.push(k);
                Sajz[k] = Sajz[w] + 1;
                Vis[k] = 1;
            }
    }
}

inline void dfs1(int v, int p)
{
    Sajz[v] = 1;
    Parent[v] = p;
    for (int w : adj[v])
        if (w != p)
        {
            dfs1(w, v);
            Sajz[v] += Sajz[w];
        }
}

inline int findCentroid(int v, int tree_sajz)
{
    for (int w : adj[v])
    {
        if (w == Parent[v] && tree_sajz - Sajz[v] > ((tree_sajz + 1) / 2))
            return findCentroid(Parent[v], tree_sajz);
        else if (w != Parent[v] && Sajz[w] > (((tree_sajz + 1) / 2)))
            return findCentroid(w, tree_sajz);
    }

    return v;
}
inline int checkSecondCentroid(int v, int tree_sajz)
{

    int ans = -1;
    for (int w : adj[v])
    {
        if (w == Parent[v] && tree_sajz - Sajz[v] >= ((tree_sajz + 1) / 2))
            ans = w;
        else if (w != Parent[v] && Sajz[w] >= (((tree_sajz + 1) / 2)))
            ans = w;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q, a, b;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    int centroid = findCentroid(1, n);
    int centroid2 = checkSecondCentroid(centroid, n);

    if (centroid2 != -1)
    {
        adj[centroid].push_back(0);
        adj[centroid2].push_back(0);
        adj[0].push_back(centroid);
        adj[0].push_back(centroid2);
        centroid = 0;
    }

    for (int i = 0; i <= n; i++)
        Sajz[i] = 0;

    dfs2(centroid);

    for (int i = 0; i <= n; i++)
        cout << Sajz[i] << "\n";

    return 0;
}