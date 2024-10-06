#include <bits/stdc++.h>

using namespace std;
map<pair<char, int>, pair<char, int>> R; // vertex repreezentant
map<pair<char, int>, int> Sajz;
inline pair<char, int> fint(pair<char, int> a) { return R[a] == a ? a : fint(R[a]); }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;

    cin >> x;
    while (x--)
    {
        int k, sajz;
        R.clear();
        Sajz.clear();
        string s;
        cin >> k;
        vector<int> length(k), l_rownanie, r_rownanie, r_pos, l_pos;
        vector<char> l_symbole, r_symbole;

        for (int &a : length)
            cin >> a;

        cin >> sajz >> s;
        for (int i = 0; i < sajz; i++)
        {
            if (s[i] < 'a')
            {
                l_symbole.push_back(s[i]);
                l_pos.push_back(s[i] - '0');
                l_rownanie.push_back(s[i] - '0');
            }
            else
                for (int j = 0; j < length[s[i] - 'a']; j++)
                {
                    l_symbole.push_back(s[i]);
                    l_pos.push_back(j);
                    l_rownanie.push_back(-1);
                }
        }
        cin >> sajz >> s;
        for (int i = 0; i < sajz; i++)
        {
            if (s[i] < 'a')
            {
                r_symbole.push_back(s[i]);
                r_pos.push_back(100);
                r_rownanie.push_back(s[i] - '0');
            }
            else
                for (int j = 0; j < length[s[i] - 'a']; j++)
                {
                    r_symbole.push_back(s[i]);
                    r_pos.push_back(j);
                    r_rownanie.push_back(-1);
                }
        }
        bool T = 1;
        R[{'1', 1}] = {'1', 1};
        R[{'0', 0}] = {'0', 0};
        Sajz[{'1', 1}] = 1;
        Sajz[{'0', 0}] = 1;
        if (l_rownanie.size() == r_rownanie.size())
        {
            for (int i = 0; i < l_rownanie.size(); i++)
            {
                
            }
            if (T)
            {
                for (auto el : R)
                    fint(el.second);
                set<pair<char, int>> ss;

                for (auto el : R)
                    if (el.second.first != '1' && el.second.first != '0')
                        ss.insert(el.second);

                vector<int> ans = {1};
                int j = ss.size();
                while (j--)
                {
                    for (int i = 0; i < ans.size() - 1; i++)
                    {
                        ans[i] *= 2;
                        if (ans[i] >= 10)
                        {
                            ans[i] -= 10;
                            ans[i + 1] += 1;
                        }
                    }
                    ans[ans.size() - 1] *= 2;
                    if (ans[ans.size() - 1] >= 10)
                    {
                        ans[ans.size() - 1] -= 10;
                        ans.push_back(1);
                    }
                }

                for (int i = ans.size() - 1; i >= 0; i--)
                    cout << ans[i];
                cout << "\n";
            }
            else
                cout << 0 << "\n";
        }
        else
            cout << "0\n";
    }

    return 0;
}