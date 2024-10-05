#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;

    cin >> x;
    while (x--)
    {
        int k, sajz, indx = 0;
        string s;
        cin >> k;
        vector<int> length(k), l_rownanie, r_rownanie, r_pos, l_pos;
        vector<char> l_symbole, r_symbole;
        map<pair<char, int>, int> M; // code,  position, value to change
        set<pair<int, int>> S;       // which value needs to be updated
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
                    l_rownanie.push_back(10);
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
                    r_rownanie.push_back(10);
                }
        }
        bool T = 1;
        for (int i = 0; i < l_rownanie.size(); i++)
        {
            if ((l_rownanie[i] == 0 || l_rownanie[i] == 1) && r_rownanie[i] == 10)
            {
                if (M.find({r_symbole[i], r_pos[i]}) != M.end())
                {
                    if (M[{r_symbole[i], r_pos[i]}] < 0)
                    {
                        S.insert({M[{r_symbole[i], r_pos[i]}], l_rownanie[i]});
                        M[{r_symbole[i], r_pos[i]}] = l_rownanie[i];
                    }
                    else if (M[{r_symbole[i], r_pos[i]}] != l_rownanie[i])
                    {
                        T = 0;
                        break;
                    }
                }
                else
                    M[{r_symbole[i], r_pos[i]}] = l_rownanie[i];
                r_rownanie[i] = l_rownanie[i];
            }

            else if ((r_rownanie[i] == 0 || r_rownanie[i] == 1) && l_rownanie[i] == 10)
            {
                if (M.find({l_symbole[i], l_pos[i]}) != M.end())
                {
                    if (M[{l_symbole[i], l_pos[i]}] < 0)
                    {
                        S.insert({M[{l_symbole[i], l_pos[i]}], r_rownanie[i]});
                        M[{l_symbole[i], l_pos[i]}] = r_rownanie[i];
                    }
                    else if (M[{l_symbole[i], l_pos[i]}] != r_rownanie[i])
                    {
                        T = 0;
                        break;
                    }
                }
                else
                    M[{l_symbole[i], l_pos[i]}] = r_rownanie[i];
                l_rownanie[i] = r_rownanie[i];
            }

            else if (r_rownanie[i] == 10 && l_rownanie[i] == 10)
            {
                if (M.find({l_symbole[i], l_pos[i]}) != M.end())
                {
                    if (M.find({r_symbole[i], r_pos[i]}) != M.end())
                    {
                        if (M[{l_symbole[i], l_pos[i]}] >= 0 && M[{r_symbole[i], r_pos[i]}] >= 0 && M[{l_symbole[i], l_pos[i]}] != M[{r_symbole[i], r_pos[i]}])
                        {
                            T = 0;
                            break;
                        }
                        if (M[{l_symbole[i], l_pos[i]}] >= 0 && M[{r_symbole[i], r_pos[i]}] < 0)
                        {
                            S.insert({M[{r_symbole[i], r_pos[i]}], M[{l_symbole[i], l_pos[i]}]});
                            M[{r_symbole[i], r_pos[i]}] = M[{l_symbole[i], l_pos[i]}];
                            l_rownanie[i] = M[{l_symbole[i], l_pos[i]}];
                            r_rownanie[i] = l_rownanie[i];
                        }
                        else if (M[{l_symbole[i], l_pos[i]}] < 0 && M[{r_symbole[i], r_pos[i]}] >= 0)
                        {
                            S.insert({M[{l_symbole[i], l_pos[i]}], M[{r_symbole[i], r_pos[i]}]});
                            M[{l_symbole[i], l_pos[i]}] = M[{r_symbole[i], r_pos[i]}];
                            l_rownanie[i] = M[{l_symbole[i], l_pos[i]}];
                            r_rownanie[i] = l_rownanie[i];
                        }

                        else if (M[{l_symbole[i], l_pos[i]}] < 0 && M[{r_symbole[i], r_pos[i]}] < 0)
                        {
                            S.insert({M[{r_symbole[i], r_pos[i]}], M[{l_symbole[i], l_pos[i]}]});
                            M[{r_symbole[i], r_pos[i]}] = M[{l_symbole[i], l_pos[i]}];
                            l_rownanie[i] = M[{l_symbole[i], l_pos[i]}];
                            r_rownanie[i] = l_rownanie[i];
                        }
                    }
                    else
                    {
                        M[{r_symbole[i], r_pos[i]}] = M[{l_symbole[i], l_pos[i]}];
                        l_rownanie[i] = M[{l_symbole[i], l_pos[i]}];
                        r_rownanie[i] = l_rownanie[i];
                    }
                }
                else
                {
                    if (M.find({r_symbole[i], r_pos[i]}) != M.end())
                    {
                        M[{l_symbole[i], l_pos[i]}] = M[{r_symbole[i], r_pos[i]}];
                        l_rownanie[i] = M[{l_symbole[i], l_pos[i]}];
                        r_rownanie[i] = l_rownanie[i];
                    }
                    else
                    {
                        indx--;
                        M[{l_symbole[i], l_pos[i]}] = indx;
                        M[{r_symbole[i], r_pos[i]}] = indx;
                        l_rownanie[i] = indx;
                        r_rownanie[i] = l_rownanie[i];
                    }
                }
            }
            if ((l_rownanie[i] == 0 && r_rownanie[i] == 1) || (l_rownanie[i] == 1 && r_rownanie[i] == 0))
            {
                T = 0;
                break;
            }
            if ((l_rownanie[i] == 0 || l_rownanie[i] == 1) && r_rownanie[i] < 0)
                S.insert({r_rownanie[i], l_rownanie[i]});
            if ((r_rownanie[i] == 0 || r_rownanie[i] == 1) && l_rownanie[i] < 0)
                S.insert({l_rownanie[i], r_rownanie[i]});
        }

        if (T)
        {
            for (auto it = S.begin(); it != S.end(); it++)
            {
                for (int i = 0; i < l_rownanie.size(); i++)
                {
                    if (l_rownanie[i] == it->first)
                    {
                        if (l_rownanie[i] >= 0 && it->second != l_rownanie[i] && it->second >= 0)
                        {
                            T = 0;
                            break;
                        }
                        if (l_rownanie[i] >= 0 && it->second < 0)
                        {
                            S.insert({it->second, l_rownanie[i]});
                            break;
                        }

                        if (r_rownanie[i] >= 0 && it->second != r_rownanie[i] && it->second >= 0)
                        {
                            T = 0;
                            break;
                        }
                        if (r_rownanie[i] >= 0 && it->second < 0)
                        {
                            S.insert({it->second, r_rownanie[i]});
                            break;
                        }

                        l_rownanie[i] = it->second;
                        r_rownanie[i] = it->second;
                    }
                    else if (r_rownanie[i] == it->first)
                    {
                        if (l_rownanie[i] >= 0 && it->second != l_rownanie[i] && it->second >= 0)
                        {
                            T = 0;
                            break;
                        }
                        if (l_rownanie[i] >= 0 && it->second < 0)
                        {
                            S.insert({it->second, l_rownanie[i]});
                            break;
                        }

                        if (r_rownanie[i] >= 0 && it->second != r_rownanie[i] && it->second >= 0)
                        {
                            T = 0;
                            break;
                        }
                        if (r_rownanie[i] >= 0 && it->second < 0)
                        {
                            S.insert({it->second, r_rownanie[i]});
                            break;
                        }

                        l_rownanie[i] = it->second;
                        r_rownanie[i] = it->second;
                    }
                }
            }

            if (!T)
                cout << 0 << "\n";
            else
            {
                set<int> ss;
                for (int i = 0; i < l_rownanie.size(); i++)
                    if (l_rownanie[i] < 0)
                        ss.insert(l_rownanie[i]);

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
        }
        else
            cout << 0 << "\n";
    }

    return 0;
}