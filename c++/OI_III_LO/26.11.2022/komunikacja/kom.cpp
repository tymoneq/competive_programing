#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
int R[M];
int Sajz[M];
bool Visited[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, v;
    cin >> n >> m >> k;
    vector<vector<int>> Graph(n + 1);
    long long wynik = 0, tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        R[i] = i;
        Sajz[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (R[i] != i)
            continue;
        q.push(i);
        Visited[i] = 1;
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            for (int w : Graph[v])
                if (!Visited[w])
                {
                    R[w] = i;
                    Sajz[i] += 1;
                    Sajz[w] = 0;
                    q.push(w);
                    Visited[w] = 1;
                }
        }
    }
    // double wzor = (1 + n) / 2 * n;
    sort(Sajz, Sajz + n, greater<int>());
    for (int i = 0; i <= k; i++)
        tmp += Sajz[i];

    wynik += tmp * (tmp - 1) / 2;
    for (int i = k + 1; i < n; i++)
        wynik += Sajz[i] * (Sajz[i] - 1) / 2;

    cout << wynik;
    return 0;
}