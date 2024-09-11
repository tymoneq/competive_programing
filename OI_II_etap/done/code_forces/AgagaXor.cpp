#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;

    ll ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> A(n);
        set<ll> B;
        bool T = 0;
        for (ll &a : A)
        {
            cin >> a;
            B.insert(a);
        }
        ans = A[0];
        for (int i = 1; i < n; i++)
        {
            T = 1;
            for (int j = i; j < n; j++)
                if (A[j] != ans)
                {
                    T = 0;
                    break;
                }

            if (T)
            {
                ans = 0;
                break;
            }
            ans ^= A[i];
        }

        if (ans == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}