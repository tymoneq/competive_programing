#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e6 + 10;
bool NotPrime[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, mx = 0;
    char z;
    cin >> n;
    vector<int> prime;
    for (int i = 2; i * i < n; i++)
        if (!NotPrime[i])
            for (int j = i + i; j < n; j += i)
                NotPrime[j] = 1;
    for (int i = 2; i <= n; i++)
        if (!NotPrime[i])
            prime.push_back(i);
    vector<vector<int>> dp(n + 2, vector<int>(prime.size() + 2));
    vector<bool> Points(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> z;
        if (z == '#')
            Points[i] = 1;
    }

    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < prime.size(); j++)
        {
            if (i + prime[j] <= n)
            {
                if (Points[i])
                    dp[i][j] = dp[i + prime[j]][j] + 1;
                else
                    dp[i][j] = dp[i + prime[j]][j];
            }
            else
            {
                if (Points[i])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            mx = max(mx, dp[i][j]);
        }
    }

    cout << mx;
    return 0;
}