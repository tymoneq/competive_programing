#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 27, N = 2e5 + 10;

int RES[MAXN], Pref[MAXN][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, m, a, tmp;
    string s;

    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 26; i++)
            RES[i] = 0;

        cin >> n >> m >> s;

        for (auto c : s)
            RES[c - 'a']++;

        for (int i = 0; i < 26; i++)
            for (int j = 0; j < s.size(); j++)
            {
                tmp = 0;
                if (s[j] - 'a' == i)
                    tmp++;
                Pref[i][j + 1] = Pref[i][j] + tmp;
            }

        for (int i = 0; i < m; i++)
        {
            cin >> a;
            for (int j = 0; j < 26; j++)
                RES[j] += Pref[j][a];
        }

        for (int i = 0; i < 26; i++)
            cout << RES[i] << " ";

        cout << "\n";
    }

    return 0;
}