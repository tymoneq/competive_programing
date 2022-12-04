#include <bits/stdc++.h>

using namespace std;
long long dp[200][200];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<long long>> Plansza(n, vector<long long>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> Plansza[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int offside = 0; offside <= k; offside++)
                dp[i+ offside][j+k-offside] = max(Plansza[i][j] + Plansza[offside][k-offside], dp[offside][k-offside]);
    cout << dp[n][m];       
    return 0;
}