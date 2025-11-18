#include <bits/stdc++.h>

using namespace std;
#define int long long

int lm, rm, lb, rb;

void solve()
{
}

int ile_takich_samych(int X)
{
    if (X <= lb + rb)
        return (X - 2 * lb + 1) / 2;
    return (2 * rb - X + 1) / 2;
}

int ile_mniejszych(int X)
{
    if (X <= lb + rb)
    {
        int ile = ile_takich_samych(X);
        int res = (1 + ile) * (ile);
        if ((X - 2 * lb + 1) % 2 == 0)
            res -= ile;
        return res;
    }
    else
    {
        int res = (ile_takich_samych(lb + rb) - 1) * ((ile_takich_samych(lb + rb) - 1) + 1);
        if ((rb - lb + 1) % 2 == 0)
            res += ile_takich_samych(rb + lb);
        else
            res += 3 * ile_takich_samych(rb + lb);
        int wart = ile_takich_samych(X);
        res += (wart + ile_takich_samych(rb + lb) - 1) * (ile_takich_samych(rb + lb) - wart);
        if (ile_takich_samych(X) != ile_takich_samych(rb + lb))
        {
            if ((X - (2 * lb + 1)) % 2 == 1)
                res -= ile_takich_samych(X);
        }
        return res;
    }
}

signed main()
{
    // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t; cin >> t;
    // while(t--) solve();
    int l, r;
    cin >> lm >> rm >> lb >> rb;
    int res = 0;
    int aktualna = lb + lb + 1 - lm;
    if (aktualna < 0)
        aktualna = 2 * lm + 1;
    else if (aktualna > rm)
    {
        cout << 0 << "\n";
        return 0;
    }
    else
        aktualna = lb + lb + 1;
    while (true)
    {
        int ile = ile_mniejszych(aktualna);
        int skok = ile - res;
        if (skok == 0)
            break;
        int nowa = min(rm + lm, aktualna + skok);
        res += skok - res;
    }
    cout << min(res, (lb + rb ) / 2);
    // l = lb;
    // r = rb;
    // map<int, int> mp;
    // for (int i = l; i <= r; i++)
    // {
    //     for (int j = i + 1; j <= r; j++)
    //         mp[i + j]++;
    // }
    // for (auto [x, y] : mp)
    // //     cout << x << " " << y << endl;
    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     int x;
    //     cin >> x;
    //     cout << "--> " << ile_mniejszych(x) << "\n";
    // }
}
