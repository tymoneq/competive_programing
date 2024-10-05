#include <bits/stdc++.h>

using namespace std;
map<pair<char, int>, pair<char, int>> R; // vertex repreezentant
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
                l_pos.push_back(100);
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
        for (int i = 0; i < l_rownanie.size(); i++)
        {
            if (r_rownanie[i] >= 0 && l_rownanie[i] >= 0 && l_rownanie[i] != r_rownanie[i])
            {
                T = 0;
                break;
            }
            else if (l_rownanie[i] >= 0 && r_rownanie[i] < 0 && R.find({r_symbole[i], r_pos[i]}) == R.end())
                R[{r_symbole[i], r_pos[i]}] = {l_symbole[i], l_rownanie[i]};

            else if (l_rownanie[i] < 0 && r_rownanie[i] >= 0 && R.find({l_symbole[i], l_pos[i]}) == R.end())
                R[{l_symbole[i], l_pos[i]}] = {r_symbole[i], r_rownanie[i]};

            else if (l_rownanie[i] >= 0 && r_rownanie[i] < 0 && R.find({r_symbole[i], r_pos[i]}) != R.end())
            {
                auto v = fint(R[{r_symbole[i], r_pos[i]}]);
                if (v.second != l_rownanie[i] && (v.first == '0' || v.first == '1'))
                {
                    T = 0;
                    break;
                }
                R[R[{r_symbole[i], r_pos[i]}]] = {l_symbole[i], l_rownanie[i]};
            }

            else if (l_rownanie[i] < 0 && r_rownanie[i] >= 0 && R.find({l_symbole[i], l_pos[i]}) != R.end())
            {
                auto v = fint(R[{l_symbole[i], l_pos[i]}]);
                if (v.second != r_rownanie[i] && (v.first == '0' || v.first == '1'))
                {
                    T = 0;
                    break;
                }
                R[R[{l_symbole[i], l_pos[i]}]] = {r_symbole[i], r_rownanie[i]};
            }
            else if (R.find({l_symbole[i], l_pos[i]}) != R.end())
            {
                auto v1 = fint(R[{l_symbole[i], l_pos[i]}]);
                if (R.find({r_symbole[i], r_pos[i]}) != R.end())
                {
                    auto v2 = fint(R[{r_symbole[i], r_pos[i]}]);
                    if ((v1.first == '1' && v2.first == '0') || (v1.first == '0' && v2.first == '1'))
                    {
                        T = 0;
                        break;
                    }
                    else if (v1.first == '0' || v1.first == '1')
                        R[v2] = v1;
                    else
                        R[v1] = v2;
                }
                else
                    R[{r_symbole[i], r_pos[i]}] = v1;
            }
            else if (R.find({r_symbole[i], r_pos[i]}) != R.end())
            {
                auto v1 = fint(R[{r_symbole[i], r_pos[i]}]);
                if (R.find({l_symbole[i], l_pos[i]}) != R.end())
                {
                    auto v2 = fint(R[{r_symbole[i], r_pos[i]}]);
                    if ((v1.first == '1' && v2.first == '0') || (v1.first == '0' && v2.first == '1'))
                    {
                        T = 0;
                        break;
                    }
                    else if (v1.first == '0' || v1.first == '1')
                        R[v2] = v1;
                    else
                        R[v1] = v2;
                }
                else
                    R[{l_symbole[i], l_pos[i]}] = v1;
            }
            else
            {
                R[{r_symbole[i], r_pos[i]}] = {r_symbole[i], r_pos[i]};
                R[{l_symbole[i], l_pos[i]}] = {r_symbole[i], r_pos[i]};
            }
        }

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
        if (T)
        {
            for (int i = ans.size() - 1; i >= 0; i--)
                cout << ans[i];
            cout << "\n";
        }
        else
            cout << 0 << "\n";
    }

    return 0;
}