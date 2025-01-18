#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <vector>
using namespace std;

const int MAXN = 50000;

int N, M, C, R, K;
vector<pair<int, int>> adj[MAXN];

int visits[MAXN];
unordered_set<int> visitors[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> C >> R >> K;

    for (int i = 0; i < M; i++)
    {
        int u, v, l;
        cin >> u >> v >> l;
        u -= 1;
        v -= 1;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    // Initialize with all charging stations in the queue
    for (int i = 0; i < C; i++)
    {
        pq.push({0, i, i});
    }

    // Dijkstra's algorithm, except we (i) visit each node up to K times and (ii) only visit nodes
    // along paths of length at most R
    int well_connected = 0;
    while (!pq.empty())
    {
        const auto [d, u, r] = pq.top();
        pq.pop();
        if (visits[u] == K || visitors[u].find(r) != visitors[u].end())
        {
            continue;
        }
        // Update the number of visits and our count of well-connected destinations
        visits[u] += 1;
        visitors[u].insert(r);
        if (u >= C && visits[u] == K)
        {
            well_connected += 1;
        }
        // Add all neighbors within the range that have not been visited K times to the queue
        for (const auto &[v, l] : adj[u])
        {
            if (d + l <= R && visits[v] < K)
            {
                pq.push({d + l, v, r});
            }
        }
    }

    cout << well_connected << "\n";
    for (int i = C; i < N; i++)
    {
        if (visits[i] == K)
        {
            cout << i + 1 << "\n";
        }
    }
}