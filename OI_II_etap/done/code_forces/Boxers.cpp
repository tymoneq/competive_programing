#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, res = 0;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end(), greater<int>());

    int lst = A[0] + 2;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int cur = -1;
        for (int dx = 1; dx >= -1; --dx)
        {
            if (A[i] + dx > 0 && A[i] + dx < lst)
            {
                cur = A[i] + dx;
                break;
            }
        }
        if (cur == -1)
            continue;
        ++ans;
        lst = cur;
    }
    cout << ans << '\n';
}