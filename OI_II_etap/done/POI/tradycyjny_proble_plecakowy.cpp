#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int N = 1e4 + 10, K = 510;

ll plecak[N][K];

inline bool sorto(pair<int, ll> &lhs, pair<int, ll> &rhs)
{
    if (lhs.first == rhs.first)
        return lhs.second > rhs.second;
    return lhs.first < rhs.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, ll>> items(n);
    for (auto &el : items)
        cin >> el.first >> el.second;

    // sort(items.begin(), items.end(), sorto);

    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= k; w++)
        {
            if (items[i - 1].first > w)
                plecak[i][w] = plecak[i - 1][w];
            else
                plecak[i][w] = max(plecak[i - 1][w], plecak[i - 1][w - items[i - 1].first] + items[i - 1].second);
        }

    cout << plecak[n][k] << "\n";

    return 0;
}