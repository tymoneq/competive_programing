#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> Graph(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    vector<int> Danger;
    for (int i = 1; i <= n; i++)
        if (Graph[i].size() == 1)
            Danger.push_back(i);

    vector<int> Distance(n + 1);
    queue<int> q;
    vector<int> Visited(n + 1);
    for (auto el : Danger)
    {
        q.push(el);
        Visited[el] = 1;
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int b : Graph[v])
        {
            if (!Visited[b])
            {
                q.push(b);
                Visited[b] = 1;
                Distance[b] = Distance[v] + 1;
            }
        }
    }
    sort(Distance.begin(), Distance.end());
    cout << Distance[Distance.size()-1];
    return 0;
}