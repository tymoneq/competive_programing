#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, d, k;
    cin >> n >> m >> k >> d;

    vector<ll> Type(n + 1);

    while (m--)
    {
        ll rozmiar, x;
        cin >> rozmiar >> x;
        Type[rozmiar] += x;

        bool Can = 1;
        int r = 1, mxRange = 0, l = 0;
        ll sum = 0;

        while (r <= n && Can)
        {

            if (Type[r] != 0)
            {
                if (mxRange < r)
                {
                    mxRange = r + d;
                    sum = Type[r];
                    l = r;
                }
                else
                {
                    sum += Type[r];
                    mxRange = r + d;
                }
            }
            if (sum > (min(r + d, n) - l + 1) * k)
                Can = 0;
            r++;
        }

        cout << (Can ? "TAK" : "NIE") << "\n";
    }

    return 0;
}