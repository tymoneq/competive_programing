#include <bits/stdc++.h>

using namespace std;
const int M = 1e5 + 10;
vector<int> Graph[M];
bool Vis[M], Vis2[M];
int Dist[M], Dist2[M], Path[M];
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("atlarge.in"), fout.open("atlarge.out");
    int n, k, a, b;
    fin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        fin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    queue<int> q;
    queue<int> Q;
    Vis[k] = 1;
    q.push(k);
    Path[k] = 0;
    int res = 0, v;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        if (Graph[v].size() == 1)
            Q.push(v), Vis2[v] = 1;
        else
            for (int w : Graph[v])
                if (!Vis[w])
                {
                    Vis[w] = 1;
                    Dist[w] = Dist[v] + 1;
                    Path[w] = v;
                    q.push(w);
                }
    }
    set<int> R;
    int p = 0;
    while (!Q.empty())
    {
        v = Q.front();
        Q.pop();
        if (abs(Dist[v] - Dist2[v] <= 1))
        {
            bool fint = 0;
            p = Path[v];
            while (p != 0)
            {
                if (R.count(p))
                {
                    fint = 1;
                    break;
                }
                p = Path[p];
            }

            if (!fint)
            {
                res++;
                R.insert(v);
            }
            continue;
        }
        for (int w : Graph[v])
            if (!Vis2[w])
            {
                Vis2[w] = 1;
                Dist2[w] = Dist2[v] + 1;
                Q.push(w);
            }
    }

    fout << res;
    return 0;
}