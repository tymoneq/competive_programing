#include <bits/stdc++.h>
using namespace std;
constexpr int M = 2e5 + 10;
long long Num[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a;
    long long psums = 0;
    cin >> n;
    Num[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        psums += a;
        Num[(psums % n + n) % n]++;
    }
    long long res = 0;
    for (int i = 0; i <= n; i++)
    {
        res += Num[i] * (Num[i] - 1) / 2;
    }
    cout << res;
    return 0;
}