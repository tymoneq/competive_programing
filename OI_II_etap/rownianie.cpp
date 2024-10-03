#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
set<int> A;

int fint(char code, int indx, map<char, vector<int>> &M_l)
{
    int l = 0, r = M_l[code].size() - 1, mid, ans = 0;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (M_l[code][mid] <= indx)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    return indx - M_l[code][ans];
}

void calc(int val, char code, int pos, map<char, vector<int>> &M_l, map<char, vector<int>> &M_r,
          vector<int> &l_rownanie, vector<int> &r_rownanie)
{
    for (int el : M_l[code])
    {
        if (l_rownanie[el + pos] == 1)
            A.insert(val);
        l_rownanie[el + pos] = val;
    }
    for (int el : M_r[code])
    {
        if (r_rownanie[el + pos] == 1)
            A.insert(val);
        r_rownanie[el + pos] = val;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;

    while (x--)

    {
        int k, l, r, cur = 0, inxd = 0;
        string lewy, prawy;
        A.clear();
        map<char, vector<int>> M_l, M_r;
        cin >> k;
        vector<int> length(k), l_rownanie, r_rownanie;
        vector<char> l_symbole, r_symbole;
        for (int &a : length)
            cin >> a;
        cin >> l >> lewy >> r >> prawy;

        for (int i = 0; i < l; i++)
        {
            if (lewy[i] == '0' || lewy[i] == '1')
            {
                l_rownanie.push_back(1);
                l_symbole.push_back('1');
            }
            else
            {
                cur = max(cur, i);
                int j = length[lewy[i] - 'a'];
                M_l[lewy[i]].push_back(cur);
                cur += j;
                while (j--)
                {
                    l_rownanie.push_back(0);
                    l_symbole.push_back(lewy[i]);
                }
            }
        }
        cur = 0;
        for (int i = 0; i < r; i++)
        {
            if (prawy[i] == '0' || prawy[i] == '1')
            {
                r_rownanie.push_back(1);
                r_symbole.push_back('1');
            }
            else
            {
                cur = max(cur, i);
                int j = length[prawy[i] - 'a'];
                M_r[prawy[i]].push_back(cur);
                cur += j;
                while (j--)
                {
                    r_rownanie.push_back(0);
                    r_symbole.push_back(prawy[i]);
                }
            }
        }

        for (int i = 0; i < l_rownanie.size(); i++)
        {
            if (l_rownanie[i] != r_rownanie[i])
            {
                if (l_rownanie[i] == 1 && r_rownanie[i] != 0)
                    A.insert(r_rownanie[i]);
                else if (r_rownanie[i] == 1 && l_rownanie[i] != 0)
                    A.insert(l_rownanie[i]);

                else if (r_rownanie[i] == 0)
                {
                    int pos = fint(r_symbole[i], i, M_r);
                    calc(l_rownanie[i], r_symbole[i], pos, M_l, M_r, l_rownanie, r_rownanie);
                }
                else if (l_rownanie[i] == 0)
                {
                    int pos = fint(l_symbole[i], i, M_l);
                    calc(r_rownanie[i], l_symbole[i], pos, M_l, M_r, l_rownanie, r_rownanie);
                }
            }
            else if (l_rownanie[i] == 0 && r_rownanie[i] == 0)
            {
                inxd--;
                int pos = fint(l_symbole[i], i, M_l);
                calc(inxd, l_symbole[i], pos, M_l, M_r, l_rownanie, r_rownanie);
                pos = fint(r_symbole[i], i, M_r);
                calc(inxd, r_symbole[i], pos, M_l, M_r, l_rownanie, r_rownanie);
            }
        }

        inxd *= -1;
        inxd -= A.size();
        vector<int> ans = {1};
        while (inxd--)
        {
            for (int i = 0; i < ans.size() - 1; i++)
            {
                ans[i] *= 2;
                if (ans[i] >= 10)
                {
                    ans[i + 1] += 1;
                    ans[i] -= 10;
                }
            }
            ans[ans.size() - 1] *= 2;
            if (ans[ans.size() - 1] >= 10)
            {
                ans.push_back(1);
                ans[ans.size() - 2] -= 10;
            }
        }

        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i];
        cout << "\n";
    }

    return 0;
}