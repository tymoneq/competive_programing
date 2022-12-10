#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    pair<int, bool> v;
    cin >> n >> m;
    vector<vector<int>> Graph_A(n + 1);
    vector<vector<int>> Graph_b(n + 1);
    vector<int> Res(n + 1);
    vector<bool> Visited(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph_A[a].push_back(b);
        Graph_b[b].push_back(a);
    }
    queue<pair<int, bool>> q;
    q.push(make_pair(1, 1)); // 1 - graph a 0-graph b
    Visited[1] = 1;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        if (Visited[n])
            break;
        if (v.second)
            for (int b : Graph_A[v.first])
            {
                if (!Visited[b])
                {
                    Visited[b] = 1;
                    Res[b] = Res[v.first] + 1;
                    q.push(make_pair(b, 0));
                }
            }
        if (!v.second)
            for (int b : Graph_b[v.first])
            {
                if (!Visited[b])
                {
                    Visited[b] = 1;
                    Res[b] = Res[v.first] + 1;
                    q.push(make_pair(b, 1));
                }
            }
    }
    int wynik = Res[n];
    for (int i = 1; i <= n; i++)
    {
        Res[i] = 0;
        Visited[i] = 0;
    }
    q.push(make_pair(1, 0)); // 1 - graph a 0-graph b
    Visited[1] = 1;

    while (!q.empty())
    {
        v = q.front();
        q.pop();
        if (Visited[n])
            break;
        if (v.second)
            for (int b : Graph_A[v.first])
            {
                if (!Visited[b])
                {
                    Visited[b] = 1;
                    Res[b] = Res[v.first] + 1;
                    q.push(make_pair(b, 0));
                }
            }
        if (!v.second)
            for (int b : Graph_b[v.first])
            {
                if (!Visited[b])
                {
                    Visited[b] = 1;
                    Res[b] = Res[v.first] + 1;
                    q.push(make_pair(b, 1));
                }
            }
    }
    if (max(wynik, Res[n]) != 0)
        if (min(wynik, Res[n]) != 0)
            cout << min(wynik, Res[n]);
        else
            cout << max(wynik, Res[n]);
    else
        cout << -1;

    return 0;
}