#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int l, r, t, n;
    ll res = 0, x;

    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> Monsters(n);

        for (ll &a : Monsters)
            cin >> a;

        sort(Monsters.begin(), Monsters.end());
        l = 0, x = 0, res = 0, r = n - 1;

        while (l < r)
        {
            if (Monsters[l] == 0)
                l++;
            else if (x + Monsters[l] < Monsters[r])
            {
                res += Monsters[l];
                x += Monsters[l];
                l++;
            }
            else
            {
                ll tp = Monsters[r] - x;
                res += tp + 1;
                Monsters[l] -= tp;
                r--;
                x = 0;
            }
        }
        if (Monsters[l] == 0)
            res += 0;
        else if (Monsters[l] == 1)
            res++;
        else
        {
            ll tmp = (Monsters[l] - x) / 2;
            x += tmp;
            res += tmp + 1;
            Monsters[l] = Monsters[l] - tmp - x;
            if (Monsters[l] == 1)
                res++;
        }
        cout << res << "\n";
    }

    return 0;
}