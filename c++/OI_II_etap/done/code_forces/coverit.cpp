#include <bits/stdc++.h>
using namespace std;

constexpr int M = 2e5 + 10;
vector<int> Graph[M];
bool Vis[M];
int Dist[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t, a, b, odd, even, v;
    cin >> t;
    vector<int> res;
    queue<int> q;
    for (int l = 0; l < t; l++)
    {
        cin >> n >> m;
        odd = 0, even = 0;
        res.clear();
        for (int i = 1; i <= n; i++)
            Vis[i] = 0, Graph[i].clear(), Dist[i] = 0;

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            Graph[a].push_back(b), Graph[b].push_back(a);
        }
        Vis[1] = 0;
        Dist[1] = 0;
        q.push(1);
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            for (int w : Graph[v])
            {
                if (!Vis[w])
                {
                    Dist[w] = Dist[v] + 1;
                    Vis[w] = 1;
                    q.push(w);
                }
            }
        }
        for (int i = 1; i <= n; i++)
            if (Dist[i] % 2 == 0)
                odd++;
            else
                even++;

        cout << min(odd, even) << "\n";
        if (odd < even)
            for (int i = 1; i <= n; i++)
            {
                if (Dist[i] % 2 == 0)
                    cout << i << ' ';
            }
        else
            for (int i = 1; i <= n; i++)
                if (Dist[i] % 2 == 1)
                    cout << i << ' ';
        cout << "\n";
    }
    return 0;
}