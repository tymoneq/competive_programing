#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 10;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        A[a]++;
    }

    sort(A.begin(), A.end(), greater<int>());

    int res = 0;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += A[i];
        res++;
        if (n - s <= s - res)
            break;
    }
    cout << res << "\n";

    return 0;
}