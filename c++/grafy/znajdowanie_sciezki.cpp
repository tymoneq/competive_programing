#include <bits/stdc++.h>
using namespace std;

/*
// using dfs
const int N = 8;
bool visited[N];
stack<int> P;
void dfs(int a, vector<vector<int>> &graf, const int &meta)
{

    if (visited[meta])
    {
        return;
    }
    P.push(a);
    visited[a] = true;
    for (int b : graf[a])
    {

        if (!visited[b])
        {
            dfs(b, graf, meta);
        }
    }
}
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> graf(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
    }
    int start, meta;
    cin >> start >> meta;
    dfs(start, graf, meta);
    while (!P.empty())
    {

        cout << P.top() << " ";
        P.pop();
    }
    cout << endl;
    return 0;
}
*/

// using bfs
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> graf(n);
    bool visited[n]{0};
    int P[n]{0};
    queue<int> Q;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
    }
    int start, meta;
    cin >> start >> meta;
    P[start] = -1;
    Q.push(start);
    visited[start] = true;
    while (!Q.empty())
    {
        if (visited[meta])
            break;

        int v = Q.front();
        Q.pop();
        for (int u : graf[v])
        {

            if (!visited[u])
            {
                visited[u] = true;
                P[u] = v;
                Q.push(u);
            }
        }
    }
    for (int i = meta ; i > start; i--)
    {
        cout << P[i] << " ";
    }
    cout << endl;
    return 0;
}