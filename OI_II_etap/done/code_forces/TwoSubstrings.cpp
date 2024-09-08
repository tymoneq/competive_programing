#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int k = 0;
    while (k < s.size() - 1)
    {
        if (s[k] == 'A' && s[k + 1] == 'B')
        {
            k += 2;
            break;
        }
        ++k;
    }
    bool Ans = 0;

    while (k < s.size() - 1)
    {
        if (s[k] == 'B' && s[k + 1] == 'A')
        {
            Ans = 1;
            break;
        }
        ++k;
    }

    k = 0;
    while (k < s.size() - 1)
    {
        if (s[k] == 'B' && s[k + 1] == 'A')
        {
            k += 2;
            break;
        }
        ++k;
    }
    while (k < s.size() - 1)
    {
        if (s[k] == 'A' && s[k + 1] == 'B')
        {
            Ans = 1;
            break;
        }
        ++k;
    }
    cout << (Ans ? "YES\n" : "NO\n");
    return 0;
}