#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int n;
    vector<vector<int>> Tree;
    int maxSnowflake = 0;

public:
    inline void calc_res(int v, int p)
    {
        for (int w : Tree[v])
            if (w != p)
                calc_res(w, v);

        vector<int> vals;
        for (int w : Tree[v])
            vals.push_back(Tree[w].size() - 1);

        sort(vals.begin(), vals.end());
        int tmp = 0;

        for (int i = 0; i < vals.size(); i++)
        {
            tmp = vals[i] * (vals.size() - i);
            maxSnowflake = max(maxSnowflake, (int)(tmp + 1 + (vals.size() - i)));
        }
    }

    inline void solve()
    {
        cin >> n;

        Tree.resize(n + 1);
        FOR(i, n, 1)
        {
            int a, b;
            cin >> a >> b;
            Tree[a].push_back(b);
            Tree[b].push_back(a);
        }

        calc_res(1, 1);
        cout << n - maxSnowflake << '\n';
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