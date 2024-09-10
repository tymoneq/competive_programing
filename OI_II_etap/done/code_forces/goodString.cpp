#include <bits/stdc++.h>

using namespace std;

constexpr int N = 10;

vector<int> Tab[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, mx, sajz, indxL, indxR;
    string s;
    cin >> t;
    while (t--)
    {
        mx = 2;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
            Tab[s[i] - '0'].push_back(i);

        for (int i = 0; i < N; i++)
        {
            mx = max(mx, (int)Tab[i].size());
            if (Tab[i].size() > 1)
                for (int j = 0; j < N; j++)
                    if (j != i && Tab[j].size() > 0)
                    {
                        indxL = Tab[i][0];
                        indxR = Tab[j][Tab[j].size() - 1];
                        sajz = 2;
                        while (indxL <= indxR)
                        {
                            auto it = lower_bound(Tab[j].begin(), Tab[j].end(), indxL);
                            if (it == Tab[j].end())
                                break;
                            auto itr = lower_bound(Tab[i].begin(), Tab[i].end(), *it);
                            if (itr == Tab[i].end())
                                break;
                            indxL = *itr;
                            if (indxL <= indxR)
                                sajz += 2;
                        }
                        mx = max(sajz, mx);
                    }
        }

        cout << s.size() - mx << "\n";

        for (int i = 0; i < N; i++)
            Tab[i].clear();
    }

    return 0;
}