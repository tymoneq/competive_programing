#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr ll N = 1e7 + 10, MAXN = 1e12 + 10;
bool Prime[N], ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll x;
    vector<ll> P;
    memset(Prime, true, sizeof(Prime));
    for (ll i = 2; i * i < MAXN; i++)
        if (Prime[i] == 1)
        {
            P.push_back(i);
            if (i * i < N)
                for (ll j = i * i; j < N; j += i)
                    Prime[j] = 0;
        }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ans = 0;
        ll l = 0, r = P.size() - 1, mid = 0;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (P[mid] * P[mid] == x)
            {
                ans = 1;
                break;
            }
            else if (P[mid] * P[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}