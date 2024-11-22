#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll res = 0;
    unordered_map<ll, pair<ll, ll>> M; // first min second max

    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        if (M.find(x) == M.end())
        {
            M[x].first = y;
            M[x].second = y;
        }
        else
        {
            M[x].first = min(M[x].first, y);
            M[x].second = max(M[x].second, y);
            res = max(res, (M[x].second - M[x].first));
        }
    }
    cout << res << "\n";
    return 0;
}