#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, res = numeric_limits<int>::max(), res_index = 0, aktual_sum = 0;
    cin >> n >> k;
    vector<int> Height(n);
    for (int i = 0; i < n; i++)
        cin >> Height[i];

    for (int i = 0; i < n - k; i++)
    {
        aktual_sum = 0;
        for (int j = i; j < i + k; j++)
            aktual_sum += Height[j];
        if (aktual_sum < res)
        {
            res = aktual_sum;
            res_index = i;
        }
    }
    cout << res_index + 1;
    return 0;
}