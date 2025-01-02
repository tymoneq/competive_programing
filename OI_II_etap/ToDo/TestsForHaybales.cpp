#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    const ll MAXVAL = 1e18;
    int N;
    vector<int> zaleznosci;
    vector<vector<int>> Graf;
    vector<int> Parent;

    struct ranges
    {
        ll poczontek, koniec;
    };

public:
    inline void read_data()
    {
        cin >> N;
        zaleznosci.resize(N + 1);
        Graf.resize(N + 1);
        Parent.resize(N + 2);

        FOR(i, N + 1, 1)
        {
            cin >> zaleznosci[i];
            Parent[i] = (zaleznosci[i] == i ? i + 1 : zaleznosci[i]);
        }
        FOR(i, N + 1, 1)
        if (zaleznosci[i] != i)
            Graf[zaleznosci[i]].push_back(i);
    }

    inline int valid(ll mid)
    {
        vector<ranges> Values(N + 2);
        Values[N] = {MAXVAL, MAXVAL};
        Values[N + 1] = {MAXVAL + mid, MAXVAL + mid};
        bool correct = 1;
        for (int i = N; i > 0; i--)
        {
            if (zaleznosci[i] == i && i != N)
                Values[i] = {max(Values[i + 1].poczontek - mid - 1, (ll)-10), max(Values[i + 1].koniec - mid - 1, (ll)-10)};

            for (int w : Graf[i])
            {
                if (Graf[w].size() == 0)
                {
                    Values[w].poczontek = max(Values[i].poczontek - mid, (ll)-10);
                    if (zaleznosci[i] == i)
                        Values[w].koniec = Values[i].koniec;
                    else
                        Values[w].koniec = Values[i].koniec - 1;
                }
                else
                    Values[w] = {max(Values[i].poczontek - mid, (ll)-10), max(Values[Parent[i]].koniec - mid - 1, (ll)-10)};
            }
        }

        FOR(i, N, 1)
        {
            if (Values[i].koniec < 0)
            {
                correct = 0;
                break;
            }
            if (Values[i].koniec > Values[i + 1].koniec)
            {
                correct = 0;
                break;
            }
        }
        if (correct)
        {
            cout << mid << '\n';

            FOR(i, N + 1, 1)
            cout << Values[i].koniec << '\n';

            return 0;
        }

        return 1;
    }

    inline void solve()
    {
        read_data();

        ll loK = 1, hiK = MAXVAL, mid;

        while (loK <= hiK)
        {
            mid = loK + (hiK - loK) / 2;

            int ans = valid(mid);

            if (ans == 0)
                break;
            else
                hiK = mid - 1;
        }
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