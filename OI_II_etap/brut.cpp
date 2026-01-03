#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define vec vector

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec<vec<int>> graph(n + 1);
    FOR(i, 0, m)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vec<int> ideg(n + 1, 0), hats(n + 1, 0);

    queue<int> q;

    hats[1] = 1;
    hats[2] = n;

    for (int v : graph[1])
        ideg[v]++;

     FOR(i, 1, n + 1)
    if (graph[i].size() == 2 * ideg[i] && hats[i] == 0)
        q.push(i);

    int timer = 2;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        hats[v] = timer++;
        for (int u : graph[v])
            if (hats[u] == 0)
            {
                ideg[u]++;
                if (graph[u].size() == 2 * ideg[u])
                    q.push(u);
            }
    }

    if (timer == n)
    {
        cout << "TAK\n";
        FOR(i, 1, n + 1)
        cout << hats[i] << " ";
    }
    else
        cout << "NIE\n";

    return 0;
}