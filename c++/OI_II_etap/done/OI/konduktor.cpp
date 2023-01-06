#include <bits/stdc++.h>
using namespace std;
const int MAXN = 600 + 7;
const int MAXK = 50 + 7;
const int INF = 2e9 + 7;
int stacje[MAXN][MAXN];
int pref[MAXN][MAXN];
int dp[MAXN][MAXK];
int poprz[MAXN][MAXK];
int n, k;
// ile pasazerow wsiadlo pomiedzy stacjami a oraz b wlacznie,
// a wysiadlo po stacji b
int sumaNaProstokacie(int i1, int j1, int i2, int j2)
{
    int wyn = +pref[i2][j2] - pref[i1 - 1][j2] - pref[i2][j1 - 1] + pref[i1 - 1][j1 - 1];
    return wyn;
}
// ile pasazerow wsiadlo pomiedzy stacjami a oraz b wlacznie,
// a wysiadlo po stacji b
int pasazerowie(int a, int b)
{
    int wyn = sumaNaProstokacie(a, b + 1, b, n);
    return wyn;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> stacje[i][j];

    // preprocessing - sumy prefiksowe 2D
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pref[i][j] = +pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + stacje[i][j];

    for (int ileKontroli = 1; ileKontroli <= k; ileKontroli++)
        dp[0][ileKontroli] = -INF;
    dp[0][0] = 0;
    // liczenie DP
    for (int i = 1; i < n; i++)
        for (int ileKontroli = 1; ileKontroli <= k; ileKontroli++)
            for (int j = i - 1; j >= 0; j--)
            {
                int wyn = dp[j][ileKontroli - 1] + pasazerowie(j + 1, i);
                if (wyn > dp[i][ileKontroli])
                {
                    dp[i][ileKontroli] = wyn;
                    poprz[i][ileKontroli] = j;
                }
            }

    // szukanie najlepszego wyniku
    int maxi = 0;
    for (int i = 1; i <= n; i++)
        if (dp[i][k] > dp[maxi][k])
            maxi = i;

    // odzyskiwanie wyniku
    vector<int> kontrole;
    int ind = maxi;
    for (int ileKontroli = k; ileKontroli > 0; ileKontroli--)
    {
        kontrole.push_back(ind);
        ind = poprz[ind][ileKontroli];
    }
    for (int i = kontrole.size() - 1; i >= 0; i--)
        cout << kontrole[i] << ' ';
    cout << '\n';
    return 0;
}