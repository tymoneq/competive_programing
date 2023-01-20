#include <bits/stdc++.h>

using namespace std;
const int M = 2e5 + 10;
vector<int> Graph[M];
int Parent[M];
bool ANS[M];
vector<int> depth;
bool ON[M];
int fintRoot(int a)
{
    if (Parent[a] == a)
        return a;
    return Parent[a] = fintRoot(Parent[a]);
}
void join(int a, int b)
{
    Parent[fintRoot(a)] = fintRoot(b);
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
    for (int i = 0; i <= n; i++)
        Parent[i] = i;
    vector<int> queries(n);
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        fin >> a;
        queries[n - i - 1] = a;
    }
    int comp = 0, node;
    for (int i = 0; i < n; i++)
    {
        node = queries[i];
        comp++;
        ON[node] = 1;
        for (int j : Graph[node])
            if (ON[j] && (fintRoot(node) != fintRoot(j)))
            {
                join(node, j);
                comp--;
            }
        ANS[n - i - 1] = comp == 1;
    }
    for (int i = 0; i < n; i++)
        if (ANS[i])
            fout << "YES\n";
        else
            fout << "NO\n";
    fin.close(), fout.close();
    return 0;
}