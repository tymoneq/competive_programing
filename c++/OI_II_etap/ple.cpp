#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline bool sorto(pair<ll, int> &lhs, pair<ll, int> &rhs) { return lhs.first > rhs.first; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    cin >> n;
    vector<int> Weight(n);
    vector<ll> res;
    vector<ll> Pref(n, 0);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> Weight[i];
        sum += Weight[i];
    }
    res.push_back(sum);
    vector<pair<ll, int>> l_sums;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll left_sum = 0;
            for (int k = j + 1; k < n; k++)
            {
                left_sum += Weight[k];
                if ((Weight[j] - left_sum) <= 0)
                    break;
            }
            if (Weight[j] - left_sum > 0)
                l_sums.push_back(make_pair(left_sum, j));
        }
        sort(l_sums.begin(), l_sums.end(), sorto);
        auto el = l_sums[0];
        res.push_back(res[i - 1] - Weight[el.second]);
        Weight[el.second] = 0;
        l_sums.clear();
    }
    for (int i = n-1; i >= 0; i--)
        cout << res[i] << " ";
    return 0;
}