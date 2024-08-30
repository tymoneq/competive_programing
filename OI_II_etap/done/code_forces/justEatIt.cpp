#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAXN = 1e5 + 10;

ll NUM[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> NUM[i];

        ll sum = 0;
        bool T = 0;
        for (int i = 0; i < n; i++)
        {
            sum += NUM[i];
            if (sum <= 0)
            {
                cout << "NO\n";
                T = 1;
                break;
            }
        }
        if (T)
            continue;
        sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += NUM[i];
            if (sum <= 0)
            {
                cout << "NO\n";
                T = 1;
                break;
            }
        }
        if (T != 1)
            cout << "YES\n";
    }

    return 0;
}