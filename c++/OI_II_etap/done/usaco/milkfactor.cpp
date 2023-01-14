#include <bits/stdc++.h>
using namespace std;
vector<int> Graph[110];
bool Visit[110];
bool Center[110];
inline void dfs_1(int v)
{
    Center[v] = 1;
    for (int w : Graph[v])
        if (!Center[w])
            dfs_1(w);
}
inline void dfs(int v)
{
    Visit[v] = 1;
    for (int w : Graph[v])
        if (!Visit[w])
            dfs(w);
}
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("factory.in"), fout.open("factory.out");
    int n, a, b;
    fin >> n;
    for (int i = 1; i < n; i++)
    {
        fin >> a >> b;
        Graph[a].push_back(b);
    }
    dfs_1(1);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            Visit[j] = 0;
        dfs(i);
        for (int j = 1; j <= n; j++)
            Center[j] = Center[j] & Visit[j];
    }
    for (int i = 1; i <= n; i++)
        if (Center[i])
        {
            fout << i;
            fin.close(), fout.close();
            return 0;
        }
    fout << -1;
    fin.close(), fout.close();
    return 0;
}