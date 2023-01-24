#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, h, n, sqr;
    long long res = 0, tmp;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> n;
        res = (n + 3) * 2;
        sqr = sqrt(n);

        for (int i = sqr; i > 1; i--)
            if (n % i == 0)
            {
                h = i;
                n /= i;
                tmp = (n + h + 2) * 2;
                res = tmp;
                break;
            }
        cout << res << "\n";
    }
    return 0;
}