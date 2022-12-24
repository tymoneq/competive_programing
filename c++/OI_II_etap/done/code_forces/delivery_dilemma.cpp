#include <bits/stdc++.h>

using namespace std;

const int MAX_VAL = 2e5 + 10;
pair<int, int> Petya[MAX_VAL];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, res = 0, a, tmp = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        res = 0, tmp = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> Petya[j].first;

        for (int j = 0; j < n; j++)
            cin >> Petya[j].second;

        sort(Petya, Petya + n, greater<pair<int, int>>());
        if (Petya[0].first <= Petya[0].second)
            res = Petya[0].first;
        else
        {
            res = Petya[0].second;
            for (int j = 1; j < n; j++)
            {
                if (res >= Petya[j].first)
                    break;

                if (res + Petya[j].second >= Petya[j].first)
                {
                    res = Petya[j].first;
                    break;
                }
                res += Petya[j].second;
            }
        }
        cout << res << "\n";
    }
    return 0;
}