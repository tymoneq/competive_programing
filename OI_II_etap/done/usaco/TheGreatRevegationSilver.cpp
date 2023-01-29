#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1e5 + 5;
bool Vis[M];
set<int> To_chceck;
vector<int> Graph[M];
int number, sajz;
inline void dfs(int v)
{
    Vis[v] = 1;
    sajz++;
    for (int w : Graph[v])
        if (!Vis[w])
            dfs(w);
}
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("revegetate.in"), fout.open("revegetate.out");
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);
    int n, m, a, b;
    char z;
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        fin >> z >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        To_chceck.insert(a), To_chceck.insert(b);
    }
    for (auto it = To_chceck.begin(); it != To_chceck.end(); it++)
    {
        if (!Vis[(*it)])
        {
            dfs(*it);
            number++;
        }
    }
    int total = n - sajz;
    vector<int> Res;
    Res.push_back(1);
    for (int i = 0; i < total + number; i++)
        Res.push_back(0);

    for (int e : Res)
        fout << e;

    fin.close(), fout.close();
    return 0;
}