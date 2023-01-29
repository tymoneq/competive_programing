#include <iostream>

using namespace std;
int height[1000001], dp[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int maxi = 0, n, a, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> height[a];
        maxi = max(maxi, a);
    }
    for (int i = 0; i <= maxi; i++)
    {
        dp[i] = (i >= height[i] + 1 ? dp[i - height[i] - 1] : 0) + (height[i] == 0 ? 0 : 1);
        res = max(res, dp[i]);
    }
    cout << n - res;
}