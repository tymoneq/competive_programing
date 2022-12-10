#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct val
{
    ll val = 0;
    ll num1 = 0;
    ll num2 = 0;
};

int main()
{
    ll n;
    val max_val;
    ll  res = 0;

    cin >> n;
    for (ll i = n; i > n / 2; i--)
    {
        for (int j = i - 1; j >= n / 2; j--)
        {
            res = 0;
            if (i % j == 0)
                continue;
            if (i == 1 && j == 0)
                break;
            for (int k = 1; k * k <= n; k++)
            {
                if (i % k == 0 && j % k == 0)
                    res++;
                else if (i % k == 0)
                    res += 1;
                else if (j % k == 0)
                    res += 1;
            }
            if (max_val.val < res)
            {
                max_val.val = res;
                max_val.num1 = i;
                max_val.num2 = j;
            }
        }
    }

    if (max_val.val == 0)
        cout << 1 << "\n"
             << 1 << " " << 1;
    else
    {
        cout << max_val.val << "\n"
             << max_val.num1 << " " << max_val.num2;
    }
    return 0;
}