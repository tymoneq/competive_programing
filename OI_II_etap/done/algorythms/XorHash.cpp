#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> h(1e6 + 10);

inline void solve()
{
    int n, q, a;
    cin >> n >> q;
    vector<ll> A(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        A[i] = h[a];
        A[i] ^= A[i - 1];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        ll ans = A[r] ^ A[l - 1];
        cout << (ans == 0 ? "YES" : "NO") << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<int64_t> dist(0, INT64_MAX);

    for (auto &x : h)
        x = dist(gen);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}