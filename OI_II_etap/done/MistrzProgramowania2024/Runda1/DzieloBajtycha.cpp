#include <bits/stdc++.h>
using namespace std;

#warning change N and K
constexpr int N = 1e5 + 10, K = 510;
typedef long long ll;
constexpr ll INF = -1;

ll dp[N][K];
vector<int> adj[N];
int Val[N];

inline void calc(int v, int p, int &k)
{

    // rekurencja po synach
    for (int w : adj[v])
        if (w != p)
            calc(w, v, k);

    // policzenie stanów dp dla V
    vector<vector<ll>> tmpdp(k + 1, vector<ll>(k + 1, -1));
    for (int i = 0; i <= k; i++)
        tmpdp[i][0] = 0;
    for (int w : adj[v])
        if (w != p)
        {
            for (int i = 1; i <= k; i++)
            {
                if (dp[w][i] == -1)
                    continue;
                for (int j = k - i; j >= 0; j--)
                {
                    if (tmpdp[i][j] < 0)
                        continue;
                    tmpdp[i][j + i] = max(tmpdp[i][j + i], dp[w][i] + tmpdp[i][j]);
                }
            }
            for (int j = k - 1; j >= 0; j--)
            {
                if (tmpdp[0][j] == -1)
                    continue;
                tmpdp[0][j + 1] = max(tmpdp[0][j + 1], tmpdp[0][j] + dp[w][0]);
            }

            for (int i = 0; i <= k; i++)
            {
                ll mx = -1;
                for (int j = 0; j <= k; j++)
                    mx = max(mx, tmpdp[j][i]);

                for (int j = 0; j <= k; j++)
                    tmpdp[j][i] = mx;
            }

            for (int i = 1; i <= k; i++)
                dp[v][i] = max(dp[v][i], tmpdp[0][i]);
        }

    // ustawienie dp[v][0] na wartość V
    dp[v][0] = Val[v];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> Val[i];

    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            dp[i][j] = INF;
    calc(1, 1, k);

    if (k == 1)
        cout << max(dp[1][0], dp[1][1]) << '\n';

    else if (dp[1][k] == -1)
        cout << -1 << '\n';
    else
        cout << dp[1][k] << '\n';

    return 0;
}