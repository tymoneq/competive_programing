#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)
typedef long long ll;

struct cowCordinates
{
    int CowX, CowY;
};

class Solve
{
protected:
    const ll INF = 1e17 + 5;
    const int K = 2;
    int HolsteinCows, GuernseyCows;
    vector<vector<vector<ll>>> dp;
    vector<cowCordinates> Holstein, Guernsey;

public:
    inline void read_data()
    {
        cin >> HolsteinCows >> GuernseyCows;
        dp.resize(HolsteinCows + 1);
        Holstein.resize(HolsteinCows + 1);
        Guernsey.resize(GuernseyCows + 1);

        FOR(i, HolsteinCows + 1, 1)
        cin >> Holstein[i].CowX >> Holstein[i].CowY;
        FOR(i, GuernseyCows + 1, 1)
        cin >> Guernsey[i].CowX >> Guernsey[i].CowY;
    }
    inline ll calcDist(cowCordinates firstCow, cowCordinates SecondCow)
    {
        return (abs(firstCow.CowX - SecondCow.CowX)) * (abs(firstCow.CowX - SecondCow.CowX)) + (abs(firstCow.CowY - SecondCow.CowY)) * (abs(firstCow.CowY - SecondCow.CowY));
    }

    inline void solve()
    {

        read_data();
        FOR(i, HolsteinCows + 1, 0)
        {
            dp[i].resize(GuernseyCows + 1);
            FOR(j, GuernseyCows + 1, 0)
            dp[i][j].resize(K);
        }
        // set dp
        FOR(i, HolsteinCows + 1, 0)
        FOR(j, GuernseyCows + 1, 0)
        FOR(k, K, 0)
        dp[i][j][k] = INF;

        dp[1][0][0] = 0;

        // calc dp
        FOR(i, HolsteinCows + 1, 1)
        FOR(j, GuernseyCows + 1, 1)
        {
            dp[i][j][0] = min({dp[i - 1][j][0] + calcDist(Holstein[i], Holstein[i - 1]),
                               dp[i][j - 1][0] + 2 * calcDist(Holstein[i], Guernsey[j]),
                               dp[i - 1][j][1] + calcDist(Guernsey[j], Holstein[i]),
                               dp[i][j - 1][1] + calcDist(Guernsey[j], Guernsey[j - 1]) + calcDist(Guernsey[j], Holstein[i])});

            dp[i][j][1] = min({dp[i - 1][j][0] + calcDist(Holstein[i], Holstein[i - 1]) + calcDist(Holstein[i], Guernsey[j]),
                               dp[i][j - 1][0] + calcDist(Holstein[i], Guernsey[j]),
                               dp[i - 1][j][1] + 2 * calcDist(Holstein[i], Guernsey[j]),
                               dp[i][j - 1][1] + calcDist(Guernsey[j], Guernsey[j - 1])});
        }

        ll ans = dp[HolsteinCows][GuernseyCows][0];
        cout << ans << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    Solve solution;
    solution.solve();

    return 0;
}