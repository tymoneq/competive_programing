#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, x, res;
    string s;

    cin >> n >> m;
    vector<int> Sad(n);
    for (int i = 0; i < n; i++)
        cin >> Sad[i];

    sort(Sad.begin(), Sad.end());
    while (m--)
    {
        cin >> s;
        if (s[0] == 'p')
        {
            cin >> x;
            for (int i = 0; i < x; i++)
                Sad[i]++;
            sort(Sad.begin(), Sad.end());
        }
        else
        {
            res = 0;
            cin >> a >> b;

            auto it = lower_bound(Sad.begin(), Sad.end(), a);
            while (it != Sad.end() && *it <= b)
            {
                res += 1;
                ++it;
            }

            cout << res << "\n";
        }
    }

    return 0;
}