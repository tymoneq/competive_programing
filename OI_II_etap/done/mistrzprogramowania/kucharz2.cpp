#include <bits/stdc++.h>

using namespace std;
const int M = 1e6 + 10;
int W[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, a, b;
    int res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> W[i];

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a--;
        res = W[b] - W[a];
        cout << res << "\n";
    }
    return 0;
}