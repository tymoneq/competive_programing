#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> drewno(n);
    int total_sum = 0;

    for (int &a : drewno)
    {
        cin >> a;
        total_sum += a;
    }

    sort(drewno.begin(), drewno.end());
    int last_element = drewno[n - 1];
    vector<vector<int>> dp(n+1, vector<int>((total_sum - last_element + 1) / 2));

    for (int i = 1; i < n; i++)
        for (int w = 0; w <= (total_sum - last_element + 1) / 2; w++)
        {
            if (w < drewno[i - 1])
                dp[i][w] = dp[i - 1][w];

            else
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - drewno[i - 1]] + drewno[i - 1]);
        }

    cout << dp[n - 1][(total_sum - last_element + 1) / 2 -1] + last_element << "\n";
    return 0;
}