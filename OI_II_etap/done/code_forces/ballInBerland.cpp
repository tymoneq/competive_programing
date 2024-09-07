#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 2e5 + 10;

set<int> Graph[N];

int Occurance[N], TotalSum[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> Boys;
    int t, a, b, k, g;
    ll res;

    cin >> t;
    while (t--)
    {
        res = 0;

        Boys.clear();

        cin >> a >> b >> k;

        Boys.resize(k);
        for (int &i : Boys)
            cin >> i;

        for (int i = 0; i < k; i++)
        {
            cin >> g;
            Occurance[g]++;
            Graph[Boys[i]].insert(g);
        }

        for (int i = a; i > 0; i--)
            TotalSum[i] = TotalSum[i + 1] + Graph[i].size();

        for (int i = 1; i < a; i++)
            for (auto el : Graph[i])
            {
                --Occurance[el];
                res += TotalSum[i + 1] - Occurance[el];
            }

        cout << res << "\n";
        for (int i = 0; i <= a; i++)
        {
            Graph[i].clear();
            TotalSum[i] = 0;
        }
        for (int i = 0; i <= b; i++)
            Occurance[i] = 0;
    }
    return 0;
}