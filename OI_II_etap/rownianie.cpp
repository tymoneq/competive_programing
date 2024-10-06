#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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
        map<pair<char, int>, ll> Sajz;
        char s;
        cin >> k;
        vector<int> length(k), r_pos, l_pos;
        vector<char> l_symbole, r_symbole;

        for (int &a : length)
            cin >> a;

        cin >> sajz;
        for (int i = 0; i < sajz; i++)
        {
            cin >> s;
            if (s < 'a')
            {
                l_symbole.push_back(s);
                l_pos.push_back(s - '0');
            }
            else
                for (int j = 0; j < length[s - 'a']; j++)
                {
                    l_symbole.push_back(s);
                    l_pos.push_back(j);
                }
        }
        cin >> sajz;
        for (int i = 0; i < sajz; i++)
        {
            cin >> s;
            if (s < 'a')
            {
                r_symbole.push_back(s);
                r_pos.push_back(s - '0');
            }
            else
                for (int j = 0; j < length[s - 'a']; j++)
                {
                    r_symbole.push_back(s);
                    r_pos.push_back(j);
                }
        }
        if (l_symbole.size() == r_symbole.size())
        {
            for (int i = 0; i < r_symbole.size(); i++)
            {
                if (R.find({l_symbole[i], l_pos[i]}) == R.end() && R.find({r_symbole[i], r_pos[i]}) == R.end())
                {
                    Sajz[{l_symbole[i], l_pos[i]}] = 2;
                    R[{l_symbole[i], l_pos[i]}] = {l_symbole[i], l_pos[i]};
                    R[{r_symbole[i], r_pos[i]}] = {l_symbole[i], l_pos[i]};
                }
                else if (R.find({l_symbole[i], l_pos[i]}) != R.end() && R.find({r_symbole[i], r_pos[i]}) == R.end())
                {
                    auto v = fint({l_symbole[i], l_pos[i]});
                    Sajz[v]++;
                    R[{r_symbole[i], r_pos[i]}] = v;
                }
                else if (R.find({l_symbole[i], l_pos[i]}) == R.end() && R.find({r_symbole[i], r_pos[i]}) != R.end())
                {
                    auto v = fint({r_symbole[i], r_pos[i]});
                    Sajz[v]++;
                    R[{l_symbole[i], l_pos[i]}] = v;
                }
                else
                {
                    auto v1 = fint({l_symbole[i], l_pos[i]});
                    auto v2 = fint({r_symbole[i], r_pos[i]});
                    if (Sajz[v1] < Sajz[v2])
                        swap(v1, v2);
                    Sajz[v1] += Sajz[v2];
                    Sajz[v2] = 0;
                    R[v2] = v1;
                }
            }
            if (R.find({'1', 1}) != R.end() && R.find({'0', 0}) != R.end() && fint({'1', 1}) == fint({'0', 0}))
                cout << "0\n";

            else
            {
                ll power = 0;
                if (R.find({'1', 1}) != R.end())
                    power--;
                if (R.find({'0', 0}) != R.end())
                    power--;
                for (auto el : R)
                    if (fint(el.first) == el.first)
                        power++;

                vector<int> ans = {1};
                while (power--)
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
            cout << "0\n";
    }

    return 0;
}