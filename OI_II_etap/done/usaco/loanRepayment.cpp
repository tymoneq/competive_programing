#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
ull N, K, M;
bool valid(ull val)
{
    ull G = 0, Y;
    ull k = K;
    while (k > 0 && G < N)
    {
        Y = (N - G) / val;
        if (Y < M)
        {
            long long leftover = ((N - G) + (M - 1)) / M;
            return leftover <= k;
        }

        long long max_match = N - (val * Y);
        long long num_days = min((max_match - G) / Y + 1, k);

        G += Y * num_days; // update values
        k -= num_days;
    }

    return G >= N;
}
int main()
{
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K >> M;
    ull lo = 1, hi = N, mid, ans = 1;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (valid(mid))
        {
            lo = mid + 1;
            ans = mid;
        }
        else
            hi = mid - 1;
    }
    cout << ans;
    return 0;
}