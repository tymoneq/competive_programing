#include <bits/stdc++.h>

using namespace std;
inline vector<int> To_bin(int a, int k)
{
    int h = k - 1;
    vector<int> Num(k);
    while (a > 0)
    {
        if (a % 2 != 0)
            Num[h] = 1;
        h--;
        a /= 2;
    }
    return Num;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t, n, x, h, c, b;
    long long res;
    vector<int> bin_1, bin_2;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> x;
        if (n < x)
            cout << -1 << "\n";
        else if (n == x)
            cout << n << "\n";
        else
        {
            res = 0;
            c = log2(n) + 1;
            h = c - 1;
            bin_1 = To_bin(n, c);
            bin_2 = To_bin(x, c);
            for (int j = c - 1; j >= 0; j--)
            {
                if (bin_1[j] != bin_2[j])
                {
                    b = 0;
                    for (int k = c - 1; k > j; k--)
                    {
                        if (bin_1[k] == 1)
                        {
                            res += 2 * b;
                        }
                        b++;
                    }
                    res -= (b+1)*2;
                    res += (b+2) * 2;
                    break;
                }
            }
            res += n;
            cout << res << "\n";
        }
    }
    return 0;
}