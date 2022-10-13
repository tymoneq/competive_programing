#include <bits/stdc++.h>

using namespace std;
const int N = 5;
int odl[N];
bool visited[N];
void dfs(int a, vector<vector<int>> &graf)
{
    cout << a << "\n";
    visited[a] = true;
    for (int b : graf[a])
    {
        if (!visited[b])
            dfs(b, graf);
    }
}

int main()
{
    // są dwa sposoby przejścia po grafie BFS(kolejka rzeczy do rozważenia)--znajduje najkrótsze odległości DFS( zachłanna rekurencja wgłab) --prosty
    // Dijkstra zaawansowany BFS
    // Floyd-Warshall Bellmand-ford

    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> graf(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    dfs(0, graf);
    // bfs
    // vector<int> q;
    // q.push_back(0);
    // visited[0] = true;
    // for (int i = 0; i < (int)q.size(); i++)
    // {
    //     int a = q[i];
    //     cout << "bfs " << a << " odległość " << odl[a] << "\n";

    //     for (int b : graf[a])
    //     {
    //         if (!visited[b])
    //         {
    //             odl[b] = odl[a] + 1;
    //             visited[b] = true;
    //             q.push_back(b);
    //         }
    //     }
    // }
    // dijkstra
    return 0;
}