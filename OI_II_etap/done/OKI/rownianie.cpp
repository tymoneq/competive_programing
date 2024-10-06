#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<pair<char, int>, pair<char, int>> R; // vertex repreezentant

inline pair<char, int> fint(pair<char, int> a) { return R[a] == a ? a : R[a] = fint(R[a]); }

inline void readData(vector<char> &symbole, vector<int> &pos, int sajz, vector<int> &length)
{
    char s;
    for (int i = 0; i < sajz; i++)
    {
        cin >> s;
        if (s < 'a')
        {
            symbole.push_back(s);
            pos.push_back(s - '0');
        }
        else
            for (int j = 0; j < length[s - 'a']; j++)
            {
                symbole.push_back(s);
                pos.push_back(j);
            }
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
        readData(l_symbole, l_pos, sajz, length);
        cin >> sajz;
        readData(r_symbole, r_pos, sajz, length);
        if (l_symbole.size() != r_symbole.size())
        {
            cout << "0\n";
            continue;
        }
        for (int i = 0; i < r_symbole.size(); i++)
        {
            if (R.find({r_symbole[i], r_pos[i]}) == R.end())
            {
                R[{r_symbole[i], r_pos[i]}] = {r_symbole[i], r_pos[i]};
                Sajz[{r_symbole[i], r_pos[i]}] = 1;
            }
            if (R.find({l_symbole[i], l_pos[i]}) == R.end())
            {
                R[{l_symbole[i], l_pos[i]}] = {l_symbole[i], l_pos[i]};
                Sajz[{l_symbole[i], l_pos[i]}] = 1;
            }
        }
        for (int i = 0; i < r_symbole.size(); i++)
        {
            auto v1 = fint({l_symbole[i], l_pos[i]});
            auto v2 = fint({r_symbole[i], r_pos[i]});
            if (Sajz[v1] < Sajz[v2])
                swap(v1, v2);
            Sajz[v1] += Sajz[v2];
            Sajz[v2] = 0;
            R[v2] = v1;
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
                if (el.second == el.first)
                    power++;

            vector<int> ans = {1};
            while (power--)
            {
                int carry = 0;
                for (int i = 0; i < ans.size(); i++)
                {
                    int temp = ans[i] * 2 + carry;
                    ans[i] = temp % 10;
                    carry = temp / 10;
                }
                if (carry)
                    ans.push_back(carry);
            }
            for (int i = ans.size() - 1; i >= 0; i--)
                cout << ans[i];
            cout << "\n";
        }
    }

    return 0;
}