#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {

        cin >> n;
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            if (x % 2 == 0)
                a += 1;
            else
                b += 1;
        }
        if (b % 4 == 2)
            cout << "Bob" << "\n";
        else if (b % 4 == 3)
            cout << "Alice" << "\n";
        else if (b % 4 == 0)
            cout << "Alice" << "\n";
        else if (a % 2 == 1)
            cout << "Alice" << "\n";
        else
            cout << "Bob" << "\n";
    }

    return 0;
}