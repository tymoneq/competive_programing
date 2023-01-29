#include <bits/stdc++.h>

using namespace std;
char Letters[130];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    char z1, z2;
    string s1, s2;
    cin >> t;
    vector<bool> Process(125);
    int res = 0;
    for (int T = 0; T < t; T++)
    {
        for (int i = 0; i < 125; i++)
            Letters[i] = i, Process[i] = 0;
        cin >> s1 >> s2;
        if (s1.size() != s2.size())
        {
            cout << -1 << "\n";
            continue;
        }
        set<char> Use;
        bool wrong = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (Letters[s1[i]] != s1[i] && Letters[s1[i]] != s2[i])
            {
                cout << -1 << "\n";
                wrong = 1;
                break;
            }
            else
                Letters[s1[i]] = s2[i];
        }
        if (wrong)
            continue;
        res = 0;
        for (int i = 0; i < s1.size(); i++)
            if (!Process[s1[i]])
            {
                if (Letters[s1[i]] == s1[i])
                    Process[s1[i]] = 1;
                else
                {
                    Use.clear();
                    Use.insert(s1[i]);
                    res++;
                    Process[s1[i]] = 1;
                    int ind = Letters[s1[i]];
                    while (Letters[ind] != ind && !Use.count(ind))
                    {
                        res++;
                        Use.insert(ind);
                        Process[ind] = 1;
                        ind = Letters[ind];
                    }
                    if(Use.size()!=1)
                        res++;
                }
            }

        cout << res << "\n";
    }
    return 0;
}