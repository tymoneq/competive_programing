#include <bits/stdc++.h>

using namespace std;

void dfs(int &l, vector<vector<int>> &G, vector<pair<int, int>> &Photos, vector<bool> &Visited, int v, int n)
{

    Photos.push_back(make_pair(l, v));
    Visited[v] = 1;

    for (int b : G[v])
    {
        if (!Visited[b] && b != 2 && G[b].size() <= l * 2) 
        {
            int vis = 0, not_vis = 0;
            for (int u : G[b])
                if (Visited[u] == 1)
                    vis += 1;
            not_vis = G[b].size() - vis;
            if (vis - not_vis == 0 && vis <= l)
            {
                l += 1;
                dfs(l, G, Photos, Visited, b, n);
            }
        }

        else if (b == 2 && Photos.size() == n - 1)
        {
            Photos.push_back(make_pair(n, 2));
            return;
        }
    }
}
inline bool sorto(pair<int, int> lhs, pair<int, int> rhs) { return lhs.second < rhs.second; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    vector<pair<int, int>> Photos;
    vector<bool> Visited(n + 1, 0);
    int l = 1;
    int licznik = 1;

    dfs(l, Graph, Photos, Visited, 1, n);
    if (Photos.size() == n)
    {
        cout << "TAK\n";
        sort(Photos.begin(), Photos.end(), sorto);
        for (auto el : Photos)
            cout << el.first << " ";
    }
    else
        cout << "NIE";
    return 0;
}