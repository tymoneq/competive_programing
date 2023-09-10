#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

constexpr int M = 5e5 + 10;
ull Cost[M], leftCost[M], rightCost[M];
bool Off[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> Cost[i];
    for (int i = 1; i < n; i++)
        cin >> rightCost[i];
    for (int i = 2; i <= n; i++)
        cin >> leftCost[i];
    ull res = 0;
    vector<int> Order;
    ull cost;
    for (int i = 1; i <= n; i++)
    {
        pair<ull, int> MX; // first val second index
        MX.first = numeric_limits<ull>::max();
        for (int j = 1; j <= n; j++)
        {
            if (Off[j])
                continue;
            cost = 0;
            if (!Off[j - 1])
                cost += leftCost[j];
            if (!Off[j + 1])
                cost += rightCost[j];
            if (cost < MX.first)
            {
                MX.first = cost;
                MX.second = j;
            }
        }
        res += Cost[MX.second];
        Off[MX.second] = 1;
        Cost[MX.second - 1] += leftCost[MX.second];
        Cost[MX.second + 1] += rightCost[MX.second];
        Order.push_back(MX.second);
    }
    cout << res << "\n";

    for (int w : Order)
        cout << w << " ";
    return 0;
}