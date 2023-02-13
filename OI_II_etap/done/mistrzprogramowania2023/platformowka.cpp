#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<long long, long long>> f(2);
    cin >> f[0].first >> f[0].second >> f[1].first >> f[1].second;
    sort(f.begin(), f.end());
    if (f[0].second - f[1].first >= 0)
    {
        if (f[0].second <= f[1].second)
            cout << f[0].second - f[1].first;
        else
            cout << f[1].second - f[1].first;
    }
    else
        cout << "NIE";

    return 0;
}