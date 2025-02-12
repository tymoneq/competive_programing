#include <bits/stdc++.h>

using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    struct range
    {
        int pocz, koniec;
    };

    const int A = 'z' - 'a' + 1;
    int N;
    string tmp, S;

    vector<vector<int>> PrefixSum;

    vector<int> dp;
    vector<int> Move;

    vector<range> Przedzialy;

public:
    inline void read_data()
    {
        cin >> N;

        PrefixSum.resize(A, vector<int>(N + 2));

        cin >> tmp;

        S = '#' + tmp;

        dp.resize(N + 1);
        Move.resize(N + 1);
    }

    inline void solve()
    {
        read_data();

        FOR(i, A, 0)
        FOR(j, N + 1, 1)
        PrefixSum[i][j] += PrefixSum[i][j - 1] + (S[j] == 'a' + i ? 1 : 0);

        dp[1] = 1;
        Move[1] = 0;

        FOR(i, N + 1, 2)
        {
            dp[i] = 1;
            Move[i] = i - 1;
            FOR(j, i, 1)
            {
                int cnt_nieparzyste = 0;

                FOR(c, A, 0)
                if ((PrefixSum[c][i] - PrefixSum[c][j - 1]) % 2 == 1)
                    cnt_nieparzyste++;

                if (cnt_nieparzyste > 1)
                    continue;

                int dl = min(dp[j - 1], i - j + 1);

                if (dp[j - 1] == 0)
                    dl = i - j + 1;

                if (dp[i] < dl)
                {
                    dp[i] = dl;
                    Move[i] = j;
                }
            }
        }

        cout << dp[N] << '\n';

        int skok = Move[N];
        int new_last_element = skok - 1;

        Przedzialy.push_back({skok, N});

        while (new_last_element > 0)
        {
            skok = Move[new_last_element] - 1;
            Przedzialy.push_back({skok + 1, new_last_element});
            new_last_element = skok;
        }

        cout << Przedzialy.size() << '\n';

        for (int i = Przedzialy.size() - 1; i >= 0; i--)
            cout << Przedzialy[i].pocz << " " << Przedzialy[i].koniec << '\n';

        // // tylko dla 50% punktów

        // cout << 1 << '\n'
        //      << 1 << " " << N << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve s;
    s.solve();

    return 0;
}