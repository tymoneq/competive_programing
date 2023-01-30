#include <bits/stdc++.h>

using namespace std;
long long dp[13];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    long long n, tmp, z;
    dp[1] = 26;
    for (int i = 2; i < 13; i++)
        dp[i] = dp[i - 1] + ((dp[i - 1]) * 26);
    cin >> T;
    vector<char> Res;
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        Res.clear();
        if (n > 26)
        {
            tmp = n / 27;
            Res.push_back('A' + tmp - 1);
            z = 0;
            if (tmp * 27 != n)
                for (int i = tmp * 27; i <= n; i++)
                    z++;
            if ((n + 1) % 27 == 0)
                z -= 2;
            Res.push_back('A' + z);
        }
        else
            Res.push_back('A' + n - 1);
        for (char z : Res)
            cout << z;
        cout << "\n";
    }
    return 0;
}