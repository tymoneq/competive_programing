#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    if (n > 5)
    {
        ll mid = (n + 1) / 2;
        if (mid % 2 == 0)
            mid++;
        ll left = mid - 1;
        ll right = n - mid;

        bool valid = true;

        while (left > 1)
        {
            if (left % 2 == 1)
            {
                valid = false;
                break;
            }
            left /= 2;
        }

        while (right > 1)
        {
            if (right % 2 == 1)
            {
                valid = false;
                break;
            }
            right /= 2;
        }

        if (valid)
            cout << mid << "\n";
        else
            cout << "impossible\n";
    }
    else
    {
        if (n <= 3)
            cout << 1 << "\n";
        else
            cout << 3 << "\n";
    }

    return 0;
}