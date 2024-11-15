#include <bits/stdc++.h>

using namespace std;

inline void solve()
{
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    bool T = 1;

    for (int i = 1; i <= n; i++)
    {
        if (A[i] == i)
            continue;
        else if (A[i + 1] == i && A[i] == i + 1)
            swap(A[i + 1], A[i]);

        else
        {
            T = 0;
            break;
        }
    }

    cout << (T ? "YES" : "NO") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}