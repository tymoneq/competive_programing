#include <bits/stdc++.h>

using namespace std;
const int M = 1e5 + 10;
set<int> Graph[M];
bool Activ[M];
pair<int, int> Roads[2 * M];
int Res[M];
bool Vis[M];
int q;
bool is_active;
inline void dfs(int v)
{
    if (Activ[v])
        is_active = 1;
    Vis[v] = 1;
    for (auto w : Graph[v])
        if (!Vis[w])
            dfs(w);
    if (is_active)
        Res[v] = q;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, Q, a, b, tmp1, tmp2, road = 1;
    char task;
    cin >> n >> Q;
    for (int i = 1; i <= n; i++)
        Activ[i] = 1;
    for (q = 1; q <= Q; q++)
    {
        cin >> task;if (task == 'A')
        
        {
            cin >> a >> b;
            Roads[road].first = a, Roads[road].second = b;
            Graph[a].insert(b);
            Graph[b].insert(a);
            road++;
        }
        else if (task == 'D')
        {
            cin >> a;
            Activ[a] = 0;
        }
        else if (task == 'R')
        {
            cin >> a;
            tmp1 = Roads[a].first, tmp2 = Roads[a].second;
            Graph[tmp1].erase(tmp2), Graph[tmp2].erase(tmp1);
        }
        for (int j = 1; j <= n; j++)
            if (!Vis[j] && Activ[j])
            {
                is_active = 0;
                dfs(j);
            }
        for (int j = 1; j <= n; j++)
            Vis[j] = 0;
    }

    for (int i = 1; i <= n; i++)
        cout << Res[i] << "\n";
    return 0;
}