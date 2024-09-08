#include <bits/stdc++.h>

using namespace std;

vector<int> Nums_locations[10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> nums;
    bool F;
    string s;
    int n, indx = -1;
    for (int i = 1; i < 1000; i++)
        if (i % 8 == 0)
            nums.push_back(i);

    cin >> s;

    for (int i = s.size() - 1; i >= 0; i--)
        Nums_locations[s[i] - '0'].push_back(s.size() - i - 1);

    if (Nums_locations[0].size() == 0)
        for (int v : nums)
        {
            indx = -1;
            F = 1;
            vector<int> Res;
            while (v > 0)
            {
                n = v % 10;
                v /= 10;
                Res.push_back(n);
                if (Nums_locations[n].size() == 0)
                {
                    F = 0;
                    break;
                }

                auto it = upper_bound(Nums_locations[n].begin(), Nums_locations[n].end(), indx);

                if (it == Nums_locations[n].end())
                {
                    F = 0;
                    break;
                }

                indx = *it;
            }
            if (F)
            {
                cout << "YES\n";
                for (int i = Res.size() - 1; i >= 0; i--)
                    cout << Res[i];
                cout << "\n";
                return 0;
            }
        }
    else if (Nums_locations[0].size() > 0)
    {
        cout << "YES\n"
             << 0 << "\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}