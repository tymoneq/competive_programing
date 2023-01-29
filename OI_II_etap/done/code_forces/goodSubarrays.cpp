#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
using ll = long long;
ll Num[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    long long res = 0, tmp_sum;
    cin >> t;
    char z;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        res = 0, tmp_sum = 0;
        for (int j = 1; j <= n; j++)
        {
            cin >> z;
            Num[j] = z - 48;
        }
        for (int j = 1; j <= n; j++)
            Num[j] += Num[j - 1];
        map<int, ll> sum_dist;
        for (int j = 0; j <= n; j++)
            sum_dist[Num[j] - j]++;
        for (auto el : sum_dist)
            res += el.second * (el.second - 1) / 2;
        cout << res << "\n";
    }
    return 0;
}