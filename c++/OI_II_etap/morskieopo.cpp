#include <bits/stdc++.h>

using namespace std;
const int M = 5e3 + 10;
vector<int> Graph[M];
int R[M];
int Dist[M][M];
bool Visit[M];
int D[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, a, b, v, d;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        R[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!Visit[i])
        {
            Visit[i] = 1;
            q.push(i);
            while (!q.empty())
            {
                v = q.front();
                q.pop();
                for (int w : Graph[v])
                    if (!Visit[w])
                    {
                        R[w] = i;
                        Visit[w] = 1;
                        q.push(w);
                    }
            }
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            Visit[j] = 0;
        q.push(i);
        Visit[i] = 1;
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            for (int w : Graph[v])
                if (!Visit[w])
                {
                    Visit[w] = 1;
                    q.push(w);
                    Dist[i][w] = Dist[i][v] + 1;
                }
        }
    }
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> d;
        if (R[a] != R[b])
            cout << "NIE\n";
        else if (Dist[a][b] <= d)
        {
            if (d >= m)
                cout << "TAK\n";
            else
            {
                for (int j = 1; j <= n; j++)
                    Visit[j] = 0, D[j] = 0;
                Visit[a] = 1;
                q.push(a);
                while (!q.empty())
                {
                    v = q.front();
                    q.pop();
                    for (int w : Graph[v])
                        if(!Visit)
                }
            }
        }

        else
            cout << "NIE\n";
    }
    return 0;
}