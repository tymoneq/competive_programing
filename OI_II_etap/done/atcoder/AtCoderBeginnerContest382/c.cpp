#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    vector<int> Mn(n);
    Mn[0] = A[0];
    for (int i = 1; i < n; i++)
        Mn[i] = min(Mn[i - 1], A[i]);

    while (m--)
    {
        int sushi;
        cin >> sushi;
        int lo = 0, hi = n - 1, mid, ans = -1;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (Mn[mid] <= sushi)
            {
                ans = mid + 1;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}