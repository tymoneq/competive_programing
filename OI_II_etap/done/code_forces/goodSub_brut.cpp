#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
int Num[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    long long res = 0, tmp_sum;
    cin >> t;
    char z;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        res = 0, tmp_sum = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> z;
            Num[j] = z - 48;
        }
        for (int j = 0; j < n; j++)
        {
            tmp_sum = 0;
            for (int h = j; h < n; h++)
            {
                tmp_sum += Num[h];
                if (tmp_sum == h - j + 1)
                    res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}