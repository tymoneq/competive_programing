#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e5 + 10, C = 20;
char Field[M][C];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, n;
    cin >> c >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < c; j++)
            cin >> Field[i][j];

    int mx = 0, cur = 0;
    for (int i = 0; i < n; i++)
    {
        mx = 0;
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                cur = 0;
                for (int k = 0; k < c; k++)
                    if (Field[i][k] != Field[j][k])
                        cur++;
                mx = max(mx, cur);
            }
        cout << mx << "\n";
    }
    return 0;
}