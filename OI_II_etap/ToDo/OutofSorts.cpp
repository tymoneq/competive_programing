#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int n;
    vector<int> Liczby;
    int ans = 0;

public:
    inline void read_data()
    {
        cin >> n;
        Liczby.resize(n);
        FOR(i, n, 0)
        cin >> Liczby[i];
    }
    inline void solve()
    {
        read_data();

        bool sorted = false;

        while (!sorted)
        {
            ans++;
            sorted = true;
            FOR(i, n - 1, 0)
            if (Liczby[i + 1] < Liczby[i])
                swap(Liczby[i], Liczby[i + 1]);

            for (int i = n - 2; i >= 0; i--)
                if (Liczby[i + 1] < Liczby[i])
                    swap(Liczby[i], Liczby[i + 1]);

            FOR(i, n - 1, 0)
            if (Liczby[i + 1] < Liczby[i])
                sorted = false;
        }

        cout << ans << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    Solve solution;
    solution.solve();

    return 0;
}