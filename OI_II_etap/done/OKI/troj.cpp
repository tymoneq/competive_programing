#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 1010;

int V[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    ll res = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        V[a]++, V[b]++;
    }
    res = (n * (n - 1) * (n - 2)) / 6;
    ll tmp = 0;
    for (int i = 1; i <= n; i++)
        tmp += (V[i] * (n - 1 - V[i]));

    res -= (tmp / 2);
    cout << res << "\n";
    return 0;
}