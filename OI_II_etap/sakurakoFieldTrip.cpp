#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int n;
    vector<vector<vector<int>>> minCost;
    vector<int> ludzie;

public:
    inline void calcState(int i, int val, int j)
    {
        int lewyStan = max(minCost[i - 1][0][0], (minCost[i - 1][0][1] == val ? minCost[i - 1][0][2] + 1 : 0));
        int prawyStan = max(minCost[i - 1][1][0], (minCost[i - 1][1][1] == val ? minCost[i - 1][1][2] + 1 : 0));

        minCost[i][j][0] = min(lewyStan, prawyStan);
        minCost[i][j][1] = val;
        if (lewyStan < prawyStan)

            minCost[i - 1][0][1] == val ? minCost[i][j][2] = minCost[i - 1][0][2] + 1 : 1;

        else
            minCost[i - 1][1][1] == val ? minCost[i][j][2] = minCost[i - 1][1][2] + 1 : 1;
    }

    inline int solve()
    {
        cin >> n;
        ludzie.resize(n + 1);
        FOR(i, n + 1, 1)
        cin >> ludzie[i];

        // resazing dp table
        minCost.resize(n + 1);
        FOR(i, n + 1, 0)
        {
            minCost[i].resize(2);
            FOR(j, 2, 0)
            minCost[i][j].resize(3);
        }

        minCost[0][0][0] = 0;
        minCost[0][1][0] = 0;

        FOR(i, n + 1, 1)
        {
            calcState(i, ludzie[i], 0);
            calcState(i, ludzie[n - i + 1], 1);
        }

        return min(minCost[n][0][0], minCost[n][1][0]);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        Solve solution;
        cout << solution.solve() << '\n';
    }

    return 0;
}