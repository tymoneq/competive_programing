#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
vector<int> Graph[M];
bool Vis[M];
int Dist[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, a, b, v;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        Graph[i].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        Dist[i] = -1;
    queue<int> Q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        Vis[a] = 1;
        Dist[a] = 0;
        Q.push(a);
        while (!Q.empty())
        {
            v = Q.front();
            Q.pop();
            if (Vis[b])
            {
                while (!Q.empty())
                    Q.pop();
                break;
            }
            for (int w : Graph[v])
                if (!Vis[w])
                {
                    Dist[w] = Dist[v] + 1;
                    Q.push(w);
                    Vis[w] = 1;
                }
        }
        cout << Dist[b] << "\n";
        for (int j = 1; j <= n; j++)
        {
            Vis[j] = 0;
            Dist[j] = -1;
        }
    }
    return 0;
}