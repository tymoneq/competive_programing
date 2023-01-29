#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e5 + 7;
vector<pair<int, int>> Graph[M];
bool Visit[M];
ll Dist[M];
int Path[M][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, c;
    pair<ll, int> v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        Graph[a].push_back({b, c});
    }
    for (int i = 1; i <= n; i++)
        Dist[i] = numeric_limits<ll>::max() - numeric_limits<int>::max();
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    Dist[1] = 0;
    while (!pq.empty())
    {
        v = pq.top();
        pq.pop();
        if (!Visit[v.second])
            for (auto w : Graph[v.second])
                if (Dist[w.first] > Dist[v.second] + w.second)
                {
                    Path[w.first][0] = v.second;
                    Path[w.first][1] = w.second;
                    Dist[w.first] = Dist[v.second] + w.second;
                    pq.push({Dist[w.first], w.first});
                }
        Visit[v.second] = 1;
    }
    int mx = 0, N = n;
    while (Path[N][0] != 0)
    {
        mx = max(mx, Path[N][1]);
        N = Path[N][0];
    }
    int r = mx / 2;
    cout << Dist[n] - mx + r;
    return 0;
}