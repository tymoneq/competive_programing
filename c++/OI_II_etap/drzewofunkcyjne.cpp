#include <bits/stdc++.h>

using namespace std;
const int M = 1010;
const long long mod = 1e9 + 7;
vector<int> Graph[M];
bool Vis[M];
long long Dist[M];
long long val[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        a--, b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    long long sum = 0;
    queue<pair<int, int>> q; // second -1 odejmujes 1 dodajesz
    for (int i = 0; i < n; i++)
    {
        Vis[i] = 1;
        Dist[i] = val[i];
        q.push({i, -1});
        while (!q.empty())
        {
            auto v = q.front();
            q.pop();
            for (int w : Graph[v.first])
                if (!Vis[w])
                {
                    Dist[w] = Dist[v.first] + val[w] * v.second;
                    Vis[w] = 1;
                    q.push({w, v.second * -1});
                }
        }
        for (int j = 0; j < n; j++)
        {
            sum += Dist[j];
            Dist[j] = 0;
            Vis[j] = 0;
        }
    }
    sum %= mod;
    cout << sum;

    return 0;
}