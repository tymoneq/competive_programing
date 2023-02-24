#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
constexpr ull INF = 5e18;
struct bakery
{
    ull cookie, muffin, time;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    ull tc, tm, cost, res;
    bool corect = 1;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> tc >> tm;
        res = INF;
        vector<bakery> B(n);
        for (int i = 0; i < n; i++)
            cin >> B[i].cookie >> B[i].muffin >> B[i].time;
        for (ull i = 1; i <= tc; i++)
            for (ull j = 1; j <= tm; j++)
            {
                corect = 1;
                for (auto &w : B)
                    if (i * w.cookie + j * w.muffin > w.time)
                    {
                        corect = 0;
                        break;
                    }
                if (corect)
                {
                    cost = (tc - i) + (tm - j);
                    res = min(res, cost);
                }
                if (!corect)
                    break;
            }
        cout << res << "\n";
    }
    return 0;
}