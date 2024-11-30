#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> A(n), PrefMAX(n);

    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end());

    int res = 0, l = 0, r = -1;

    while (r < n - 1)
    {
        if (r < l)
        {
            r++;
            int tmp = 0;
            if (r != 0)
                tmp += PrefMAX[l - 1];

            res = max(res, r - l + 1 + tmp);
        }
        else if (A[r + 1] <= A[l] + k)
        {
            r++;
            PrefMAX[r] = max(PrefMAX[r - 1], r - l + 1);
            res = max(res, r - l + 1 + PrefMAX[l - 1]);
        }
        else if (A[r + 1] > A[l] + k)
        {
            l++;
            res = max(res, r - l + 1 + PrefMAX[l - 1]);
        }
    }

    cout << res << '\n';

    return 0;
}