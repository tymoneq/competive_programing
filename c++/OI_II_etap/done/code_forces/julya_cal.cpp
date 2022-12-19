#include <bits/stdc++.h>

using namespace std;

const int MAX_VAL = 1e6 + 10;
long long dp[MAX_VAL];
int main()
{
    long long n;
    cin >> n;
    for (int i = 1; i < 10; i++)
        dp[i] = 1;
    dp[10] = 2;
    int maxi = 0, I = 0, tmp = 0;

    for (int i = 11; i < MAX_VAL; i++)
    {
        I = i;
        maxi = 0;
        while (I > 0)
        {
            tmp = I % 10;
            maxi = max(tmp, maxi);
            I /= 10;
        }
        dp[i] = dp[i - maxi] + 1;
    }
    cout << dp[n];
    return 0;
}
