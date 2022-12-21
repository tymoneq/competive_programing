#include <bits/stdc++.h>
using namespace std;
const int MAX_VAl = 1e5 + 10;
long long Sum[MAX_VAl];
long long dp[MAX_VAl];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    for (int i = 0; i < n; i++)
        Sum[num[i]] += num[i];
    dp[1] = Sum[1];
    for (int i = 2; i < MAX_VAl; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + Sum[i]);

    cout << dp[n];
    return 0;
}