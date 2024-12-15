#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

constexpr int N = 25;
int Val[N], Parent[N];
bool Vis[N], valid;

inline void check(int v)
{
    Vis[v] = 1;

    while (v != 1)
    {
        v = Parent[v];
        if (Vis[v])
            valid = 0;
    }
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
        cin >> Parent[i];

    int mask = 1 << n;

    ll res = -1;
    for (int i = 0; i < mask; i++)
    {
        int cnt = 0;
        valid = 1;
        ll current_res = 0;

        for (int j = 0; j < n; j++)
            if (1 & (i >> (j)))
            {
                cnt++;
                current_res += Val[j + 1];
                check(j + 1);
            }

        if (cnt == k && valid)
            res = max(res, current_res);

        for (int j = 0; j <= n; j++)
            Vis[j] = 0;
    }

    cout << res << '\n';

    return 0;
}