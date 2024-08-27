#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll ans, current_denominator, tmp, K;
    int t, n, x;
    vector<ll> numbers;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> K;
        ans = 0, current_denominator = 0;
        numbers.clear();
        numbers.resize(n);
        for (int i = 0; i < n; i++)
            cin >> numbers[i];

        current_denominator = numbers[0];
        for (int i = 1; i < n; i++)
        {
            x = 0;
            if (numbers[i] % K != 0)
                x++;
            if ((numbers[i] * 100 / K) + x > current_denominator)
            {
                x = 0;
                tmp = (numbers[i] * 100);
                if (tmp % K != 0)
                    x++;
                tmp = tmp / K + x - current_denominator;
                current_denominator += tmp;
                ans += tmp;
            }

            current_denominator += numbers[i];
        }

        cout << ans << "\n";
    }

    return 0;
}