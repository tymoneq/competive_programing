#include <bits/stdc++.h>
using namespace std;

char TAB[110][1010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, x, y, res = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        res = 0;
        cin >> n >> m >> x >> y;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                cin >> TAB[j][k];
        if (y >= 2 * x)
        {
            for (int j = 0; j < n; j++)
                for (int k = 0; k < m; k++)
                    if (TAB[j][k] == '.')
                        res += x;
        }
        else
        {
            for (int j = 0; j < n; j++)
                for (int k = 0; k < m; k++)
                {
                    if (k + 1 < m && TAB[j][k] == '.' && TAB[j][k + 1] == '.')
                    {
                        res += y;
                        k++;
                    }
                    else if (TAB[j][k] == '.')
                        res += x;
                }
        }

        cout << res << "\n";
    }

    return 0;
}