#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    int N, M;

    vector<vector<int>> Planety;
    ll res = 0;

public:
    inline void read_data()
    {
        cin >> N >> M;

        Planety.resize(N, vector<int>(M));

        FOR(i, N, 0)
        FOR(j, M, 0)
        cin >> Planety[i][j];
    }

    inline void solve()
    {
        read_data();

        bool czyZero = false;

        ll curent_res = 0;

        FOR(i, N, 0)
        {
            if (Planety[i][0] == 1)
            {
                if (czyZero)
                    curent_res++;

                czyZero = false;
            }
            if (Planety[i][0] == 0)
                czyZero = true;
        }
        res = curent_res;

        curent_res = 0;
        
        czyZero = false;
        for (int i = N - 1; i >= 0; i--)
        {
            if (Planety[i][0] == 1)
            {
                if (czyZero)
                    curent_res++;

                czyZero = false;
            }
            if (Planety[i][0] == 0)
                czyZero = true;
        }
        cout << max(res, curent_res) << '\n';
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