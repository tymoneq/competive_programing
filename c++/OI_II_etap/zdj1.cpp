#include <bits/stdc++.h>

using namespace std;

void photos(int &l, vector<vector<int>> &G, vector<pair<int, int>> &Photos, vector<bool> &Visited, int v, int n)
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
                photos(l, G, Photos, Visited, b, n);
            }
        }

        else if (b == 2 && Photos.size() == n - 1)
        {
            Photos.push_back(make_pair(n, 2));
            return;
        }
    }
}
// sprawdzenie czy graf jest spójny
void dfs(int V, vector<bool> &visited, vector<vector<int>> &G)
{
    visited[V] = 1;
    for (int b : G[V])
        if (!visited[b])
            dfs(b, visited, G);
}
bool connected_graph(int V, vector<bool> visited, vector<vector<int>> &G, vector<int> &Add_kras)
{
    dfs(V, visited, G);
    bool connect_G = true;
    for (int i = 1; i < visited.size(); i++)
        if (!visited[i])
        {
            Add_kras.push_back(i);
            connect_G = false;
        }
    return connect_G;
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
    vector<int> Add_kr;
    vector<bool> Visited(n + 1, 0);
    vector<pair<int, int>> Photos;
    int l = 1, N = n;
    auto connect_G = connected_graph(1, Visited, Graph, Add_kr);
    if (!connect_G)
        N -= Add_kr.size();
    photos(l, Graph, Photos, Visited, 1, N);
    if (Photos.size() == n)
    {
        cout << "TAK\n";
        sort(Photos.begin(), Photos.end(), sorto);
        for (auto el : Photos)
            cout << el.first << " ";
    }
    else if (!connect_G && Photos.size() + Add_kr.size() == n)
    {
        cout << "TAK\n";
        int tmp = 0;
        for (int i = Photos.size() + 1; i <= n; i++)
        {
            Photos.push_back(make_pair(i, Add_kr[tmp]));
            tmp += 1;
        }

        sort(Photos.begin(), Photos.end(), sorto);
        for (auto el : Photos)
            cout << el.first << " ";
    }
    else
        cout << "NIE";
    return 0;
}