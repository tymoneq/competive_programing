#include <bits/stdc++.h>
using namespace std;
constexpr int M = 3e4 + 10;

int Weight[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int w, n, res = 0, actual_sum = 0, k;
    cin >> w >> n;
    for (int i = 0; i < n; i++)
        cin >> Weight[i];
    k = n - 1;
    res = n;
    sort(Weight, Weight + n);
    for (int i = 0; i < n; i++)
        while (1)
        {
            if (k <= i)
                break;
            if (Weight[k] + Weight[i] <= w)
            {
                res--, k--;
                break;
            }
            if (Weight[k] + Weight[i] > w)
                k--;
        }

    cout << res;
    return 0;
}