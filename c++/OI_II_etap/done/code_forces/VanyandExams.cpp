#include <bits/stdc++.h>
using namespace std;

inline bool sorto(pair<int, int> &lhs, pair<int, int> &rhs) { return lhs.second < rhs.second; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long  n, r, avg, a, b, actual = 0, required = 0, res = 0;
    cin >> n >> r >> avg;
    vector<pair<int, int>> Points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        Points[i] = make_pair(a, b);
        actual += a;
    }
    if (actual / n >= avg)
    {
        cout << 0;
        return 0;
    }
    required = avg * n - actual;
    sort(Points.begin(), Points.end(), sorto);
    int i = 0;
    while (required > 0)
    {
        if (Points[i].first < r)
        {
            if (required - r + Points[i].first < 0)
            {
                res += required * Points[i].second;
                break;
            }
            required -= r - Points[i].first;
            res += (r - Points[i].first) * Points[i].second;
        }
        i++;
    }
    cout << res;
    return 0;
}