#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int n, m;
    vector<int> Type;
    vector<vector<int>> drzewo;

public:
    inline void solve()
    {
        cin >> n >> m;
        Type.resize(n + 1);
        drzewo.resize(n + 1);
        FOR(i, n + 1, 1)
        cin >> Type[i];

        FOR(i, n, 1)
        {
            int a, b;
            cin >> a >> b;
            drzewo[a].push_back(b);
            drzewo[b].push_back(a);
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