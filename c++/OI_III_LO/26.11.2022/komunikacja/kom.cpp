#include <bits/stdc++.h>
using namespace std;

void dfs(int &v, vector<bool> &visited, vector<vector<int>> &G, vector<bool> &All_visit)
{
    visited[v] = 1;
    All_visit[v] = 1;
    for (int b : G[v])
        if (!visited[b])
            dfs(b, visited, G, All_visit);
}

bool connect(vector<vector<int>> &G, int &v, int &n, vector<vector<int>> &res, vector<bool> &al_visit)
{
    vector<bool> visited(n + 1);
    dfs(v, visited, G, al_visit);
    v = 0;
    vector<int> G_res;
    bool conect = true;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            G_res.push_back(i);
        else if (!al_visit[i])
        {
            conect = false;
            v = i;
        }
    }
    res.push_back(G_res);
    return conect;
}
inline bool sorto(vector<int> &lhs, vector<int> &rhs) { return lhs.size() >= rhs.size(); }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> Graph(n + 1);
    vector<vector<int>> res;
    vector<bool> all_visit(n + 1);
    int next = 1;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    bool conect = connect(Graph, next, n, res, all_visit);
    if (conect)
    {
        long long wynik = 0;
        for (int i = n - 1; i > 0; i--)
            wynik += i;
        cout << wynik;
    }
    else
    {
        long long wynik = 0;
        while (next != 0)
        {
            conect = connect(Graph, next, n, res, all_visit);
        }
        sort(res.begin(), res.end(), sorto);
        for (int i = k + 1; i < res.size(); i++)
            wynik += res[i].size()/2;
        long long tmp = 0;
        for (int i = 0; i < k + 1; i++)
            tmp += res[i].size();
        for (int i = tmp-1; i > 0; i--)
            wynik += i;
        cout << wynik;
    }
    return 0;
}