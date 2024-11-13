#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 10, INF = 1e8;
bool Agent[N];
vector<int> adj[N];
int dp[N][3]; // 0-> dp w górę 1-> dp w dół

inline vector<int> innerDP(int v, int sum, int p)
{
    vector<vector<int>> innerDP(adj[v].size(), vector<int>(3, -INF)); // 0-> w góre 1-> w dół 2-> po dwóch indeksach

    int indx = -1;
    for (int w : adj[v])
        if (w != p)
        {
            indx++;
            if (indx == 0)
            {
                innerDP[0][0] = sum - dp[w][2] + 1 + dp[w][0];
                innerDP[0][1] = sum - dp[w][2] + 1 + dp[w][1];
            }
            else
            {
                innerDP[indx][0] = max(innerDP[indx - 1][0], sum - dp[w][2] + 1 + dp[w][0]);
                innerDP[indx][1] = max(innerDP[indx - 1][1], sum - dp[w][2] + 1 + dp[w][1]);
                innerDP[indx][2] = max(innerDP[indx - 1][2], max(dp[w][0] + innerDP[indx - 1][1], innerDP[indx - 1][0] + dp[w][1]) - dp[w][2] + 1);
            }
        }

    return innerDP[max(indx, 0)];
}

inline void calc(int v, int p)
{
    int suma = 0;

    for (int w : adj[v])
        if (w != p)
        {
            calc(w, v);
            suma += dp[w][2];
        }

    vector<int> innerdp = innerDP(v, suma, p);

    if (Agent[v])
    {
        dp[v][0] = suma;
        dp[v][1] = -INF;
        dp[v][2] = max(suma, innerdp[1]);
    }
    else
    {
        dp[v][0] = innerdp[0];
        dp[v][1] = max(suma, innerdp[1]);
        dp[v][2] = max({suma, innerdp[0], innerdp[2]});
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;

    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        Agent[a] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    calc(1, 1);

    cout << 2 * (n - k) - dp[1][2] << '\n';
    return 0;
}