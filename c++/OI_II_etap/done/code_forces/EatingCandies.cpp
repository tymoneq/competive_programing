#include <bits/stdc++.h>

using namespace std;
const int M = 2e5 + 10;
int Num[M], pre[M], post[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, n, l, r, res, current;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> Num[i];
            pre[i] = Num[i];
            if (i > 0)
                pre[i] += pre[i - 1];
        }
        post[n - 1] = Num[n - 1];
        for (int i = n - 2; i >= 0; i--)
            post[i] = post[i + 1] + Num[i];
        l = 0, r = n - 1, res = 0, current = 2;
        while (l < r)
        {
            if (pre[l] < post[r])
            {
                l++;
                current++;
            }
            else if (pre[l] > post[r])
            {
                r--;
                current++;
            }
            else if (pre[l] == post[r])
            {
                res = max(res, current);
                r--;
                current++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}