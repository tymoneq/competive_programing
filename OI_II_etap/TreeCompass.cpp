#include <bits/stdc++.h>
using namespace std;

inline void dfs(int v, int p, int d, vector<vector<int>> &adj, vector<set<int>> &mxDepth)
{
    mxDepth[v].insert(d);
    for (int w : adj[v])
        if (w != p)
        {
            dfs(w, v, d + 1, adj, mxDepth);
            for (int a : mxDepth[w])
                mxDepth[v].insert(a);
        }
}

inline void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    set<int> Ans;
    int indx = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<set<int>> mxDepth(n + 1);
        dfs(i, i, 0, adj, mxDepth);

        if (indx == 0)
        {
            indx = i;
            Ans = mxDepth[i];
        }
        else if (Ans.size() > mxDepth[i].size())
        {
            Ans = mxDepth[i];
            indx = i;
        }
    }
    cout << Ans.size() << '\n';

    for (int w : Ans)
        cout << indx << ' ' << w << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}