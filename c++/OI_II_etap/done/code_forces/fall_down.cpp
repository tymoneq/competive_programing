#include <bits/stdc++.h>

using namespace std;
const int MAX_VAL = 52;
char Grid[MAX_VAL][MAX_VAL];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, tmp = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                cin >> Grid[j][k];

        for (int j = n - 2; j >= 0; j--)
            for (int k = 0; k < m; k++)
            {
                if (Grid[j][k] == '*')
                {
                    tmp = j;
                    while (tmp < n)
                    {
                        if (Grid[tmp + 1][k] == '.')
                            tmp++;
                        else
                        {
                            Grid[j][k] = '.';
                            Grid[tmp][k] = '*';
                            break;
                        }
                    }
                }
            }

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
                cout << Grid[j][k];
            cout << "\n";
        }
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                Grid[j][k] = '*';
    }

    return 0;
}