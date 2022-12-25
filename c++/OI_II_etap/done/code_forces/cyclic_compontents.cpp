#include <bits/stdc++.h>

using namespace std;
const int MAX_VAL = 2e5 + 10;
vector<int> Graph[MAX_VAL];
int R[MAX_VAL];
int Size[MAX_VAL];
bool Visited[MAX_VAL];
int correct = 1;
void dfs(int b)
{
    Visited[b] = 1;
    if (Graph[b].size() != 2)
    {
        correct = 0;
        return;
    }
    for (int v : Graph[b])
        if (!Visited[v])
            dfs(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, v, res = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        R[i] = i;
        Size[i] = 1;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (Visited[i])
            continue;
        Visited[i] = 1;

        for (int b : Graph[i])
        {
            q.push(b);
            R[b] = i;
            Size[i] += 1;
            Visited[b] = 1;
            Size[b] = 0;
        }
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            for (int c : Graph[v])
                if (!Visited[c])
                {

                    q.push(c);
                    R[c] = i;
                    Size[i] += 1;
                    Visited[c] = 1;
                    Size[c] = 0;
                }
        }
    }
    for (int i = 1; i <= n; i++)
        Visited[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (Size[i] < 3)
            continue;
        correct = 1;
        dfs(i);
        if (correct == 1)
            res += 1;
    }
    cout << res;
    return 0;
}