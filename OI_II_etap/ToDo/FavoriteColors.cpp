#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int N, M;
    vector<vector<int>> Graf;
    vector<int> Reprezentant;

public:
    inline int fint(int v) { return Reprezentant[v] == v ? v : fint(Reprezentant[v]); }

    inline void read_data()
    {
        cin >> N >> M;

        Graf.resize(N + 1);
        Reprezentant.resize(N + 1);

        FOR(i, M, 0)
        {
            int a, b;
            cin >> a >> b;
            Graf[b].push_back(a);
        }

        FOR(i, N + 1, 1)
        Reprezentant[i] = i;
    }

    inline void onion(int cowA, int cowB)
    {
        cowA = fint(cowA);
        cowB = fint(cowB);

        if (cowA == cowB)
            return;

        if (Graf[cowA].size() < Graf[cowB].size())
            swap(cowA, cowB);

        for (int w : Graf[cowB])
            Graf[cowA].push_back(cowB);

        Reprezentant[cowB] = cowA;
    }

    inline void solve()
    {
        read_data();

        FOR(i, N + 1, 1)
        while (Graf[i].size() > 1)
        {
            int cowA = Graf[i][Graf[i].size() - 1];
            int cowB = Graf[i][Graf[i].size() - 2];
            onion(cowA, cowB);
            Graf[i].pop_back();
        }

        int XD = 0;
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