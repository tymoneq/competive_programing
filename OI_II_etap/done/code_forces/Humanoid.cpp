#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ans;

void solve(int green, int blue, ll h, int indx, vector<ll> &A, int current_res)
{

    for (indx; indx < A.size(); indx++)
    {
        if (A[indx] < h)
        {
            h += A[indx] / 2;
            current_res++;
        }
        else
            break;
    }
    ans = max(ans, current_res);
    if (A[indx] >= h)
    {
        if (green > 0)
            solve(green - 1, blue, h * 2, indx, A, current_res);
        if (blue > 0)
            solve(green, 0, h * 3, indx, A, current_res);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        int n;
        ll h;
        cin >> n >> h;
        vector<ll> A(n);
        for (ll &a : A)
            cin >> a;

        sort(A.begin(), A.end());

        int indx = 0;
        for (indx; indx < n; indx++)
        {
            if (A[indx] < h)
            {
                h += A[indx] / 2;
                ans++;
            }
            else
                break;
        }

        solve(2, 1, h, indx, A, ans);

        cout << ans << "\n";
    }

    return 0;
}