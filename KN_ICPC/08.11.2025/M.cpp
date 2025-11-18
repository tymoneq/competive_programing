#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;
        string s;
        cin >> s;

        int ans = 0;
        for (int i = 0; i < N; i++)
            if (s[i] == '1')
                ans++;

        bool fire = false;
        int mx = 0;
        for (int i = 0; i < N; i++)
        {
            if (s[i] == '0')
                continue;

            int tmp = 0;
            if (i - 1 >= 0 && s[i - 1] == '1')
                tmp++;

            if (i + 1 < N && s[i + 1] == '1')
                tmp++;

            mx = max(mx, tmp);
        }

        ans -= mx;

        cout << ans << "\n";
    }

    return 0;
}