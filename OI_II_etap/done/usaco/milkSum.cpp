#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int M = 20 + 10;
int UnsortedCows[M], Days[M], IND[M];
ll Prefsum[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, a, b;
    vector<pair<ll, ll>> Cows;
    cin >> n;
    Cows.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Cows[i].first;
        Cows[i].second = i;
    }

    cin >> q;
    for (int i = 0; i < n; i++)
        UnsortedCows[i] = Cows[i].first;
    sort(Cows.begin(), Cows.end());
    ll T = 0;
    for (ll i = 0; i < n; i++)
    {
        T += (i + 1) * Cows[i].first;
        Days[Cows[i].second] = i + 1;
        IND[Cows[i].second] = i;
    }
    Prefsum[0] = Cows[0].first;
    for (int i = 1; i < n; i++)
        Prefsum[i] = Prefsum[i - 1] + Cows[i].first;

    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        int lo = 0, hi = n - 1, mid, ans = 0;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (Cows[mid].first >= b)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        ll res;
        ll cost = 0;
        if (ans == IND[a - 1])
            res = T + (ans + 1) * b - (UnsortedCows[a - 1] * Days[a - 1]);
        else if (ans < IND[a - 1])
        {
            cost = abs(Prefsum[ans-1] - Prefsum[IND[a - 1] - 1]);
            res = T + (ans + 2) * b - (UnsortedCows[a - 1] * Days[a - 1]) + cost;
        }
        else
        {
            cost = Prefsum[ans - 1] - Prefsum[IND[a - 1]];
            res = T + (ans) * b - (UnsortedCows[a - 1] * Days[a - 1]) - cost;
        }

        cout << res << "\n";
    }

    return 0;
}