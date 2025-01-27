#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    static const int M = 5e5 + 10;
    int N;
    int res = 0;

    vector<bool> Jednostki;

public:
    inline void solve()
    {
        cin >> N;

        Jednostki.resize(M);

        while (N--)
        {
            res = 0;
            int nowa_jednostka;

            cin >> nowa_jednostka;

            Jednostki[nowa_jednostka] = true;

            int nieparzyste = 0;
            int parzyste = 0;

            FOR(i, M - 5, 1)
            {
                if (!Jednostki[i])
                    continue;

                if (i % 2 == 0)
                    parzyste++;
                else
                    nieparzyste++;

                if (!Jednostki[i + 1])
                {
                    res += max(parzyste, nieparzyste);
                    parzyste = 0, nieparzyste = 0;
                }
            }

            cout << res << " ";
        }

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