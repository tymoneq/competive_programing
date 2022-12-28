#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
vector<int> Graph[M];
bool Visited[M];
vector<int> res;
int val;
void dfs(int v, int f)
{
    Visited[v] = 1;
    if (val == 0)
        res.push_back(v);
    if (val != 0)
        return;
    for (int w : Graph[v])
    {
        if (Visited[w] && w != f)
        {
            val = w;
            return;
        }

        if (!Visited[w])
            dfs(w, v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    dfs(1, 1);
    if (val == 0)
        cout << "IMPOSSIBLE";
    else
    {
        cout << res.size() + 1 << "\n";
        for (int e : res)
            cout << e << " ";
        cout << 1;
    }
    return 0;
}