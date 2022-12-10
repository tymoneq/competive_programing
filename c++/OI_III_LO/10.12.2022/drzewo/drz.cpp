#include <bits/stdc++.h>

using namespace std;
inline long long pot_szybkie(long long a, unsigned int n)
{
    long long w = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            w *= a;
            w %= 1000000009;
        }

        a *= a;
        a %= 1000000009;
        n /= 2; // skrócenie o jeden bit
    }
    return w;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, k, h, H;
    unsigned long long res = 0;
    unsigned long long base = 0, tmp = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> k >> h;
        res = 0, tmp = 0, base = 0;
        if (k == 0)
        {
            res = pot_szybkie(2, h) - 1;
            cout << res << "\n";
        }
        else if (k == h - 1)
            cout << h << "\n";
        else if (k >= 2)
        {
            res = h;
            H = h;
            while (H - k - 1 > 0)
            {
                res += H - k - 1;
                H--;
            }
            H = h;
            while (H - k - 1 > 0)
            {
                res += H - k - 1;
                H--;
            }

            cout << (res - 1) % 1000000009 << "\n"; // h + h - k - 1
        }
        else if (k == 1)
        {
            base = 2 * h - 2;
            if (h - 4 > 0)
                res += 2 * (h - 4) - 1;
            while (h - 3 > 0)
            {
                tmp = h - 3;
                if (tmp >= 3)
                {
                    res += 2 * (tmp - 2) - 1;
                }
                res += tmp;
                h--;
            }

            res = (base + res) % 1000000009;
            cout << res << "\n";
        }
    }

    return 0;
}