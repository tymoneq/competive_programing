#include <bits/stdc++.h>

using namespace std;
const int M = 2e5 + 10;
vector<int> Graph[M];
bool Vis[M];
int r = 0;
vector<int> Ans[M];
inline void dfs(int v)
{
    Vis[v] = 1;
    Ans[r].push_back(v);
    for (int w : Graph[v])
        if (!Vis[w])
            dfs(w);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<set<int>> NoPath(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        NoPath[min(a, b)].insert(max(a, b));
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            if (!binary_search(NoPath[i].begin(), NoPath[i].end(), j))
            {

                Graph[i].push_back(j);
                Graph[j].push_back(i);
            }
    }
    for (int i = 1; i <= n; i++)
        if (!Vis[i])
        {
            r++;
            dfs(i);
        }
    vector<int> ans;
    for (int i = 1; i <= r; i++)
        ans.push_back(Ans[i].size());
    cout << r << "\n";
    sort(ans.begin(), ans.end());
    for (int w : ans)
        cout << w << ' ';
    return 0;
}