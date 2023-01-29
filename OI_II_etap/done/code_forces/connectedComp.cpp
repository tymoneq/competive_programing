#include <bits/stdc++.h>

using namespace std;
const int M = 2e5 + 10;
unordered_set<int> Graph[M];
set<int> unvis;
int r = 0;
int Ans[M];
inline void dfs(int v)
{
    Ans[r]++;
    auto it = unvis.begin();
    while (it != unvis.end())
    {
        if (Graph[v].count(*it))
            it++;
        else
        {
            unvis.erase(it);
            int last = *it;
            dfs(last);
            it = unvis.upper_bound(last);
        }
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
        a--, b--;
        Graph[a].insert(b);
        Graph[b].insert(a);
    }
    for (int i = 0; i < n; i++)
        unvis.insert(i);
    for (int i = 0; i < n; i++)
    {
        auto it = unvis.find(i);
        if (it != unvis.end())
        {
            unvis.erase(it);
            dfs(i);
            r++;
        }
    }
    cout << r << "\n";

    sort(Ans, Ans + r);
    for (int i = 0; i < r; i++)
        cout << Ans[i] << ' ';
    return 0;
}