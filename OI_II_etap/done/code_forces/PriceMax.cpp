#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    ll a, ans, k;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ans = 0;
        vector<ll> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            ans += a / k;
            A[i] = a % k;
        }

        sort(A.begin(), A.end(), greater<ll>());

        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            while (A[i] + A[j] < k && i < j)
                j--;
            if (i == j)
                break;
            ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}