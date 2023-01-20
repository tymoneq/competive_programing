#include <bits/stdc++.h>

using namespace std;
const int M = 2e5 + 10;
vector<int> Graph[M];
bool Vis[M];
bool off[M];
inline void dfs(int v)
{
    Vis[v] = 1;
    for (int w : Graph[v])
        if (!Vis[w] && !off[w])
            dfs(w);
}
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);
    fin.open("closing.in"), fout.open("closing.out");
    int n, m, a, b;
    fin >> n >> m;
    set<int> Activ;
    for (int i = 1; i <= n; i++)
        Activ.insert(i);
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    bool fint = 1;
    for (int i = 0; i < n; i++)
    {
        dfs(*(Activ.begin()));
        for (int j = 1; j <= n; j++)
        {
            if (!Vis[j] && !off[j])
                fint = 0;
            Vis[j] = 0;
        }
        if (fint)
            fout << "YES\n";
        else
            fout << "NO\n";
        fin >> a;
        off[a] = 1;
        fint = 1;
        Activ.erase(a);
    }

    fin >> a;
    fin.close(), fout.close();
    return 0;
}