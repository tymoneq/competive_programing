#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e5 + 10;
int Arr[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, n, res, sum, expect;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n >> expect;
        sum = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> Arr[i];
            if (Arr[i] == 1)
                sum++;
        }
        if (sum < expect)
            cout << -1 << "\n";
        else if (sum == expect)
            cout << 0 << "\n";
        else
        {
            int l = 0, r = n - 1;
            while (l <= r)
            {
                if (Arr[l] == 1)
                    sum--, l++, res++;
                if (sum == expect)
                    break;
                if (Arr[r] == 1)
                    sum--, r--, res++;
                if (sum == expect)
                    break;
                if (Arr[l] == 0)
                    res++, l++;
                else if (Arr[r] == 0)
                    res++, r--;
            }
            cout << res << "\n";
        }
    }

    return 0;
}