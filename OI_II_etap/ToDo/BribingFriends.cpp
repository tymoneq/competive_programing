#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int N, Moonies, Cones;
    const int INF = -1e9 + 5;
    struct Cow
    {
        int popularity, moonies, cones;
    };

    vector<Cow> Cows;
    vector<vector<int>> dp;

public:
    inline void read_data()
    {
        cin >> N >> Moonies >> Cones;
        Cows.resize(N);

        FOR(i, N, 0)
        cin >> Cows[i].popularity >> Cows[i].moonies >> Cows[i].cones;

        // set dp

        dp.resize(Moonies + 1);

        FOR(i, Moonies + 1, 0)
        dp[i].resize(Cones + 1, INF);

        FOR(i, Moonies + 1, 0)
        dp[i][0] = 0;
    }
    inline void solve()
    {
        read_data();

        for (auto cow : Cows)
            for (int moonie = Moonies; moonie >= 0; moonie--)
                for (int cone = Cones; cone >= 0; cone--)
                {
                    if (moonie >= cow.moonies)
                        dp[moonie][cone] = max(dp[moonie][cone], dp[moonie - cow.moonies][cone] + cow.popularity);

                    int used_cones = cow.cones;
                    int znizka = 1;
                    while (used_cones <= cone && znizka <= cow.moonies)
                    {
                        if (moonie - cow.moonies + znizka >= 0)
                            dp[moonie][cone] = max(dp[moonie][cone], dp[moonie - cow.moonies + znizka][cone - used_cones] + cow.popularity);
                        znizka++;
                        used_cones += cow.cones;
                    }
                }

        int mx = INF;
        for (int moonie = Moonies; moonie >= 0; moonie--)
            for (int cone = Cones; cone >= 0; cone--)
                mx = max(mx, dp[moonie][cone]);

        cout << mx << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve solution;
    solution.solve();

    return 0;
}