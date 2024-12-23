#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

struct Cow
{
    int height, weight, strength;
};

struct dpState
{
    int cumulativeHeight, safetyFactor;
};
class Solve
{
protected:
    int n, MarkHeight;
    vector<Cow> cows;
    vector<dpState> dp;
    const int INF = 1e9 + 5;

public:
    inline void solve()
    {
        cin >> n >> MarkHeight;

        cows.resize(n);
        dp.resize((1 << n));

        FOR(i, n, 0)
        cin >> cows[i].height >> cows[i].weight >> cows[i].strength;

        dp[0] = {0, INF};

        FOR(mask, (1 << n) + 1, 1)
        {
            dp[mask] = {0, -1};

            FOR(bit, n, 0)
            if (mask & (1 << bit))
            {
                dp[mask].cumulativeHeight += cows[bit].height;
                int prev = mask ^ (1 << bit);
                dp[mask].safetyFactor = max(dp[mask].safetyFactor, min(dp[prev].safetyFactor - cows[bit].weight, cows[bit].strength));
            }
        }

        int maxSafety = -1;
        FOR(mask, (1 << n) + 1, 1)
        if (dp[mask].cumulativeHeight >= MarkHeight)
            maxSafety = max(maxSafety, dp[mask].safetyFactor);

        if (maxSafety < 0)
            cout << "Mark is too tall" << '\n';
        else
            cout << maxSafety << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("guard.in", "r", stdin);
    // freopen("guard.out", "w", stdout);

    Solve solution;
    solution.solve();
    return 0;
}