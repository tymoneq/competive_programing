#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 10, MAXLOGN = 17;
int m[N][MAXLOGN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, l, r, pow2;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> m[i][0];
    for (int j = 1; j < MAXLOGN; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        pow2 = log2(r - l + 1);
        cout << min(m[l][pow2], m[r - (1 << pow2) + 1][pow2]) << "\n";
    }
    return 0;
}