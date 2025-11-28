#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr ll INF = 1e15 + 10;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N, Q;
        cin >> N >> Q;

        vector<ll> A(N + 1);
        for (int i = 1; i <= N; i++)
            cin >> A[i];

        vector<pair<ll, ll>> Ranges(N + 1);

        for (int i = 1; i <= N; i++)
            Ranges[i].second = INF;

        ll ans = INF;

        while (Q--)
        {
            ll r, l, p;
            cin >> p >> l >> r;

            if (Ranges[p].second < l || Ranges[p].first > r)
                ans = -1;
            

            Ranges[p].second = min(Ranges[p].second, r);
            Ranges[p].first = max(Ranges[p].first, l);
        }

        ll tmp = 0;

        for (int i = 1; i <= N; i++)
        {
            if (A[i] <= Ranges[i].second && A[i] >= Ranges[i].first)
                continue;

            tmp += min(abs(A[i] - Ranges[i].first), abs(A[i] - Ranges[i].second));
        }

        ans = min(ans, tmp);

        cout << ans << "\n";
    }

    return 0;
}