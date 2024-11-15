#include <bits/stdc++.h>

using namespace std;

vector<int> Ans27 = {1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 13, 12, 12, 1, 13};

inline void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        int num = 1;
        for (int i = 0; i < n; i++)
        {
            cout << num << " ";
            if (i % 2 == 1)
                num++;
        }
    }
    else if (n % 2 == 1 && n >= 27)
    {
        for (int w : Ans27)
            cout << w << " ";

        int num = 14;
        for (int i = 28; i <= n; i++)
        {
            cout << num << " ";
            if (i % 2 == 1)
                num++;
        }
    }
    else
        cout << -1;

    cout << "\n";
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