#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S, T;
    cin >> S >> T;
    map<char, int> MS, MT;

    for (int i = 1; i < S.size(); i++)
    {
        if (MS.find(S[i]) == MS.end())
        {
            MS[S[i]] = i;
        }
    }

    for (int i = T.size() - 2; i >= 0; i--)
    {
        if (MT.find(T[i]) == MT.end())
            MT[T[i]] = i;
    }
    string s = S;
    s += T;
    for (int i = 0; i < 10; i++)
        s.append("AAA");
    bool t = 0;
    for (auto w : MS)
    {
        if (MT.find(w.first) == MT.end())
            continue;
        else
        {
            string ss = "";
            for (int i = 0; i < w.second; i++)
                ss += (S[i]);

            for (int i = MT[w.first]; i < T.size(); i++)
                ss += (T[i]);

            if (ss.size() < s.size())
                s = ss;
            t = 1;
        }
    }

    if (t)
    {
        cout << s << '\n';
        return 0;
    }

    cout << -1 << '\n';

    return 0;
}