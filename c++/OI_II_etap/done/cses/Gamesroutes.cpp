#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 10, MOD = 1e9 + 7;
vector<int> Graph[M];
vector<int> BackGraph[M];
int Sto[M];
long long dp[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph[a].push_back(b);
        BackGraph[b].push_back(a);
        Sto[b]++;
    }
    dp[1] = 1;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (Sto[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int w : Graph[v])
        {
            Sto[w]--;
            if (Sto[w] == 0)
                q.push(w);
        }
        for (int prev : BackGraph[v])
            dp[v] = (dp[v] + dp[prev]) % MOD;
    }
    cout << dp[n];
    return 0;
}