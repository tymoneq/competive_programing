#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

struct state
{
    int lastNetSize, howManyWastedSpace;
};

class Solve
{
protected:
    const int INF = 1e9 + 5;
    int NumberOfSnakes, NetSizeChanges;
    vector<vector<state>> dp;
    vector<int> Snakes;
    set<int> SnakeSizes;

public:
    inline void read_data()
    {
        cin >> NumberOfSnakes >> NetSizeChanges;

        Snakes.resize(NumberOfSnakes);
        dp.resize(NumberOfSnakes);

        FOR(i, NumberOfSnakes, 0)
        {
            cin >> Snakes[i];
            dp[i].resize(NetSizeChanges + 1);
        }
    }

    inline void setDp()
    {
        FOR(i, NumberOfSnakes, 0)
        FOR(j, NetSizeChanges + 1, 0)
        dp[i][j] = {INF, INF};
    }

    inline void solve()
    {
        read_data();
        setDp();
        int bestScore = INF;
        int maxVal = 0;
        int sum_of_elements = 0;
        int cnt = 0;
        for (int i = NumberOfSnakes - 1; i >= 0; i--)
        {
            cnt++;
            maxVal = max(maxVal, Snakes[i]);
            sum_of_elements += Snakes[i];
            dp[i][0].howManyWastedSpace = maxVal * cnt - sum_of_elements;
            dp[i][0].lastNetSize = maxVal;
        }

        cnt = 1;
        for (int i = NumberOfSnakes - 2; i >= 0; i--)
        {
            FOR(stan, NetSizeChanges + 1, 1)
            {
                if (cnt < stan)
                    break;

                dp[i][stan].lastNetSize = Snakes[i];
                dp[i][stan].howManyWastedSpace = dp[i + 1][stan - 1].howManyWastedSpace;

                int Ile = 1;
                int suma = Snakes[i];
                int mx = Snakes[i];
                FOR(j, NumberOfSnakes - 1, i + 1)
                {
                    Ile++;
                    suma += Snakes[j];
                    mx = max(mx, Snakes[j]);
                    if (dp[j][stan].lastNetSize != INF)
                    {
                        int nowyWynik = mx * Ile - suma + dp[j + 1][stan - 1].howManyWastedSpace;
                        if (nowyWynik < dp[i][stan].howManyWastedSpace)
                        {
                            dp[i][stan].howManyWastedSpace = nowyWynik;
                            dp[i][stan].lastNetSize = dp[j][stan].lastNetSize;
                        }
                    }
                    else
                        break;
                }
            }
            cnt++;
        }

        FOR(stan, NetSizeChanges + 1, 0)
        bestScore = min(bestScore, dp[0][stan].howManyWastedSpace);

        cout << bestScore << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    Solve solution;
    solution.solve();

    return 0;
}