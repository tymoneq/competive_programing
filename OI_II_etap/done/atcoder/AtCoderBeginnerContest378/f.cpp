#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 10;
typedef long long ll;

int STO[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    ll res = 0;

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        STO[a]++, STO[b]++;
    }

    ll sto_2 = 0, sto_3 = 0;

    for (int i = 1; i <= n; i++)
    {
        if (STO[i] == 2)
            sto_2++;
        if (STO[i] == 3)
            sto_3++;
    }

    res = (sto_2 * (sto_3 - 1)) * sto_3;
    res /= 2;

    cout << res << "\n";
    return 0;
}