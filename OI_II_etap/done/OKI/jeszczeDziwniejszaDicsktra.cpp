#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 1e5 + 10;

vector<pair<int, int>> adj[N];
bool Vis[N];
pair<ll, vector<int>> D[N];

bool valid(pair<ll, vector<int>> &lhs, pair<ll, vector<int>> &rhs)
{

    for (int i = 0; i < min(lhs.second.size(), rhs.second.size()); i++)
    {
        if (lhs.second[i] == rhs.second[i])
            continue;
        return lhs.second[i] < rhs.second[i];
    }
    return 0;
}

struct distComparator
{

    bool operator()(pair<ll, vector<int>> &lhs, pair<ll, vector<int>> &rhs)
    {
        if (lhs.first == rhs.first)
        {
            if (lhs.second.size() == rhs.second.size())
                for (int i = 0; i < lhs.second.size(); i++)
                {
                    if (lhs.second[i] == rhs.second[i])
                        continue;
                    return lhs.second[i] > rhs.second[i];
                }

            return lhs.second.size() > rhs.second.size();
        }

        return lhs.first > rhs.first;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        D[i].first = numeric_limits<ll>::max();

    while (m--)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<pair<ll, vector<int>>, vector<pair<ll, vector<int>>>, distComparator> pq;
    D[1].first = 0;
    vector<int> A = {1};
    pq.push({0, A});
    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        if (!Vis[v.second[v.second.size() - 1]])
        {
            for (auto w : adj[v.second[v.second.size() - 1]])
            {
                if (D[w.first].first > D[v.second[v.second.size() - 1]].first + w.second)
                {
                    D[w.first].first = D[v.second[v.second.size() - 1]].first + w.second;
                    D[w.first].second = v.second;
                    D[w.first].second.push_back(w.first);
                    pq.push({D[w.first].first, D[w.first].second});
                }
                else if (D[w.first].first == D[v.second[v.second.size() - 1]].first + w.second && valid(v, D[w.first]))
                {
                    D[w.first].second = v.second;
                    D[w.first].second.push_back(w.first);
                    pq.push({D[w.first].first, D[w.first].second});
                }
            }
            Vis[v.second[v.second.size() - 1]] = 1;
        }
    }
    if (D[n].first == numeric_limits<ll>::max())
        cout << -1 << "\n";
    else
    {
        cout << D[n].second.size() << "\n";
        for (int e : D[n].second)
            cout << e << " ";
        cout << "\n";
    }
    return 0;
}