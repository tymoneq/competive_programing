#include <bits/stdc++.h>
using namespace std;

const int MAX_KLOCKOW = 1e6 + 10;

int dp[MAX_KLOCKOW]; 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> Weight(n);
    for (int i = 0; i < n; ++i)
        cin >> Weight[i];

    for (int i = 0; i <= s; ++i)
        dp[i] = -1;
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        if (Weight[i] > s)
            continue;
        for (int j = s - Weight[i]; j >= 0; --j)
        {
            if (dp[j] == -1)
                continue;
            if (dp[j + Weight[i]] == -1)
            {
                dp[j + Weight[i]] = dp[j] + 1;
                continue;
            }
            if (dp[j + Weight[i]] > dp[j])
                dp[j + Weight[i]] = dp[j] + 1;
        }
    }
    for (int j = s; j >= 0; --j)
    {
        if (dp[j] > 0)
        {
            if (dp[j] <= k)
            {
                cout << j << "\n";
                return 0;
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}