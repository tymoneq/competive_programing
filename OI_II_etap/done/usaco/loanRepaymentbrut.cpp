#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
ull N, K, M;
bool valid(ull val)
{
    ull G = 0, Y;
    for (ull i = 1; i <= K; i++)
    {
        Y = (N - G) / val;
        if (Y < M)
            Y = M;
        G += Y;
        if (G >= N)
            return 1;
    }
    return 0;
}
int main()
{
    // freopen("loan.in", "r", stdin);
    // freopen("loan.out", "w", stdout);
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