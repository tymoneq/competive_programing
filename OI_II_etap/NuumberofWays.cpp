#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int N = 5e5 + 10;
ll Pref[N], Suf[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, left, right;
    ll sum_l = 0, sum_m = 0, sum_r = 0, ans = 0;
    cin >> n;
    vector<int> a(n);
    vector<int> A;
    for (int &b : a)
    {
        cin >> b;
        sum_m += b;
    }
    Pref[0] = a[0];
    Suf[n - 1] = a[n - 1];
    for (int i = 1; i < n - 1; i++)
        Pref[i] = Pref[i - 1] + a[i];

    for (int i = n - 2; i >= 0; i--)
    {
        Suf[i] = Suf[i + 1] + a[i];
        if (Suf[i] < Suf[i + 1])
            A.push_back(i+1);
    }

    left = 0, right = n - 1;
    sum_l = a[0];
    sum_r = a[n - 1];
    sum_m -= a[0] + a[n - 1];

    while (left < right - 1)
    {
        if (sum_l == sum_m && sum_l == sum_r)
        {

            // finding index in A
            int l = left + 2, r = right, mid, res = right;
            if (A.size() > 0)
            {
                int L = 0, R = A.size();
                while (L <= R)
                {
                    mid = L + (R - L) / 2;
                    if (A[mid] <= r)
                    {
                        res = mid;
                        L = mid + 1;
                    }
                    else
                        R = mid - 1;
                }
                l = max(l, A[res]);
            }

            res = right;
            while (l <= r)
            {
                mid = l + (r - l) / 2;

                if (Suf[mid] == sum_l && sum_l == Pref[mid - 1] - Pref[left])
                {
                    res = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            ans += right - res + 1;
            left++;
            sum_l += a[left];
            sum_m -= a[left];
        }
        else if (sum_l < sum_r)
        {
            left++;
            sum_l += a[left];
            sum_m -= a[left];
        }
        else
        {
            right--;
            sum_r += a[right];
            sum_m -= a[right];
        }
    }

    cout << ans << "\n";
    return 0;
}