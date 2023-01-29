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
        if (val != 0)
            return;
        if (Visited[w] && w != f)
        {
            val = w;
            return;
        }
        if (!Visited[w])
            dfs(w, v);
    }
    if (val == 0)
    {
        auto itr = res.end();
        itr--;
        res.erase(itr);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, k = 0;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (Visited[i])
            continue;
        val = 0;
        dfs(i, i);
        if (val == 0)
            res.clear();
        else
        {
            for (unsigned long long j = 0; j < res.size(); j++)
                if (res[j] == val)
                {
                    k = j;
                    break;
                }
            cout << res.size() - k + 1 << "\n";
            for (unsigned long long j = k; j < res.size(); j++)
                cout << res[j] << " ";
            cout << val;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}