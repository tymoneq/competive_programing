#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, res = numeric_limits<int>::max(), res_index = 0, aktual_sum = 0;
    cin >> n >> k;
    vector<int> Height(n);
    vector<int> Pref_sum(n);
    for (int i = 0; i < n; i++)
        cin >> Height[i];
    Pref_sum[0] = Height[0];
    for (int i = 1; i < n; i++)
        Pref_sum[i] = Pref_sum[i - 1] + Height[i];

    for (int i = 0; i <= n - k; i++)
    {
        if (i != 0)
            aktual_sum = Pref_sum[i + k - 1] - Pref_sum[i - 1];
        else
            aktual_sum = Pref_sum[i + k - 1];
        if (aktual_sum < res)
        {
            res = aktual_sum;
            res_index = i;
        }
    }
    cout << res_index + 1;
    return 0;
}