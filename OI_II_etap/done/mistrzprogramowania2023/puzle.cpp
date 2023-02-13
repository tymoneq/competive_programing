#include <bits/stdc++.h>

using namespace std;
int N, sqr, mid;
inline bool valid(int val)
{
    bool fint = 0;
    for (int i = sqr; i < val; i++)
    {
        if (i == N)
            break;
        if (N % i == 0)
        {
            int h = N / i;

            if (i + h + 2 == val)
            {
                fint = 1;
                break;
            }

            else
            {
                int n_val = i + h + 2;
                if (mid > n_val)
                {
                    fint = 1;
                    mid = n_val;
                    break;
                }
            }
        }
    }
    return fint;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, hi, lo;
    long long res = 0, tmp;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> N;
        hi = N + 3;
        sqr = sqrt(N);
        lo = (sqr + N / sqr + 2);
        res = hi;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (valid(mid))
            {
                hi = mid - 1;
                res = mid;
            }
            else
                lo = mid + 1;
        }

        cout << (res * 2) << "\n";
    }
    return 0;
}