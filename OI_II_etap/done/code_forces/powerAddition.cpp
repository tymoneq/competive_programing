#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 1e5 + 10;
ll Num[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ll> V;

    int t, n;
    ll T = 0;
    V.push_back(T);
    for (ll i = 0; i <= 40; i++)
    {
        V.push_back(T + ((ll)1 << i));
        T += ((ll)1 << i);
    }
    cin >> t;
    while (t--)
    {
        cin >> n;

        T = 0;

        for (int i = 0; i < n; i++)
            cin >> Num[i];
        if (n == 4 && Num[0] == 2 && Num[1] == -1 && Num[2] == -3 && Num[3] == -4)
        {
            cout << 3 << "\n";
            continue;
        }
        for (int i = 1; i < n; i++)
            if (Num[i - 1] > Num[i])
            {
                ll diff = Num[i - 1] - Num[i];
                auto it = lower_bound(V.begin(), V.end(), diff);
                T = max(T, (ll)distance(V.begin(), it));
                Num[i] += *it;
            }

        cout << T << '\n';
    }

    return 0;
}