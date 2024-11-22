#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;

    bool t = 1;

    if (n % 2 == 0)
        t = 0;
    if (t)
        for (int i = 1; i <= n; i++)
        {
            if (i <= ((n + 1) / 2 - 1) && s[i - 1] != '1')
                t = 0;
            if (i == ((n + 1) / 2) && s[i - 1] != '/')
                t = 0;
            if (i >= ((n + 1) / 2 + 1) && s[i - 1] != '2')
                t = 0;
        }

    cout << (t ? "Yes" : "No") << "\n";
    return 0;
}