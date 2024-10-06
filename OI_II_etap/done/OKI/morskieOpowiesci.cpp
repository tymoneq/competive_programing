#include <bits/stdc++.h>

using namespace std;
struct podroz
{
    int dok, odl, nr;
};
constexpr int M = 5e3 + 10, N = 1e6 + 9;
vector<int> Graph[2 * M];
vector<podroz> pod[M];
int Dist[2 * M];
bool odp[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, a, b, v, d;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph[a].push_back(b + n);
        Graph[b].push_back(a + n);
        Graph[a + n].push_back(b);
        Graph[b + n].push_back(a);
    }
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> d;
        pod[a].push_back({b, d, i});
    }
    for (int i = 1; i <= n; i++)
        if (pod[i].size() > 0 && Graph[i].size() > 0)
        {
            for (int j = 1; j <= 2 * n; j++)
                Dist[j] = -1;
            Dist[i] = 0;
            q.push(i);
            while (!q.empty())
            {
                v = q.front();
                q.pop();
                for (int w : Graph[v])
                    if (Dist[w] == -1)
                    {
                        Dist[w] = Dist[v] + 1;
                        q.push(w);
                    }
            }

            for (int j = 0; j < pod[i].size(); j++)
                if (Dist[pod[i][j].dok + ((pod[i][j].odl % 2 == 0) ? 0 : 1) * n] != -1)
                    if (Dist[pod[i][j].dok + ((pod[i][j].odl % 2 == 0) ? 0 : 1) * n] <= pod[i][j].odl)
                        odp[pod[i][j].nr] = 1;
        }
    for (int i = 0; i < k; i++)
        cout << (odp[i] == 1 ? "TAK\n" : "NIE\n");
    return 0;
}