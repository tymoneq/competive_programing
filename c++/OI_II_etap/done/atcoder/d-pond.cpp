#include <bits/stdc++.h>
using namespace std;
const int M = 810;
long long Sum[M][M];
int Val[M][M];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, res = numeric_limits<int>::max(), aktual_res = 0, absolut_min = 0;
    cin >> n >> k;
    absolut_min = k * k / 2 + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> Val[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            Sum[i][j] = Val[i][j] + Sum[i][j - 1] + Sum[i - 1][j] - Sum[i - 1][j - 1];

    for (int i = k; i <= n; i++)
        for (int j = k; j <= n; j++)
        {
            aktual_res = Sum[i][j] - Sum[i - k - 1][j] - Sum[i][j - k - 1] + Sum[i - k][j - k];
            aktual_res = aktual_res / (k * k);
            res = min(res, aktual_res);
        }

    cout << res;
    return 0;
}