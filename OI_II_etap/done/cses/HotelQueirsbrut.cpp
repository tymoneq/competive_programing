#include <bits/stdc++.h>

using namespace std;
const int M = 2e5 + 10;
int Sums[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> Sums[i];
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        bool fint = 0;
        for (int j = 1; j <= n; j++)
            if (Sums[j] >= a)
            {
                cout << j << " ";
                fint = 1;
                Sums[j] -= a;
                break;
            }
        if (!fint)
            cout << 0 << " ";
    }
    return 0;
}