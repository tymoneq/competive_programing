#include <bits/stdc++.h>
using namespace std;
struct Cow
{
    int x, y, power;
};
const int M = 210;
int current = 0;
vector<int> Graph[M];
bool vis[M];
void dfs(int v)
{
    vis[v] = 1;
    current++;
    for (int w : Graph[v])
        if (!vis[w])
            dfs(w);
}

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("moocast.in"), fout.open("moocast.out");
    int n;
    fin >> n;
    vector<Cow> C(n);
    for (int i = 0; i < n; i++)
        fin >> C[i].x >> C[i].y >> C[i].power;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            double dist = sqrt(pow((C[j].x - C[i].x), 2) + pow((C[j].y - C[i].y), 2));
            if (dist <= C[i].power)
                Graph[i].push_back(j);
        }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        current = 0;
        for (int j = 0; j < n; j++)
            vis[j] = 0;

        dfs(i);
        res = max(res, current);
    }
    fout << res;
    fin.close(), fout.close();
    return 0;
}