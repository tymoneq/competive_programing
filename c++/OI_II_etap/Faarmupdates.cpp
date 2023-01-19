#include <bits/stdc++.h>
using namespace std;
struct LOG
{
    char oper;
    int FarmA, FarmB;
};
constexpr int M = 1e5 + 10;
bool Vis[M], Fint[M];
LOG Log[2 * M];
pair<int, int> Roads[M * 2];
set<int> Graph[M];
set<int> Activ;
int q;
bool is_active;
int Res[M];
inline void dfs(int v)
{
    Vis[v] = 1;
    Res[v] = max(Res[v], q);
    Fint[v] = 1;
    for (int w : Graph[v])
        if (!Vis[w] && !Fint[w])
            dfs(w);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, Q, a, b, road = 1;
    char oper;
    cin >> n >> Q;
    for (int i = 1; i <= n; i++)
        Activ.insert(i);
    for (int i = 1; i <= Q; i++)
    {
        cin >> oper;
        if (oper == 'A')
        {
            cin >> a >> b;
            Roads[road].first = a, Roads[road].second = b;
            road++;
            Graph[a].insert(b);
            Graph[b].insert(a);
        }
        else if (oper == 'D')
        {
            cin >> a;
            Activ.erase(a);
        }
        else if (oper == 'R')
        {
            cin >> a;
            Graph[Roads[a].first].erase(Roads[a].second);
            Graph[Roads[a].second].erase(Roads[a].first);
        }
        Log[i] = {oper, a, b};
    }
    q = Q;
    for (auto el : Activ)
        if (!Vis[el])
        {
            dfs(el);
        }

    for (int i = 1; i <= n; i++)
        Vis[i] = 0;
    LOG loG;
    pair<int, int> R;
    q--;
    while (q > 0)
    {
        loG = Log[q + 1];
        if (loG.oper == 'D')
        {
            dfs(loG.FarmA);
            for (int i = 1; i <= n; i++)
                Vis[i] = 0;
        }
        else if (loG.oper == 'R')
        {
            R = Roads[loG.FarmA];
            Graph[R.first].insert(R.second);
            Graph[R.second].insert(R.first);
            if (Fint[R.first] && !Fint[R.second])
            {
                Res[R.second] = max(q, Res[R.second]);
                Fint[R.second] = 1;
            }
            if (Fint[R.second] && !Fint[R.first])
            {
                Res[R.first] = max(q, Res[R.first]);
                Fint[R.first] = 1;
            }
        }
        else if (loG.oper == 'A')
        {
            Graph[loG.FarmA].erase(loG.FarmB);
            Graph[loG.FarmB].erase(loG.FarmA);
        }
        q--;
    }
    for (int i = 1; i <= n; i++)
        cout << Res[i] << "\n";
    return 0;
}