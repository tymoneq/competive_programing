#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e8;

inline int fint(int v, vector<int> &R) { return R[v] == v ? v : R[v] = fint(R[v], R); }

inline void onion(int a, int b, vector<int> &R, vector<int> &Sajz)
{
    if (fint(a, R) == fint(b, R))
        return;

    if (Sajz[fint(a, R)] < Sajz[fint(b, R)])
        swap(a, b);

    Sajz[R[a]] += Sajz[R[b]];
    Sajz[R[b]] = 0;
    R[R[b]] = R[a];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;

    vector<int> R(n + 1), Sajz(n + 1, 1), dp(n + 1, INF);
    map<int, int> Cnt;

    // dsu algo
    for (int i = 1; i <= n; i++)
        R[i] = i;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        onion(a, b, R, Sajz);
    }

    // counting elements

    for (int i = 1; i <= n; i++)
        if (Sajz[i] != 0)
            Cnt[Sajz[i]]++;

    // knapsack problem
    dp[0] = -1;

    for (auto el : Cnt)
        for (int k = 1; k <= el.second; k *= 2)
        {
            int nw = k * el.first;
            for (int i = n; i >= nw; i--)
                dp[i] = min(dp[i], dp[i - nw] + k);
        }

    // finding best answer
    int mn = INF;
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        bool T = 1;

        while (num > 0)
        {
            if (num % 10 == 7 || num % 10 == 4)
            {
                num /= 10;
                continue;
            }
            T = 0;
            break;
        }

        if (T)
            mn = min(dp[i], mn);
    }

    cout << (mn == INF ? -1 : mn) << "\n";
    return 0;
}