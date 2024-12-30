#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

struct edge
{
    vector<int> Miecze;
    int to;
};

vector<vector<edge>> Graf;
vector<int> Dystanse;
vector<bool> Odwiedzone;
const int INF = 1e9 + 9;
class Solve
{
protected:
    int n, m, MaxDystans, iloscMieczy;

public:
    inline void read_data()
    {
        cin >> n >> m >> MaxDystans >> iloscMieczy;

        Graf.resize(n + 1 + (1 << (iloscMieczy + 1)));
        Dystanse.resize((n + 1) * (1 << (iloscMieczy + 1)), INF);
        Odwiedzone.resize(n + 1 + (1 << (iloscMieczy + 1)));

        vector<int> miecze;
        miecze.resize(iloscMieczy);
        FOR(i, m, 0)
        {
            int a, b;

            cin >> a >> b;
            FOR(j, iloscMieczy, 0)
            cin >> miecze[j];

            FOR(j, iloscMieczy, 0)
            {
                Graf[a + (1 << j)].push_back({miecze, b + (1 << j)});
                Graf[b + (1 << j)].push_back({miecze, a + (1 << j)});
            }
        }
    }

    inline void solve()
    {
        read_data();
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