#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int zD = 1;
    int zABC = 0;
    for (int i = 1; i <= n; i++)
    {
        int nzD = zABC * (ll)3 % MOD;
        int nzABC = (zABC * (ll)2 + zD) % MOD;

        zD = nzD;
        zABC = nzABC;
    }
    cout << zD << "\n";
}