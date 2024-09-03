#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, k, a;
    cin >> t;
    set<int> s;
    while (t--)
    {
        cin >> n >> k;
        s.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            s.insert(a);
        }

        if (s.size() > k)
        {
            cout << -1 << "\n";
            continue;
        }

        cout << n * k << "\n";

        for (int i = 0; i < n; i++)
        {
            for (int b : s)
                cout << b << " ";

            for (int j = 0; j < k - s.size(); j++)
                cout << 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}