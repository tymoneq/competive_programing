#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e5 + 10;
int Height[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, mx;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> Height[i];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        mx = 0;
        for (int j = a; j <= b; j++)
            if (Height[j] - 1 == mx)
                mx++;
        cout << mx << "\n";
    }
}