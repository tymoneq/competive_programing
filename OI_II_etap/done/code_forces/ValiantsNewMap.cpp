#include <bits/stdc++.h>
#define rep(i, init, n) for (int i = init; i < (int)n; i++)
using namespace std;

int n, m;
inline bool valid(int mid, vector<vector<int>> Grid)
{
    vector<vector<int>> pre(n + 1, vector<int>(m + 1));
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (Grid[i][j] >= mid)
                Grid[i][j] = 1;
            else
                Grid[i][j] = 0;
            pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + Grid[i][j];
        }
    }
    rep(i, mid, n + 1)
    {
        rep(j, mid, m + 1)
        {
            int sum = pre[i][j] - pre[i][j - mid] - pre[i - mid][j] + pre[i - mid][j - mid];
            if (sum == mid * mid)
                return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, lo, mid, hi;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n >> m;
        vector<vector<int>> Grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> Grid[i][j];

        lo = 0, hi = min(n, m);
        int ans = 0;
        while (lo <= hi)
        {
            mid = (hi + lo) / 2;
            if (valid(mid, Grid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        cout << ans << "\n";
    }

    return 0;
}