#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
vector<pair<int, int>> Graph[M];
int d[M];
bool Vis[M];
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    int n, m, a, b, c;
    fin.open("wormsort.in"), fout.open("wormsort.out");
    fin >> n >> m;
    vector<int> Cows(n);
    for (int i = 0; i < n; i++)
    {
        fin >> Cows[i];
        Cows[i]--;
    }
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b >> c;
        a--, b--;
        Graph[a].push_back({b, c});
        Graph[b].push_back({a, c});
    }
    // for (int i = 0; i <= n; i++)
    //     d[i] = numeric_limits<int>::max();
    d[0] = numeric_limits<int>::max();
    pair<int, int> v;
    int weight;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        v = pq.top();
        pq.pop();
        for (auto w : Graph[v.second])
            if (!Vis[w.first])
            {
                weight = min(w.second, d[v.second]);
                if (weight > d[w.first])
                {
                    d[w.first] = weight;
                    pq.push({weight, w.first});
                }
            }

        Vis[v.second];
    }
    int mn = numeric_limits<int>::max();
    for (int i = 0; i < n; i++)
        if (Cows[i] != i)
            mn = min(mn, d[i]);
    if (mn == numeric_limits<int>::max())
        fout << -1;
    else
        fout << mn;
    fin.close(), fout.close();
    return 0;
}