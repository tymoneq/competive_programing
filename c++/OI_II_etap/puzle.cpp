#include <bits/stdc++.h>

using namespace std;
const int M = 1e7 + 10;
bool NotPrime[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, h, n, N, H;
    cin >> T;
    for (int i = 2; i * i < M; i++)
        if (!NotPrime[i])
            for (int j = i * i; j < M; j += i)
                NotPrime[j] = 1;
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        N = n;
        h = 1;
        long long res = (n + 3) * 2, tmp;
        int sqr = sqrt(N);
        if (NotPrime[n])
            for (int i = sqr; i > 1; i--)
            {
                if (N % i == 0)
                {
                    n = N;
                    h = i;
                    n /= i;
                    tmp = (n + h + 2) * 2;
                    res = min(res, tmp);
                    break;
                }
            }
        cout << res << "\n";
    }
    return 0;
}