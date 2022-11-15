#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
// time complexy O(n)
/*
unsigned long long getNthUgly_num(ull n)
{
    vector<ull> ugly(n);
    ull i2 = 0, i3 = 0, i5 = 0;
    ull next_2 = 2, next_3 = 3, next_5 = 5, next_ugly_num = 1;
    ugly[0] = 1;
    for (int i = 1; i < n; i++)
    {
        next_ugly_num = min(next_2, min(next_3, next_5));
        ugly[i] = next_ugly_num;
        if (next_ugly_num == next_2)
        {
            i2 += 1;
            next_2 = ugly[i2] * 2;
        }
        if (next_ugly_num == next_3)
        {
            i3 += 1;
            next_3 = ugly[i3] * 3;
        }
        if (next_ugly_num == next_5)
        {
            i5 += 1;
            next_5 = ugly[i5] * 5;
        }
    }
    return next_ugly_num;
}
*/
// Time complexy O(logN)

int getNthUgly_num(int n)
{
    int poww[40] = {1};
    for (int i = 1; i <= 30; i++)
        poww[i] = poww[i - 1] * 2;
    int l = 1, r = numeric_limits<int>::max();
    int ans = -1;
    while (l <= r)
    {
        int mid = l + ((r - l) / 2);
        int cnt = 0;
        for (ull i = 1; i <= mid; i *= 5)
        {
            for (ull j = 1; j * i <= mid; j *= 3)
            {
                cnt += upper_bound(poww, poww + 31, mid / (i * j)) - poww;
            }
        }
        if (cnt < n)
            l = mid + 1;
        else
            r = mid - 1, ans = mid;
    }
    return ans;
}

int main()
{
    ull n;
    cin >> n;
    cout << getNthUgly_num(n);
    return 0;
}