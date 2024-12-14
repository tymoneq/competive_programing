#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef unsigned long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll S, sum = 0;
    cin >> n >> S;

    vector<ll> a(n);
    for (ll &w : a)
    {
        cin >> w;
        sum += w;
    }

    S %= sum;

    int head = -1, tail = 0;
    ll curent_sum = (ll)0;

    bool T = 0;

    while (tail < n)
    {
        if (head < tail)
        {
            head++;
            curent_sum += a[head];
        }
        else if (head == n - 1)
        {
            curent_sum -= a[tail];
            tail++;
        }
        else if (curent_sum + a[head + 1] <= S)
        {
            head++;
            curent_sum += a[head];
        }

        else if (curent_sum + a[head + 1] > S)
        {
            curent_sum -= a[tail];
            tail++;
        }
        if (curent_sum == S)
        {
            T = 1;
            break;
        }
    }
    if (S == 0)
        T = 1;
    if (T)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}