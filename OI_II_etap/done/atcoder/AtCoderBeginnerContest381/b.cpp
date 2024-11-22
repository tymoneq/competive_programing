#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    bool T = 1;

    if (s.size() % 2 == 1)
        T = 0;

    if (T)
    {
        set<char> used;

        for (int i = 0; i < s.size(); i += 2)
        {
            if (s[i] != s[i + 1])
                T = 0;

            else if (used.count(s[i]))
                T = 0;
            used.insert(s[i]);
        }
    }

    cout << (T ? "Yes" : "No") << '\n';
    return 0;
}