#include <bits/stdc++.h>
using namespace std;
void dfsStack(int v, bool *visited, stack<int> &S, vector<vector<int>> &G)
{
    visited[v] = true;
    for (int b : G[v])
    {
        if (!visited[b])

            dfsStack(b, visited, S, G);
    }
    S.push(v);
}

void dfsPrint(int v, bool *visited, vector<vector<int>> &G)
{
    visited[v] = true;
    cout << v << " ";
    for (int b : G[v])
    {
        if (!visited[b])
            dfsPrint(v, visited, G);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    bool visited[n]{0};
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    stack<int> S;
    for (int v = 0; v < n; v++)
    {
        if (!visited[v])
            dfsStack(v, visited, S, G);
    }
    vector<vector<int>> G_transpoz(n);
    for (int i = 0; i < n; i++)
    {
        if (!G[i].empty())
        {
            for (auto el : G[i])
            {
                G_transpoz[el].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
        visited[i] = false;

    int cn = 0;
    while (!S.empty())
    {
        int v = S.top();
        S.pop();
        if (!visited[v])
        {
            cn += 1;
            cout << cn << ": ";
            dfsPrint(v, visited, G_transpoz);
        }
    }

    return 0;
}