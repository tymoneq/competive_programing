#include <bits/stdc++.h>
#include <cstdint>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t n, m, k;
    cin >> n >> m >> k;

    vector<vector<int64_t>> Nalesniki(n, vector<int64_t>(m));
    vector<vector<int64_t>> NalesnikiPref(n, vector<int64_t>(m));
    vector<int64_t> dp(k + 1, 0);
    vector<int64_t> dp_copy(k + 1, 0);

    for (int32_t i = 0; i < n; i++)
        for (int32_t j = 0; j < m; j++)
            cin >> Nalesniki[i][j];

    for (int32_t i = 0; i < n; i++)
        for (int32_t j = 0; j < m; j++)
            NalesnikiPref[i][j] =
                Nalesniki[i][j] + (j > 0 ? NalesnikiPref[i][j - 1] : 0);

    for (int32_t i = 0; i < n; i++) {
        for (int32_t j = 0; j < m; j++)
            for (int64_t val = k - (j + 1); val >= 0; val--) {
                dp_copy[val + j + 1] =
                    max(dp_copy[val + j + 1], NalesnikiPref[i][j] + dp[val]);
            }

        for (int32_t val = 0; val <= k; val++)
            dp[val] = max(dp[val], dp_copy[val]);
    }

    cout << dp[k] << '\n';

    return 0;
}