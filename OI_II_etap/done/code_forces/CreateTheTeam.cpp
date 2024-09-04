#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline bool sorto(ll &lhs, ll &rhs) { return lhs > rhs; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    ll x;

    cin >> t;
    while (t--)
    {
        cin >> n >> x;

        vector<ll> Nums(n);
        for (auto &el : Nums)
            cin >> el;

        sort(Nums.begin(), Nums.end(), sorto);

        int res = 0, length = 1;
        for (int i = 0; i < n; i++)
        {
            if (Nums[i] >= x)
                res++;
            else if (Nums[i] * length >= x)
            {
                res++;
                length = 1;
            }
            else
                ++length;
        }

        cout << res << "\n";
    }

    return 0;
}