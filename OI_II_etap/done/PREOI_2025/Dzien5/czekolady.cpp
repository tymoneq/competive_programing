#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    const int INF = 1e9 + 5;
    int X;
    string s;
    vector<int> Pref;
    vector<int> dp;
    vector<int> last_move;

    vector<int> Ans;

public:
    inline void solve()
    {
        cin >> X >> s;

        Pref.resize(s.size() + 1);
        dp.resize(X + 1, INF);
        last_move.resize(X + 1);
        Ans.resize(s.size());

        FOR(i, s.size(), 0)
        Pref[i + 1] = Pref[i] + (s[i] == 'T' ? 1 : 0);

        dp[0] = 0;
        last_move[0] = 0;

        for (int k = s.size(); k > 0; k--)
            FOR(i, X + 1, 0)
            {
                if (i + k > X)
                    break;

                if (dp[i + k] > dp[i] + Pref[k])
                {
                    dp[i + k] = dp[i] + Pref[k];
                    last_move[i + k] = k;
                }
            }

        cout << dp[X] << '\n';

        int id = X;
        while (id != 0)
        {
            FOR(i, last_move[id], 0)
            Ans[i]++;

            id -= last_move[id];
        }

        for (int w : Ans)
            cout << w << " ";

        cout << '\n';
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