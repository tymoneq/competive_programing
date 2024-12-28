#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    map<int, int> mapa;

public:
    inline void solve()
    {
        FOR(i, 4, 0)
        {
            int a;
            cin >> a;
            mapa[a]++;
        }
        int threCnt = 0, twoCnt = 0;
        for (auto w : mapa)
        {
            if (w.second == 3)
                threCnt++;
            else if (w.second == 2)
                twoCnt++;
        }

        if (threCnt == 1 || twoCnt == 2)
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
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