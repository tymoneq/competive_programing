#include <bits/stdc++.h>
using namespace std;

int Banknotes[15];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t, n, k, h, res;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        if (n == 0)
            continue;
        h = n - 1;
        res = 0;
        for (int j = 0; j < n; j++)
            cin >> Banknotes[j];

        while (k != 0)
        {
            if (k / Banknotes[h] >= 0)
            {
                res += k / Banknotes[h];
                k -= Banknotes[h] * (k / Banknotes[h]);
                h--;
            }
        }
        cout << res << "\n";
    }
    return 0;
}