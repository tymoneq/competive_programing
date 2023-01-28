#include <bits/stdc++.h>

using namespace std;
const int M = 2e5 + 10;
long long Prefsum[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, a, b;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        Prefsum[i] = Prefsum[i - 1] + a;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a--;
        cout << Prefsum[b] - Prefsum[a] << "\n";
    }
    return 0;
}