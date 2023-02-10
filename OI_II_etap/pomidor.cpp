#include <bits/stdc++.h>

using namespace std;
set<string> S[27];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        S[s[0] - 'a'].insert(s);
    }
    cin >> q;
    bool cor = 1;
    for (int i = 0; i < q; i++)
    {
        cin >> s;
        cor = 1;
        auto it = lower_bound(S[s[0] - 'a'].begin(), S[s[0] - 'a'].end(), s);
        if (it == S[s[0]].end())
        {
            cout << "Pomidor\n";
            continue;
        }
        string ss = *it;
        if (ss.size() < s.size())
            cor = 0;
        if (cor)
            for (int j = 0; j < s.size(); j++)
                if (s[j] != ss[j])
                {
                    cor = 0;
                    break;
                }
        if (!cor)
            cout << "Pomidor\n";
        else
            cout << ss << "\n";
    }
    return 0;
}