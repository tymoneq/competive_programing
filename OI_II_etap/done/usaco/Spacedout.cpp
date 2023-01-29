#include <bits/stdc++.h>
using namespace std;
const int M = 1010;
int Grid[M][M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> Grid[i][j];

    int res = 0, res_col = 0;
    for (int i = 0; i < n; i++)
    {
        int sum[2]{};
        for (int j = 0; j < n; j++)
            sum[j % 2] += Grid[i][j];
        res += max(sum[0], sum[1]);
    }
    for (int i = 0; i < n; i++)
    {
        int sum[2]{};
        for (int j = 0; j < n; j++)
            sum[j % 2] += Grid[j][i];
        res_col += max(sum[0], sum[1]);
    }
    cout << max(res, res_col);
    return 0;
}