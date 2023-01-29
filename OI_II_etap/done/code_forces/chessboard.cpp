#include <bits/stdc++.h>
using namespace std;
const int MAX_VAL = 105;

char Chessboadrd[MAX_VAL][MAX_VAL];
char RES[MAX_VAL][MAX_VAL];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, tmp = 0;
    char val = 'W';
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> Chessboadrd[i][j];

    for (int i = 1; i <= n; i++)
    {
        RES[i][1] = val;
        for (int j = 2; j <= m; j++)
        {
            if (RES[i][j - 1] == 'W')
                RES[i][j] = 'B';
            else
                RES[i][j] = 'W';
        }
        if (val == 'W')
            val = 'B';
        else
            val = 'W';
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (Chessboadrd[i][j] == '-')
                RES[i][j] = '-';
        
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << RES[i][j];
        cout << "\n";
    }
    return 0;
}