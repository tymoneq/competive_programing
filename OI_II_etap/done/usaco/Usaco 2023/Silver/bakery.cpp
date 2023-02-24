#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
constexpr ull INF = 5e18;
struct bakery
{
    ull cookie, muffin, time;
};
vector<bakery> B;
bool valid(ull val, ull t)
{
    bool cor = 1;
    for (auto w : B)
        if (t * w.cookie + (val * w.muffin) > w.time)
        {
            cor = 0;
            break;
        }
    return cor;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    ull tc, tm, cost, res, mintm;
    bool corect = 1;
    ull lo, hi, mid,LO;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> tc >> tm;
        res = INF;
        B.resize(n);
        for (int i = 0; i < n; i++)
            cin >> B[i].cookie >> B[i].muffin >> B[i].time;

        for (ull i = 1; i <= tc; i++)
        {
            mintm = INF;
            lo = 1, hi = tm;
            while (lo <= hi)
            {
                mid = lo + (hi - lo) / 2;
                if (valid(mid, i))
                {
                    lo = mid + 1;
                    mintm = mid;
                }
                else
                    hi = mid - 1;
            }
            if (mintm != INF)
                res = min(res, (tc - i + tm - mintm));
        }
        B.clear();
        cout << res << "\n";
    }
    return 0;
}