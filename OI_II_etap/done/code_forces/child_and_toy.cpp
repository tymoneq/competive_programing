#include <bits/stdc++.h>
using namespace std;
const int MAX_VAL = 1e3 + 10;

int Cost[MAX_VAL];
int Cost_of_Move[2 * MAX_VAL];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    long long res = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> Cost[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        Cost_of_Move[i] = min(Cost[a], Cost[b]);
    }
    for (int i = 1; i <= m; i++)
        res += Cost_of_Move[i];
    cout << res;
    return 0;
}