#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> Q(k + 2), P(k + 2), R(k + 2), MaxScores(k + 2), PowersOfTwo(k + 2);
    ll powerOfTwo = 4;

    for (int i = 2; i <= k + 1; i++)
    {
        Q[i] = (i - 1) * powerOfTwo;
        P[i] = (i - 2) * powerOfTwo;
        R[i] = (i - 1) * powerOfTwo - 4;
        powerOfTwo *= 2;
    }

    powerOfTwo = 1;
    for (int i = 0; i < k + 2; i++)
    {
        PowersOfTwo[i] = powerOfTwo;
        powerOfTwo *= 2;
    }

    for (int i = 2; i <= k + 1; i++)
        MaxScores[i] += R[i] + MaxScores[i - 1];

    while (n--)
    {
        int h;
        cin >> h;

        if ((h % 4 != 0 or MaxScores[k + 1] < h) or (4 > h))
        {
            cout << -1 << "\n";
            continue;
        }

        vector<ll> ans;

        int t = k + 1;
        int slots = k;
        while (t > 1)
        {

            if (P[t] <= h)
            {
                ans.push_back(PowersOfTwo[t]);
                ll special = Q[t];
                if (t == slots + 1)
                    special = R[t];

                ll tmp = min({(ll)h, special});
                slots--;
                h -= (tmp - tmp % 4);
                if (h == 0)
                    break;
            }
            else
                t--;
        }

        cout << ans.size() << " ";
        for (ll &a : ans)
            cout << a << " ";

        cout << "\n";
    }

    return 0;
}