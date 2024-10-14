#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int N = 5e5 + 10;
vector<int> adj[N];
ll timer = -1, cities_to_visit;

inline void calc(int v, int p)
{

    timer++;
    cities_to_visit--;

    for (int w : adj[v])
        if (w != p)
            calc(w, v);

    if (cities_to_visit == 0)
        return;
    timer++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, a, b, city_with_agent;
    cin >> n >> k >> city_with_agent;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cities_to_visit = n;
    calc(city_with_agent, 0);

    cout << timer << "\n";
    return 0;
}