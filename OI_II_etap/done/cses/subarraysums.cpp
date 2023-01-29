#include <bits/stdc++.h>

using namespace std;
const int M = 2e5 + 10;
int T[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, X;
    cin >> n >> X;
    for (int i = 0; i < n; i++)
        cin >> T[i];

    long long pref_sum = 0, res = 0;
    map<long long, int> sums;
    sums[0] = 1;
    for (int i = 0; i < n; i++)
    {
        pref_sum += T[i];
        res += sums[pref_sum - X];
        sums[pref_sum]++;
    }
    cout << res;
    return 0;
}