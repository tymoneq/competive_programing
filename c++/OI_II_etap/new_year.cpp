#include <bits/stdc++.h>

using namespace std;
const int MAX_val = 10;
vector<int> Graph[MAX_val];
bool Visited[MAX_val];
int Way_to_node[MAX_val];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, v, index = 0;
    cin >> n >> m;
    queue<int> Q;
    vector<int> Res;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    Visited[1] = 1;
    Q.push(1);
    while (!Q.empty())
    {
        v = Q.front();
        Q.pop();
        for (int b : Graph[v])
            if (!Visited[b])
            {
                Visited[b] = 1;
                Q.push(b);
                Way_to_node[b] = v;
            }
    }
    index = n;
    while (index != 1)
    {
        Res.push_back(index);
        index = Way_to_node[index];
    }
    for (int i = Res.size() - 1; i >= 0; i--)
        cout << Res[i] << " ";
    return 0;
}