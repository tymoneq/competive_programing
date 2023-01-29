#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int vertex;
    double cost, flow;
};

vector<edge> Graph[1010];

bool Visit[1010];
double Dist[1010][3];
ifstream file_in;
ofstream file_out;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    file_in.open("pump.in"), file_out.open("pump.out");
    double c, d, min_flow, cost;
    int n, m, a, b;
    pair<double, int> v;
    file_in >> n >> m;
    for (int i = 0; i < m; i++)
    {
        file_in >> a >> b >> c >> d;
        if (a == n)
            Graph[b].push_back({a, c, d});
        if (b == n)
            Graph[a].push_back({b, c, d});
        else
        {
            Graph[a].push_back({b, c, d});
            Graph[b].push_back({a, c, d});
        }
    }
    for (int i = 1; i <= n; i++)
        Dist[i][0] = numeric_limits<long long>::max() - numeric_limits<int>::max(), Dist[i][2] = numeric_limits<int>::max();

    Dist[1][0] = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        v = pq.top();
        pq.pop();
        if (!Visit[v.second])
            for (auto w : Graph[v.second])
            {
                min_flow = min(Dist[v.second][2], w.flow);
                if (min_flow / (Dist[v.second][0] + w.cost) > Dist[w.vertex][1])
                {
                    Dist[w.vertex][0] = Dist[v.second][0] + w.cost;
                    Dist[w.vertex][1] = min_flow / (Dist[v.second][0] + w.cost);
                    Dist[w.vertex][2] = min_flow;
                    pq.push({Dist[w.vertex][1], w.vertex});
                }
            }
        Visit[v.second] = 1;
    }
    int res = Dist[n][1] * (1e6);
    file_out << res;
    file_in.close(), file_out.close();
    return 0;
}