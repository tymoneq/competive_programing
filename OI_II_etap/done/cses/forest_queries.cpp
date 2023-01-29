#include <bits/stdc++.h>
using namespace std;
const int M = 1011;
int Grid[M][M];
int Pref_sum[M][M];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char a;
    int n, q, x1, y1, x2, y2, res = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            if (a == '*')
                Grid[i][j] = 1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            Pref_sum[i][j] = Pref_sum[i - 1][j] + Pref_sum[i][j - 1] - Pref_sum[i - 1][j - 1] + Grid[i][j];

    for (int i = 0; i < q; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        res = Pref_sum[x2][y2];
        res -= Pref_sum[x1 - 1][y2];
        res -= Pref_sum[x2][y1 - 1];
        res += Pref_sum[x1 - 1][y1 - 1];
        cout << res << "\n";
    }
    return 0;
}