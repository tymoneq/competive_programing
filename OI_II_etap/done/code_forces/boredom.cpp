#include <bits/stdc++.h>
using namespace std;
const int MAX_VAl = 1e5 + 10;
long long num[MAX_VAl];
long long dp[MAX_VAl];
long long m[MAX_VAl];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        m[num[i]]++;
    }

    dp[0] = 0;
    dp[1] = m[1];
    for (int i = 2; i < MAX_VAl; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + m[i] * i);

    cout << dp[100002];
    return 0;
}