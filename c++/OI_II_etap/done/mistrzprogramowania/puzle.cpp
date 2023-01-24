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
            for (int j = i + i; j < M; j += i)
                NotPrime[j] = 1;
    vector<int> Prime;
    for (int i = 2; i < M; i++)
        if (!NotPrime[i])
            Prime.push_back(i);
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        N = n;
        h = 1;
        long long res = (n + 3) * 2, tmp;
        int sqr = sqrt(n);
        if (sqr * sqr == n)
            tmp = (sqr + sqr + 2) * 2, res = min(res, tmp);
        for (int i = 0; i < Prime.size(); i++)
        {
            if (n % Prime[i] == 0)
            {
                h *= Prime[i];
                n /= Prime[i];
                tmp = (n + h + 2) * 2;
                res = min(res, tmp);
                i = -1;
            }
            if (h > n)
                break;
        }

        cout << res << "\n";
    }
    return 0;
}