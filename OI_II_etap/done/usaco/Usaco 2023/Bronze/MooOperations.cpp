#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    string s;
    cin >> q;
    for (int Q = 0; Q < q; Q++)
    {
        int count = 0, res = numeric_limits<int>::max();
        cin >> s;
        if (s.size() < 3)
            cout << -1 << "\n";
        else if (s.size() == 3)
        {
            if (s[0] == 'O')
                count++;
            if (s[1] == 'M')
            {
                cout << -1 << "\n";
                continue;
            }
            if (s[2] == 'M')
                count++;
            cout << count << "\n";
        }
        else
        {
            for (int i = 0; i < s.size() - 3; i++)
            {
                count = 0;
                if (s[i] == 'O')
                    count++;
                if (s[i + 1] == 'M')
                    continue;
                if (s[i + 2] == 'M')
                    count++;
                count += i;
                count += s.size() - (i + 3);
                res = min(res, count);
            }
            count = 0;
            if (s[s.size() - 2] == 'O')
            {
                if (s[s.size() - 1] == 'M')
                    count++;
                if (s[s.size() - 3] == 'O')
                    count++;
                count += s.size() - 3;
                res = min(res, count);
            }
            if (res == numeric_limits<int>::max())
                res = -1;
            cout << res << "\n";
        }
    }
    return 0;
}